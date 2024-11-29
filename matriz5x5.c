#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void inicializador(int ma[5][5]);
int main(){

    int i, j , ma[5][5];
    srand(time(NULL));
   
    printf("La matriz 5x5 es:\n");
    inicializador(ma);
    }
        
void inicializador(int ma[5][5]){
    
    int i , j ;
    for(i=0; i<5; i++){
        for(j=0;j<5;j++){
            ma[i][j]= rand()%35+10;
            printf("%d     ", ma[i][j]);
            
            
            
            }
           printf("\n");
          }
          
        }
            
