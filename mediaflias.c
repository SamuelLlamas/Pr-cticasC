#include <stdio.h>
void leermatriz(int matriz[3][3]);
float calculamedia(int matriz[3][3]);
int main (){

    int m[3][3];
    float media;
    leermatriz(m);
    media = calculamedia(m);
    printf("La media es: %f\n", media);
    
}

float calculamedia(int matriz[3][3]){

    int i, suma, j;float media;
    suma = 0;
    for(i=0;i<3;i++){
   
        
        for(j=0;j<3; j++){
            suma= suma+ matriz[i][j];
        
        }
        
    media = suma/9;
    
    
}
return(media);
}

void leermatriz(int matriz[3][3]){
    int i, j;
    for(i=0;i<3;i++){
          for(j=0;j<3;j++){
                printf("Numero %d:", j+1);
                scanf("%d", &matriz[i][j]);
      
      }
    
      
  }
        
}     
        
       
