#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    int n, i;
    float *vector1, *vector2, sum1 = 0, sum2 = 0, min1 = 10, min2 = 10, max1 = 0, max2 = 0;

    printf("Ingrese el número de alumnos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El número de alumnos debe ser positivo.\n");
        return 1;
    }

    vector1 = (float *) malloc(n * sizeof(float));
    vector2 = (float *) malloc(n * sizeof(float));

    srand(time(0));

    #pragma omp parallel for private(i)
    for (i = 0; i < n; i++) {
        vector1[i] = (float) rand() / RAND_MAX * 10;
        vector2[i] = (float) rand() / RAND_MAX * 10;
    }

    #pragma omp parallel for reduction(+:sum1, sum2) reduction(min:min1, min2) reduction(max:max1, max2) private(i)
    for (i = 0; i < n; i++) {
        sum1 += vector1[i];
        sum2 += vector2[i];

        if (vector1[i] < min1) min1 = vector1[i];
        if (vector2[i] < min2) min2 = vector2[i];

        if (vector1[i] > max1) max1 = vector1[i];
        if (vector2[i] > max2) max2 = vector2[i];
    }

    printf("Media del primer parcial: %.2f\n", sum1 / n);
    printf("Mínimo del primer parcial: %.2f\n", min1);
    printf("Máximo del primer parcial: %.2f\n", max1);

    printf("Media del segundo parcial: %.2f\n", sum2 / n);
    printf("Mínimo del segundo parcial: %.2f\n", min2);
    printf("Máximo del segundo parcial: %.2f\n", max2);

    free(vector1);
    free(vector2);

    return 0;
}

