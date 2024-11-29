#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int nthreads, tid, A[10][10], B[10][10], C[10][10], D[10][10];
	double t1 = omp_get_wtime();
	
	#pragma omp parallel private(tid)
	{
	
		#pragma omp sections
		{
			#pragma omp section	
			{
		
			srand(tid);
			for(int i =0; i<10; i++){
				for(int j=0; j<10; j++){
					A[i][j] = rand()%10+1;
						}
					}
			}
			
			#pragma omp section
			{
			srand(tid);
			for(int i =0; i<10; i++){
				for(int j=0; j<10; j++){
					B[i][j] = rand()%10+1;
						}
					}
			}
		
		
			#pragma omp section
			{
		
			for(int i =0; i<10; i++){
				for(int j=0; j<10; j++){
					C[i][j] = A[i][j]*B[i][j];
						}
					}
			}
					
			#pragma omp section
			{
		
			for(int i =0; i<10; i++){
				for(int j=0; j<10; j++){
					D[i][j]= A[i][j]+B[i][j];
					}
		        	}
		        }
				
		}
	}
		double t2 = omp_get_wtime();
		printf("%lf\n", t2-t1); 
	return 0;
	}
