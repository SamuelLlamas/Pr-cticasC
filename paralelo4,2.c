#include <stdio.h>
#include <omp.h>
#include <stdbool.h>

bool esPrimo(int num) {
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3;  i*i<= num; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    printf("Introduce el valor de n: ");
    scanf("%d", &n);

    int contador = 0;

    #pragma omp parallel for reduction(+:contador)
    for (int i = 2; i <= n; i++) {
        if (esPrimo(i)) {
            #pragma omp atomic
            contador++;
        }
    }

    printf("Hay %d números primos en el intervalo de 1 a %d\n", contador, n);

    return 0;
}