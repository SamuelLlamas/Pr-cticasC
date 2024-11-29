#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int nthreads, tid, media, resultado;
    int n;
    printf("Introduce n: ");
    scanf("%d", &n);
    int sum = 0;
    int *m = (int*)malloc(sizeof(int)*n*n);
    double t1 = omp_get_wtime();

    #pragma omp parallel private (tid)
      
    {      
        srand(tid);
        #pragma omp for 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){ 
                *(m+i*n+j) = rand()%10+1;
            }    
        }
        #pragma omp for reduction(+ : sum)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum+= *(m+i*n+j);
            }
            resultado += sum;
            sum = 0;
        }
        #pragma omp single
        media = resultado/n;
                           
        }
    
    double t2 = omp_get_wtime();
    printf("La media del vector es: %d\n", media);
    printf("Tiempo %lf", t2-t1);

    free(m);
    return 0;
}