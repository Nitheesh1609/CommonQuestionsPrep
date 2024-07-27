//
// Created by Nitheesh Prakash on 7/27/24.
//
//Implement a Circular Buffer:
//
//Interview Question:
//
//Implement a Circular Buffer (Ring Buffer) in C with the following functionalities:
//
//Initialization: Initialize the buffer with a fixed size.
//Write: Add an element to the buffer. If the buffer is full, overwrite the oldest data.
//Read: Remove and return the oldest element in the buffer. If the buffer is empty, return an indication that the buffer is empty.
//isEmpty: Check if the buffer is empty.
//isFull: Check if the buffer is full.

#include <iostream>

typedef struct {
    int capacity;
    int size;
    int *arr;
    int front;
    int back;
}CircularBuffer;

 void initialize_Buffer(CircularBuffer *CB, int N){
    CB->capacity = N;
    CB->arr = (int *) malloc(sizeof (int)*N);
    CB->front=0;
    CB->back=0;
    CB->size=0;
}

void writeBuffer(CircularBuffer *CB, int value){
     CB->arr[CB->back]=value;
     CB->size++;
     CB->back = (CB->back + 1) % CB->capacity;
 }

 int readBuffer(CircularBuffer *CB, int *value){
     if(CB->back == CB->front)
         return -1;

     *value = CB->arr[CB->front];
     CB->size--;
     CB->front = (CB->front + 1) % CB->capacity;
     return 0;
 }
bool isEmpty(CircularBuffer *CB){
    return CB->size == 0;
}

bool isFull(CircularBuffer *CB){
    return CB->size == CB->capacity;
}

int readBuffer(CircularBuffer *CB){
    if(isEmpty(CB))
        return -1;

    int value = CB->arr[CB->front];
    CB->size--;
    CB->front = (CB->front + 1) % CB->capacity;
    return value;
}




int main() {
    CircularBuffer buffer;
    initialize_Buffer(&buffer, 3);

    printf("Buffer is empty: %d\n", isEmpty(&buffer));  // 1 (true)

    writeBuffer(&buffer, 1);
    writeBuffer(&buffer, 2);
    writeBuffer(&buffer, 3);

    printf("Buffer is full: %d\n", isFull(&buffer));  // 1 (true)

    printf("Read: %d\n", readBuffer(&buffer));  // 1
    printf("Read: %d\n", readBuffer(&buffer));  // 2

    writeBuffer(&buffer, 4);
    writeBuffer(&buffer, 5);

    printf("Read: %d\n", readBuffer(&buffer));  // 3
    printf("Read: %d\n", readBuffer(&buffer));  // 4

    printf("Buffer is empty: %d\n", isEmpty(&buffer));  // 0 (false)
    printf("Read: %d\n", readBuffer(&buffer));  // 5
    printf("Buffer is empty: %d\n", isEmpty(&buffer));  // 1 (true)
    printf("Read: %d\n", readBuffer(&buffer));  // -1 (Buffer is empty)

    return 0;
}
