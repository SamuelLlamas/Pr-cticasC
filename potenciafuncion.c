#include <stdio.h>
int potencia(int base, int exponente);
int main(){
        int resultado;
        int suma, base , exponente;
	
	
	
	
	printf("La potencia da: %d\n", potencia(base, exponente));
	return 0;
}

int potencia( int base , int exponente){
  
        int p;
	int i;
	int x;
	
	
	do{
		printf("Dime base:\n");
		scanf("%d", &base);
		if(base<0){
			printf("La potencia es: Error\n");}
	}while(base<0);
	do{
		printf("Dime exponente:\n");
		scanf("%d", &exponente);
		if(exponente<0){
			printf("La potencia es: Error\n");}
	}while(exponente<0);
	i=1;p=1;
	while(i<=exponente){
		p = p*base;
		i++;
		}
	    
	return(p);
    }
	

