#include <stdio.h>
void calculanota(float Num);
int main(){
    float Num;
    
    calculanota(Num);
    
    
    return 0 ;
    
}

void calculanota(float Num){
    printf("Escribe la nota numérica: ");
    scanf("%f", &Num);
   
    if(Num < 0 || Num > 10){
        printf("La nota no se puede calcular, tiene que estar entre 0 y 10\n");
         }
    if(Num<5 && Num >=0){
        printf("La nota es Suspenso\n");
        }
     
      
    if(Num >= 5 && Num <= 6){
        printf("La nota es Aprobado\n");
        }
    if(Num >= 7 && Num < 9){
        printf("La nota es Notable\n”");
        }
    if(Num >= 9 && Num <11){
        printf("La nota es Sobresaliente\n");
      }
     
    
  }

