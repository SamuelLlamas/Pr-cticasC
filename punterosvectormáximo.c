#include <stdio.h>
#include <stdlib.h>

int cogerelmaximo(int *pnumeros, int n);


int main(){
    
    int maximo;
    int num;
    scanf("%d", &num);
    int *pnumeros = (int *)malloc(num * sizeof(int));

    for (int i = 0; i < num; i++) {
        scanf("%d", &pnumeros[i]);
    }
   
    
    maximo = cogerelmaximo(pnumeros, num);
    printf("\nEl máximo es: %d\n", maximo);
    
    free(pnumeros);
    return 0;

}

int cogerelmaximo(int *pnumeros, int n){
      int maximo;int i;
      maximo = *pnumeros;
      
       for (i = 0; i < n ; i++) { 
            
                if (maximo<*(pnumeros + i)){
                        maximo = *(pnumeros+i);
              }
        }
    return(maximo);
    }

