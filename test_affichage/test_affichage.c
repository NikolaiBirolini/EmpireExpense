#include <stdio.h>
#include <time.h>

int main() {
    
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 1; i <= 1000000; ++i) 
    {
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double duration_ms = (end.tv_sec - start.tv_sec) * 1000.0 +
                         (end.tv_nsec - start.tv_nsec) / 1000000.0;

    printf("Delay : %.2f ms.\n", duration_ms);

    return 0;
}