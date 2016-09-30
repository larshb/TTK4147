#include "io.h"
#include <comedilib.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void timespec_add_us(struct timespec *t, long us)
{
	// add microseconds to timespecs nanosecond counter
	t->tv_nsec += us*1000;

	// if wrapping nanosecond counter, increment second counter
	if (t->tv_nsec > 1000000000)
	{
		t->tv_nsec = t->tv_nsec-1000000000;
		t->tv_sec += 1;
	}
}

void* do_test(void* id)
{
	int test = (int)id;
	io_write(id, 1);
	while(1)
	{
		if(!io_read(test))
		{
			io_write(test, 0);
			usleep(5);
			io_write(test, 1);
		}
	}
}

void* do_test2(void* id)
{
	int test = (int)id;
	io_write(id, 1);
	struct timespec next;
	clock_gettime(CLOCK_REALTIME, &next);
	while(1)
	{
		clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &next, NULL);
		timespec_add_us(&next, 1000);
		if(!io_read(test))
		{
			io_write(test, 0);
			usleep(5);
			io_write(test, 1);
		}
		pthread_yield();
	}
}

void* do_test3(void* id)
{
	int test = (int)id;
	io_write(id, 1);
	struct timespec next;
	clock_gettime(CLOCK_REALTIME, &next);
	while(1)
	{
		clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &next, NULL);
		timespec_add_us(&next, 100);
		if(!io_read(test))
		{
			io_write(test, 0);
			usleep(5);
			io_write(test, 1);
		}
		pthread_yield();
	}
}

int set_cpu(int cpu_number)
{
	// setting cpu set to the selected cpu
	cpu_set_t cpu;
	CPU_ZERO(&cpu);
	CPU_SET(cpu_number, &cpu);

	// set cpu set to current thread and return
	return pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpu);
}

void* disturbance(void* arg)
{
	int i;
		i = 2;
	while(1)
	{
		i = i*i;
	}
}

int main(int argc, char *argv[]){
	assert(argc>1);
	io_init();
	set_cpu(1);
	pthread_t threads[13];
	int i;
	if(strcmp(argv[1],"1")==0)
	{
		puts("Approval step 3");
		for(i = 0; i < 3; i++)
		{
			pthread_create(&threads[i], NULL, do_test, (void*)(i+1));
		}
		for(i = 3; i < 14; i++)
		{
			pthread_create(&threads[i], NULL, disturbance, NULL);
		}
	}
	else if(strcmp(argv[1],"2")==0)
	{
		puts("Approval step 2");
		for(i = 0; i < 3; i++)
		{
			pthread_create(&threads[i], NULL, do_test2, (void*)(i+1));
		}
		for(i = 3; i < 14; i++)
		{
			pthread_create(&threads[i], NULL, disturbance, NULL);
		}
	}
	else if(strcmp(argv[1],"3")==0)
	{
		puts("Approval step 3");
		for(i = 0; i < 3; i++)
		{
			pthread_create(&threads[i], NULL, do_test3, (void*)(i+1));
		}
		for(i = 3; i < 14; i++)
		{
			pthread_create(&threads[i], NULL, disturbance, NULL);
		}
	}
	pthread_join(threads[0], NULL);
	return 0;
}