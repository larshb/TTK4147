#include <stdlib.h>
#include <stdio.h>

void allocate(int value) {
    int *ptr = NULL;
    ptr = malloc(100000 * sizeof(int));

    // Assignment C:
    if (ptr == NULL) {
        perror("Error in allocate: ");
        exit(1);
    }

    *ptr = value;
    printf("test of allocated memory: %i\n");
}

int main() {
    while(1) allocate(3);
    return 0;
}
