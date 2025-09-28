

// Included libraries
#include <stdio.h> // 
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

// Define the number of threads in the pool
#define THREAD_POOL_SIZE 4

// Task function type for type checking
typedef void (*TaskFunction)(void*);

// Node for the task queue linked list
typedef struct TaskNode {
    TaskFunction function;
    void* arg;
    struct TaskNode* next;
} TaskNode;

// Thread pool structure
typedef struct ThreadPool {
    pthread_t threads[THREAD_POOL_SIZE];
    TaskNode* task_queue_head;
    TaskNode* task_queue_tail;
    pthread_mutex_t queue_mutex;
    pthread_cond_t queue_cond;
    int stop;
} ThreadPool;

// Worker thread function
// TODOS: Implement the worker thread function :) <3
// void* worker_thread(void* arg);
