#include <pthread.h>
#include <stdio.h>

int glo = 0;

void* increment(void* arg) {
  int loc = 0;
  loc += 3;
  glo += 3;
  printf("Global: %i\nLocal: %i\n", glo, loc);
}

int main() {
  pthread_t pt;
  pthread_create(&pt, NULL, increment, NULL);
  increment(0);
  pthread_join(pt, NULL);
  return 0;
}
