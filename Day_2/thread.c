#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 5

int count = 0;

struct thread {
	int id;
	char* name;
	int i;
	int d;
};

	struct thread t_struct[NUM_THREADS];

void *f(void *num)
{
	int i;
	int t = (long)num;
	t_struct[t].id = pthread_self();
	for (i = 0; i < t_struct[t].i; i++)
	{
		count = count + t_struct[t].d;
		printf("Thread  %d\n", t);
		printf("Thread id %d\n", t_struct[t].id);
		printf("Thread i %d\n", t_struct[t].i);
		printf("Thread d %d\n", t_struct[t].d);

		printf("Tread count %d\n", count);
	}

}

int main (int argc, char *argv[])
{

	long i;
	int rc;
	pthread_t threads[NUM_THREADS];

	for (i = 0; i < NUM_THREADS; i++)
	{
		printf("Creating thread %ld\n", i);
		rc = pthread_create(&threads[i], NULL, f, (void *)i);
		t_struct[i].i = rand() & 20;
		t_struct[i].d = rand() % 20 - 10;
		if (rc)
		{
			printf("ERROR");
			exit(-1);
		}
	}
	for (i = 0; i < NUM_THREADS; i ++)
	{
		pthread_join(threads[i], NULL);
		printf("Thread #%ld finished\n",i);
	
	}
}
