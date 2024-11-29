#include <omp.h>
#include <stdio.h>
int main(){
    int nthreads,tid, i=2;
    #pragma omp parallel private(tid) if(i>5)
    {
        tid=omp_get_thread_num();
        nthreads=omp_get_num_threads();
        printf("Hola desde el thread %d de %d threads\n", tid, nthreads);
    }
    return 0;
}