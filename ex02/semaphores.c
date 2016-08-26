#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define THREADS 5

sem_t sem;

void* do_stuff(void* id) {
  while(1) {
    sem_wait(&sem);
    printf("Thread %i is doing stuff\n", (int*)id);
    sleep(1);
    sem_post(&sem);
  }
}

int main() {
  sem_init(&sem, 0, 3);
  pthread_t thread[THREADS];
  for (int i = 0; i < THREADS; i++) {
    pthread_create(&thread[i], NULL, do_stuff, (void*)i);
  }
  pthread_join(thread[0], NULL);
  return 0;
}
