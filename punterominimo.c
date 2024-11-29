#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializar(int *matriz, int n , int m );
void minimo(int *matriz, int n, int m, int *v);

int main(){ 
    int n, i;
    int m, j;
    int *v;
    int *matriz;

    scanf("%d", &n);
    scanf("%d", &m);

    srand(time(NULL));

    matriz = (int*)malloc(m*n*sizeof(int));
    v = (int*)malloc(n*sizeof(int));
    if(matriz == NULL || v == NULL){
        printf("ERROR\n");
        return 1;
    }
    
    inicializar(matriz, n, m);
    minimo(matriz, n, m , v);

    for(i =0; i<n ; i++){
            printf("El mínimo de la fila %d es: %d\n", i+1, v[i]);
        }



}

void inicializar(int *matriz, int n, int m){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            *(matriz +i*n+j) = rand()%20 -10;
            printf("%d  ", *(matriz +i*n+j));
        }
    printf("\n");

    }

}

void minimo(int *matriz, int n, int m, int *v){

    int i, j, minimo;

    

    for(i=0; i<n; i++){
        minimo = *(matriz+i+n);
        for(j=0; j<m; j++){
            if(minimo>*(matriz+i*n+j)){
                    minimo = *(matriz+i*n+j);
                    
                    
            }
        v[i]= minimo;
        }
    }
}