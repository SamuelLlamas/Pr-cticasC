#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int main(){
	int nthreads, tid;
	double t1 = omp_get_wtime();
	
	int n;
	printf("Introduce n: ");
	scanf("%d", &n);
		
	int *a = (int*)malloc(sizeof(int)*n*n);
	int *b = (int*)malloc(sizeof(int)*n*n);
	int *c = (int*)malloc(sizeof(int)*n*n);
	int *d = (int*)malloc(sizeof(int)*n*n);
	
	#pragma omp parallel private(tid)
	{
	
		#pragma omp sections
		{
			#pragma omp section	
			{
		
			srand(tid);
			for(int i =0; i<n; i++){
				for(int j=0; j<n; j++){
					*(a+i*n+j) = rand()%10+1;
						}
					}
			}
			
			#pragma omp section
			{
			srand(tid);
			for(int i =0; i<n; i++){
				for(int j=0; j<n; j++){
					*(b+i*n+j) = rand()%10+1;
						}
					}
			}
		
		
			#pragma omp section
			{
		
			for(int i =0; i<n; i++){
				for(int j=0; j<n; j++){
					*(c+i*n+j) = (*(a+i*n+j))*(*(b+i*n+j));
						}
					}
			}
					
			#pragma omp section
			{
		
			for(int i =0; i<n; i++){
				for(int j=0; j<n; j++){
					*(d+i*n+j) = (*(a+i*n+j))+(*(b+i*n+j));
					}
		        	}
		        }
				
		}
	}
	double t2 = omp_get_wtime();
	printf("%lf\n", t2-t1); 
	return 0;
}
