#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int running = 1;
int var1 = 0;
int var2 = 0;

pthread_mutex_t lock;

void* thread1(void* arg) {
  while (running) {
    pthread_mutex_lock(&lock);
    var1 += 1;
    var2 = var1;
    pthread_mutex_unlock(&lock);
  }
}

int main() {
  pthread_t pt;
  pthread_create(&pt, NULL, thread1, NULL);

  //thread2
  for (int i = 0; i < 20; i++) {
    pthread_mutex_lock(&lock);
    printf("Number 1 is %i, number 2 is %i\n", var1, var2);
    pthread_mutex_unlock(&lock);
    usleep(100000);
  }
  running = 0;

  return 0;
}
