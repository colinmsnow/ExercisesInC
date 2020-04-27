/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_CHILDREN 100

typedef pthread_mutex_t Mutex;

void perror_exit(char *s)
{
    perror(s);
    exit(-1);
}

void *check_malloc(int size)
{
    void *p = malloc(size);
    if (p == NULL) {
        perror_exit("malloc failed");
    }
    return p;
}

typedef struct {
    int counter;
    int end;
    int *array;
    Mutex* mutex;
} Shared;

Mutex *make_mutex()
{
Mutex *mutex = check_malloc(sizeof(Mutex));
int n = pthread_mutex_init(mutex, NULL);
if (n != 0) perror_exit("make_lock failed");
return mutex;
}

void mutex_lock(Mutex *mutex)
{
int n = pthread_mutex_lock(mutex);
if (n != 0) perror_exit("lock failed");
}

void mutex_unlock(Mutex *mutex)
{
int n = pthread_mutex_unlock(mutex);
if (n != 0) perror_exit("unlock failed");
}

Shared *make_shared(int end)
{
    int i;
    Shared *shared = check_malloc(sizeof(Shared));

    shared->counter = 0;
    shared->end = end;

    shared->array = check_malloc(shared->end * sizeof(int));
    for (i=0; i<shared->end; i++) {
        shared->array[i] = 0;
    }
    shared->mutex = make_mutex();
    return shared;
}

pthread_t make_thread(void *(*entry)(void *), Shared *shared)
{
    int ret;
    pthread_t thread;

    ret = pthread_create(&thread, NULL, entry, (void *) shared);
    if (ret != 0) {
        perror_exit("pthread_create failed");
    }
    return thread;
}

void join_thread(pthread_t thread)
{
    int ret = pthread_join(thread, NULL);
    if (ret == -1) {
        perror_exit("pthread_join failed");
    }
}

void child_code(Shared *shared)
{
    mutex_lock(shared->mutex);
    // printf("Starting child at counter %d\n", shared->counter);

    while (1) {
        if (shared->counter >= shared->end) {
            mutex_unlock(shared->mutex);
            return;
        }
        shared->array[shared->counter]++;
        shared->counter++;

        // if (shared->counter % 10000 == 0) {
        //     printf("%d\n", shared->counter);
        // }
    }
    mutex_unlock(shared->mutex);
}

void *entry(void *arg)
{
    Shared *shared = (Shared *) arg;
    child_code(shared);
    // printf("Child done.\n");
    pthread_exit(NULL);
}

void check_array(Shared *shared)
{
    int i, errors=0;

    // printf("Checking...\n");

    for (i=0; i<shared->end; i++) {
        if (shared->array[i] != 1) errors++;
    }
    // printf("%d errors.\n", errors);
}

int main()
{
    int i;
    pthread_t child[NUM_CHILDREN];

    Shared *shared = make_shared(1000000);

    for (i=0; i<NUM_CHILDREN; i++) {
        child[i] = make_thread(entry, shared);
    }

    for (i=0; i<NUM_CHILDREN; i++) {
        join_thread(child[i]);
    }

    check_array(shared);
    return 0;
}
