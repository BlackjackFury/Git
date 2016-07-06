#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5
#define NUM_RUNS 3


pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond;
int count = 1;
int t_fin = 0;

void* counter(void *num)
{
   	int t;
	
    long i = (long) num;
    
    	pthread_mutex_lock(&mut);
    	count++;
    	pthread_mutex_unlock(&mut);
    
    //		printf("Count %d\n",count);
   		sleep(count);
    	printf("Thread %ld finished task\n", i);
		
		t_fin ++;
	if (t_fin != NUM_THREADS)
		{		
		printf("Thread %ld now waiting\n", i);
		
		pthread_mutex_lock(&mut2);		
				
		pthread_cond_wait(&cond, &mut2);
		
		pthread_mutex_unlock(&mut2);
		printf("Thread %ld finished waiting\n", i);
		}
		
	else { 
		printf("=======================\n");
		pthread_cond_broadcast(&cond);
		}	
	sleep(1);
    pthread_exit(NULL);
}

int main (int argc, char* argv[])
{
    long i;
    int rc;
	pthread_cond_init(&cond, NULL);
    pthread_t threads[NUM_THREADS];
        
    for (i = 0; i < NUM_THREADS; i++)
    {
    rc = pthread_create(&threads[i], NULL, counter, (void *)i);
    printf("Thread created %ld\n", i);
       if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
                 }
    }
	
	printf("=======================\n");
    for (i = 0; i < NUM_THREADS; i ++)
    {
       pthread_join(threads[i], NULL);
        printf("Thread stopped %ld\n", i);
    }
}
