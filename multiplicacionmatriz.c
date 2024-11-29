#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void inicializador1(int m1[3][3]);
void inicializador2(int m2[3][3]);
void multiplicacion(int ma1[3][3], int ma2[3][3], int m[3][3]);
int main(){
    int m1[3][3], m2[3][3], m[3][3];
    printf("La 1 matriz: \n ");
    inicializador1(m1);
    printf("La 2 matriz: \n");
    inicializador2(m2);
    printf("El resultado de la multiplicación es: \n");
    multiplicacion(m1, m2, m);
    
}


void inicializador1(int m1[3][3]){

  int i , j;
  
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        m1[i][j] = rand()%9+2;
        printf("%d  ", m1[i][j]);
        
      } 
    printf("\n");
    
   }
   
}

void inicializador2(int m2[3][3]){
     int i, j;
     
     for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            m2[i][j] = rand()%9+5;
            printf("%d  ", m2[i][j]);
            
            }
         printf("\n");
          
          }
          
  }
  
void multiplicacion(int ma1[3][3], int ma2[3][3], int m[3][3]){


    int i, j;
    
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            m[i][j] = ma1[i][j]*ma2[i][j];
            printf("%d  ", m[i][j]);
            }
        printf("\n");
        }
        
}
    
  

          
          
          
