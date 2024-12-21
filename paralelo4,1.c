#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    // Verificar que se proporcionen dos argumentos para el tamaño de la matriz
    if (argc != 3) {
        printf("Uso: %s <filas> <columnas>\n", argv[0]);
        return 1;
    }

    // Obtener el tamaño de la matriz
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    if (n <= 0 || m <= 0) {
        printf("El número de filas y columnas debe ser mayor que 0.\n");
        return 1;
    }

    // Reservar memoria para la matriz
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(m * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Error al asignar memoria para la matriz.\n");
            return 1;
        }
    }

    // Configurar el número de hilos
    omp_set_num_threads(4);

    // Configuración de schedule y pruebas
    const char *schedules[] = {"static", "dynamic", "guided"};
    int chunk_sizes[] = {1, 2, 4}; // Diferentes tamaños de bloque

    for (int sched = 0; sched < 3; sched++) {
        for (int chunk = 0; chunk < 3; chunk++) {
            printf("Schedule: %s, Chunk Size: %d\n", schedules[sched], chunk_sizes[chunk]);

            // Configurar schedule en tiempo de ejecución
            if (sched == 0)
                omp_set_schedule(omp_sched_static, chunk_sizes[chunk]);
            else if (sched == 1)
                omp_set_schedule(omp_sched_dynamic, chunk_sizes[chunk]);
            else if (sched == 2)
                omp_set_schedule(omp_sched_guided, chunk_sizes[chunk]);

            // Inicialización de la matriz sin `collapse`
            #pragma omp parallel for schedule(runtime)
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    matriz[i][j] = omp_get_thread_num();
                }
            }

            // Imprimir la matriz
            printf("Matriz sin collapse:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
            printf("\n");

            // Inicialización de la matriz con `collapse`
            #pragma omp parallel for collapse(2) schedule(runtime)
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    matriz[i][j] = omp_get_thread_num();
                }
            }

            // Imprimir la matriz
            printf("Matriz con collapse:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    // Liberar memoria
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
