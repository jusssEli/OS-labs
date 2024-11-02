#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <sys/mman.h>
#include <cstring>
#include <semaphore.h>

struct ZaData {
    int table [2];
};

int main() {
    const char* sHm = "/shared memory";
    const char* semaph = "/semaphore1";
    int shm_fd = shm_open(sHm, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    ftruncate(shm_fd, sizeof(ZaData));
    ZaData *sharedData = (ZaData*)mmap(NULL, sizeof(ZaData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (sharedData == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }


    sem_t *sem1 = sem_open(semaph, 0);
    if (sem1 == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 2; ++i) {
        // Wait for the semaphore
        if (sem_wait(sem1) == -1) {
            perror("sem_wait");
            exit(EXIT_FAILURE);
        }

        // Consume data
        std::cout << "Consumer is consuming data: " << sharedData->table[i] << std::endl;
        sleep(1); // Simulation -- busy wait

        // Release the semaphore
        if (sem_post(sem1) == -1) {
            perror("sem_post");
            exit(EXIT_FAILURE);
        }
    }
    // Close the semaphore
    if (sem_close(sem1) == -1) {
        perror("sem_close");
        exit(EXIT_FAILURE);
    }

    // Cleanup shared memory
    munmap(sharedData, sizeof(ZaData));
    close(shm_fd);
    return 0;
}
