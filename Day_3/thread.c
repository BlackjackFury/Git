#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;

int count = 1;


void* counter(void *num)
{
   

    long i = (long) num;
    pthread_mutex_lock(&mut);

    count++;
    pthread_mutex_unlock(&mut);
    printf("Count %d\n",count);
    sleep(count);
    printf("Thread %ld finished task\n", i);
    pthread_exit(NULL);
}

int main (int argc, char* argv[])
{
    long i;
    int rc;
    pthread_t threads[NUM_THREADS];
        
    for (i =0; i < NUM_THREADS; i++)
    {
    rc = pthread_create(&threads[i], NULL, counter, (void *)i);
    printf("Thread created %ld\n", i);
       if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
                 }
    }

    for (i = 0; i < NUM_THREADS; i ++)
    {
       pthread_join(threads[i], NULL);
        printf("Thread stopped %ld\n", i);
    }
}
