# Overview

## The Assignment

The producer generates items and puts items onto the table. The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer.  Mutual exclusion should be considered. We use threads in the producer program and consumer program. Shared memory is used for the “table”.

## Resources
I used WSL to compile and run the program I had written in VS Code with C++ via "code ." command.

## Compile
To compile the program:

```
g++ producer.cpp -o producer
g++ consumer.cpp -o consumer
./producer && ./consumer
```
## Example Output
```code
Producer data: 10
Producer data: 11
Consumer is consuming data: 10
Consumer is consuming data: 11
```
