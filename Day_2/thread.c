#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 5

int count = 0;

struct thread {
	int id;
	char *name;
	int i;
	int d;
};

	struct thread t_struct[NUM_THREADS];
    
char * names[] = {
    "Pervii",
    "Vtoroii",
    "Tretii",
    "Chetvertii",
    "Pyatii"
};
void *f(void *num)
{
    usleep(1);
	int i;
	int t = (long)num;
	t_struct[t].id = pthread_self();
	for (i = 0; i < t_struct[t].i; i++)
	{
		count = count + t_struct[t].d;
        printf("===============\n");
		printf("Thread  %d\n", t);
        printf("Thread  %s\n", t_struct[t].name);
		printf("Thread id %d\n", t_struct[t].id);
		printf("Thread i %d from %d\n", i + 1, t_struct[t].i);
		printf("Thread d %d\n", t_struct[t].d);
        printf("===============\n");
		printf("Tread count %d\n", count);
	}

}

int main (int argc, char *argv[])
{

	long i;
	int rc;
	pthread_t threads[NUM_THREADS];
    time_t t;
    srand((unsigned) time(&t));

	for (i = 0; i < NUM_THREADS; i++)
	{
		printf("Creating thread %ld\n", i);
		rc = pthread_create(&threads[i], NULL, f, (void *)i);
		t_struct[i].i = rand() & 20;
		t_struct[i].d = rand() % 20 - 10;
        t_struct[i].name = names[rand() % 5];
        printf("%d\n", rand());
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
    printf("------------\n");
    printf("Final count %d\n", count);
    printf("------------\n");
    
}
