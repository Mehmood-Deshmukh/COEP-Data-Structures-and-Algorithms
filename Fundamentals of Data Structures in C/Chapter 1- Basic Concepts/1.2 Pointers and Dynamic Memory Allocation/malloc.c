#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
    if(!((p) = malloc(s))) {\
        fprintf(stderr, "Insufficient Memory!");\
        exit(EXIT_FAILURE);\
    }

int main() {
    int *pi;
    float *pf;
    MALLOC(pi, sizeof(int));
    MALLOC(pf, sizeof(float));
    *pi = 1024;
    *pf = 3.14;
    printf("An Integer = %d, a float = %f\n", *pi, *pf);
    free(pi);
    free(pf);
    return 0;
}