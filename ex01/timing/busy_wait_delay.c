#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

void busy_wait_delay(int seconds)
{
    int i, dummy;
    int tps = sysconf(_SC_CLK_TCK);
    clock_t start;struct tms exec_time;
    times(&exec_time);
    start = exec_time.tms_utime;
    while( (exec_time.tms_utime - start) < (seconds * tps))
    {
        for(i=0; i<1000; i++)
        {
            dummy = i;
        }
        times(&exec_time);
    }
}

void* print_with_delay(void* arg) {
    printf("Hello form %i\n", (int)arg);
    busy_wait_delay(5);
    printf("Goodbye form %i\n", (int)arg);
}

int main() {
    pthread_t thread_1;
    pthread_t thread_2;
    pthread_create(&thread_1, NULL, print_with_delay, (void*)1);
    pthread_create(&thread_2, NULL, print_with_delay, (void*)2);
    pthread_exit(0);
    return 0;
}
