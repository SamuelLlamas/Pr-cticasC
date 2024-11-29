#include <stdio.h>
int calculasuma(int suma);
int main(){
        int resultado;
        int suma;
	printf("Dime número:");
	resultado = calculasuma(suma);
	printf("La suma da: %d", resultado);
	return 0;
}

int calculasuma( int suma){
  
        int num;
	int i;
	int x;
	
	
	do{
		scanf("%d", &num);
		if(num<0){
			printf("ERROR");}
	}while(num<0);
	
	i=0;x=0;
	while(i<=num){
		x = x+i;
		i++;
		}
	    
	return(x);
    }
	

