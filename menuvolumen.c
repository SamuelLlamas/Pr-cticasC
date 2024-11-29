#include <stdio.h>
int funcion( int num);
int menuortoedro(float volumen);
int menucono(float volumen);
int main(){
    int num;
    int volumen;
    num = funcion(num);
    
    if( num == 1){
        float volumen1;
        volumen = menucono(volumen1);
      }
    if( num == 2){
        float volumen2;
        volumen = menuortoedro(volumen2);
      }
    if( num == 3){
        
      }
    return 0;
  
  }
int funcion(  int num){

    
    printf("Menu: \n1. Cono\n2. Ortoedro: \nDi opción:");
    
    do{
        
          scanf("%d", &num);
          if(num<0 || num>3){
            printf("\nEl volumen no se puede calcula. La opción tiene que ser 1 ó 2\n");
            
            }
       
        }while(num<0||num>3);
    
    if ( num == 1){
        return(num);
      }
    if( num == 2){
        return(num);
      }
    if( num == 3){
        return(num);
      }
    return(num);
  }
    
int menucono(float cono){
    float h, r;
    
    printf("Dime altura: ");
    scanf("%f", &h);
    printf("Dime radio: ");
    scanf("%f", &r);
    
    cono = (0.33)*(3.14)*h*(r*r);
    printf("Tu volumen es: %f ", cono);
    return(volumen);
  }
  
int menuortoedro(float ortoedro){
    float a, b , h;
    
    printf("Dime ancho: ");
    scanf("%f", &a);
    printf("Dime base: ");
    scanf("%f", &b);
    printf("dime altura: ");
    scanf("%f", &h);
    
    ortoedro = (a*b)*h;
    printf("El volumen del ortoedro es %.2f\n ", ortoedro);
    return(ortoedro);
 } 
  
