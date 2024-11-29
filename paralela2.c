#include <omp.h>
#include <stdio.h>
int main(){
    int nthreads,tid;
    #pragma omp parallel private(tid)
    {
        #pragma omp sections
        {
                #pragma omp section
                {
                    tid=omp_get_thread_num();
                    nthreads=omp_get_num_threads();
                    printf("El thread %d, de %d, calcula la sección 1\n", tid, nthreads);
                }
                #pragma omp section
                {
                    tid=omp_get_thread_num();
                    nthreads=omp_get_num_threads();
                    printf("El thread %d, de %d, calcula la sección 2\n", tid, nthreads);
                }
                #pragma omp section
                {
                    tid=omp_get_thread_num();
                    nthreads=omp_get_num_threads();
                    printf("El thread %d, de %d, calcula la sección 3\n", tid, nthreads);
                }
                #pragma omp section
                {
                    tid=omp_get_thread_num();
                    nthreads=omp_get_num_threads();
                    printf("El thread %d, de %d, calcula la sección 4\n", tid, nthreads);
                }
            }
        }
        return 0;
    
}