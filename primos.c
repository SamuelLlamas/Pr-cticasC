#include <stdio.h>
void inicializador( int primos[10]);
int calculadivisores( int numero);
int esprimo(int primo);
int main(){
    int pr[10];int num;int i;
    
    
   
    inicializador(pr);
    printf("Los 10 primeros primos son:\n");
    for ( i= 0; i <10; i++){
        printf("%d\n", pr[i]);
        }
    return  0 ; 
  }
    
    
    
void inicializador(int primos[10]){
    int i=0; int num=2;int x;
    
    while(i<10){
        if (esprimo(num)){
              primos[i]=num;
              i++;
              
            
          }
          num++;
          }
          
    
  }
    
    
    
int calculadivisores( int numero){
    int i;int x=0;
    for ( i=1; i<=numero; i++){
       
       if ( numero%i == 0){
           
            x++;
            }
            
          }
        return(x);
        }
        
      
int esprimo( int primo){
    
    int num; int i;
    num = calculadivisores( primo);
    
        if ( num<=2){
          i=1;
          
          
          }
        else{
          i =0;
          }
        return(i);
        }
      
      
        
    
