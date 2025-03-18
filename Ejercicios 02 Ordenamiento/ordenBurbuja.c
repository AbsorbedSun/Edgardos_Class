/*  
  Autor: Aldo Garcia Ambrosio (C) Marzo 2025
  Autor origina: Uso de IA (GPT o4, Claude)
  Version: 1.4
  
  Programa que lee n caracteres de la entrada estándar y los ordena con el algoritmo
  de ordenamiento Burbuja. 
  
  Complejidad: O(n^2).
  
  Observaciones: 
  
  Compilación: Windows / Linux: gcc ordenBurbuja.c -o burbuja

  Ejecución: ./burbuja {elementos a ordenar}  < lista_caracteres.txt
            ./burbuja {elementos a ordenar} < lista_caracteres.txt > salida.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
void ordenBurbuja(int *arregloDes, int n)
Recibe: int * arreglo como arregloDes y n como tamaño del arreglo
Devuelve: void (No retorna valor explicito)
Observaciones: Función que orderna el arregloDes de menor a mayor haciendo uso del
algoritmo de ordenamiento burbuja (compara de 2 en 2 y ordena) a razón de O(n^2).
*/
void ordenBurbuja(int *arregloDes, int n) {
    bool cambios = true;
    // Variable de iteracion
    int i = 0;
    // Ciclo determinado por el número de elementos en el arreglo
    while (i <= (n - 2) && cambios) {
        cambios = false;
        // Iteracion para comparar de 2 en 2 y ordenar
        for (int j = 0; j < (n - 2) - i; j++) {
            // Comparacion y ordenamiento
            if (arregloDes[j] > arregloDes[j + 1]) {
                // Variable auxiliar para el intercambio
                int aux = arregloDes[j];
                arregloDes[j] = arregloDes[j + 1];
                arregloDes[j + 1] = aux;
                cambios = true;
            }
        }
        /*Incremento de la variable para evitar el ciclo infinito o evitar
        el cierre anticipado*/ 
        i++;
    }
    
}

// Función principal
int main(int num_arg, char *arg_user[]) {

    //Recibir por argumento el tamaño de n y el valor a buscar
	if (num_arg != 2) 
	{
		printf("\nIndique el tamanio de n y el valor a buscar - Ejemplo: [user@equipo]$ %s 100\n",arg_user[0]);
		exit(1);
	} 

    // variable que define el numero de elementos a leer y ordenar
    int n = atoi(arg_user[1]);
    
    // Apartar memoria para n números enteros
    int *arreglo = malloc(n * sizeof(int));
    
    // Valir que se haya apartado la memoria correctamente
    if (arreglo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        exit(1);
    }
    
    //Lee de la entrada estandar los n valores y los coloca en un arreglo
    for (int i = 0; i <= n; i++) {
        scanf("%d", &arreglo[i]);
    }
    
    // Mostrar el arreglo antes del ordenamiento
    printf("Arreglo antes del ordenamiento: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d \n", arreglo[i]);
    }
    printf("\n");

    //*****************************************  
	// Algoritmo de Ordenamiento Burbuja
	//*****************************************
    // Llamar a la función de ordenamiento
    ordenBurbuja(arreglo, n);
    
    // Mostrar el arreglo ordenado
    printf("Arreglo despues del ordenamiento: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d \n", arreglo[i]);
    }
    
    // Liberar la memoria
    free(arreglo);
    
    return 0;
}