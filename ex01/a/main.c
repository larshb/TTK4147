#include <stdlib.h>
#include <stdio.h>

void allocate(int value) {
    int *ptr = NULL;
    ptr = malloc(100000 * sizeof(int));
    *ptr = value;
    printf("test of allocated memory: %i\n");
}

int main() {

    while(1) allocate(3);

    return 0;
}
