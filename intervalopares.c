#include <stdio.h>

int main() {
    int a , b;

    printf("Dime dos números: \n");
    scanf("%d %d", &a, &b);

    do{
        
        if( a<0 || b < 0 || a>b){
                printf("Dime otros números, estos no valen, error\n");
                scanf("%d %d", &a, &b);
        }
    }while(a<0 || b < 0 || a>b);


    for(int i =a; i<=b; i++){
        if(i%2==0){
            printf("%d ", i); 
        }
    }
    return 0;
    
}
