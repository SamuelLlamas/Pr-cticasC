#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void media(int m[10][5], int ex[10]);
void inicializador(int ma[10][5]);
int main(){

    int i, j , ma[10][5], ex[10],  mediafila;
    srand(time(NULL));
    int mediatotal= 0;
    int suma = 0;
    inicializador(ma);
    media(ma, ex);
    for( i =0; i<10; i++){
        printf("La media del alumno %d es : %d\n", i+1, ex[i]);
        suma= suma +ex[i];
        
        }
    
      mediatotal = suma/10;
    printf("La media total de la clase es: %d\n", mediatotal);
    
 
    
    
    }
    
  
        
void inicializador(int ma[10][5]){
    
    int i , j ;
    for(i=0; i<10; i++){
        for(j=0;j<5;j++){
            ma[i][j]= rand()%10+1;
            printf("%d   ", ma[i][j]);
            
            
            
            }
           printf("\n");
          }
          
        }
            
void media(int m[10][5], int ex[10]){
    int i,j;int sumacols = 0;int media = 0;int mediafila =0;
    for(i=0; i<10; i++){
        for(j=0; j<5; j++){
             sumacols= sumacols+ m[i][j];
             
             }
            
        media = sumacols/5;
        ex[i]= media; 
        sumacols=0;
        
            
      
      }

      }
      
        
        
