#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combinar(int n, char *simbolos, int nivel);

int main(int argc, char *argv[]) {

    // Validaciones
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1; // Terminamos el programa con error
    }

    // Argumento de cadena a entero
    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("El número debe ser positivo.\n");
        return 1;
    }

    // Reservamos memoria para la cadena (n caracteres + 1 para el terminador nulo)
    // Malloc es una funcioin para asignar dinamicamente un array de char con n+1 espacios
    char *simbolos = malloc((n + 1) * sizeof(char));
    if (simbolos == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    simbolos[0] = '\0'; // Inicializamos la cadena como vacía

    combinar(n, simbolos, 0);

    free(simbolos); // Liberamos la memoria reservada
    return 0;
}

// Llamamos a la función combinar, pasando n, el array simbolos y 0 como el nivel inicial.
void combinar(int n, char *simbolos, int nivel) {
    if (nivel == n) {
        printf("%s\n", simbolos); // Se imprime la cadena completa cuando alcanzamos el nivel deseado
        return;
    }

    // Probar cada carácter ('a', 'b', 'c')
    char opciones[] = {'a', 'b', 'c'};
    for (int i = 0; i < 3; i++) {
        simbolos[nivel] = opciones[i];  // Asignamos el carácter en la posición actual
        simbolos[nivel + 1] = '\0';     // Aseguramos el terminador nulo
        combinar(n, simbolos, nivel + 1); // Llamada recursiva para el siguiente nivel
    }
}
