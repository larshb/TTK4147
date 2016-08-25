#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* print_with_delay(void* arg) {
    printf("Hello form %i\n", (int)arg);
    sleep(5);
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
