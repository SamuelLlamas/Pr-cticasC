#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int nthreads, tid, media;
    int n;
    printf("Introduce n: ");
    scanf("%d", &n);
    int sum = 0;
    int *v = (int*)malloc(sizeof(int)*n);
    double t1 = omp_get_wtime();

    #pragma omp parallel private (tid)
      
    {      
        srand(tid);
        #pragma omp for 
        for(int i=0; i<n; i++){
            *(v+i) = rand()%100+1;
            printf("%d\n", *(v+i));
                }
           
        #pragma omp for reduction(+ :sum)
        for(int i = 0; i<n; i++){
            sum+= v[i];
            }
            
        #pragma omp single
        media = sum/n;                   
        }
    
    double t2 = omp_get_wtime();
    printf("La media del vector es: %d\n", media);
    printf("Tiempo %lf", t2-t1);

    return 0;
}

    


