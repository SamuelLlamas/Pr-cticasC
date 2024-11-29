#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(){
    int n;
    printf("Introduce n: ");
    scanf("%d", &n);

    int *m1 = (int*)malloc(sizeof(int)*n*n);
    int *m2 = (int*)malloc(sizeof(int)*n*n);
    int *m3 = (int*)malloc(sizeof(int)*n*n);

    if (m1 == NULL || m2 == NULL || m3 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    double t1 = omp_get_wtime();

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        srand(tid * time(NULL)); 

        #pragma omp for collapse(2)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                *(m1+i*n+j) = rand()%10 +1;
            }
        }

        #pragma omp for collapse(2)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                *(m2+i*n+j) = rand()%10 +1;
            }
        }

        #pragma omp for collapse(3)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                *(m3+i*n+j) = 0; 
                for(int k=0; k<n; k++){
                    *(m3+i*n+j) += (*(m1+i*n+k)) * (*(m2+k*n+j)); 
                }
            }
        }
    }

    double t2 = omp_get_wtime();
    printf("Matriz 1:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("        %d        ", *(m1+i*n+j));
        }
        printf("\n");
    }
    printf("Matriz 2:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("        %d        ", *(m2+i*n+j));
        }
        printf("\n");
    }
    printf("Matriz 3:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("        %d        ", *(m3+i*n+j));
        }
        printf("\n");
    }

    printf("Tiempo %lf\n", t2-t1);

    free(m1);
    free(m2);
    free(m3);

    return 0;
}