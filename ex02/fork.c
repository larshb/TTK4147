#include <stdio.h>
#include <unistd.h>

int glo = 0;

int main() {
    int loc = 0;
    glo = 0;
    vfork();
    loc += 3;
    glo += 3;
    printf("Global: %i\nLocal: %i\n", glo, loc);
    return 0;
}
