/*  
  Autor: Aldo Garcia Ambrosio (C) Marzo 2025
  Autor origina: Uso de IA (GPT o4, Claude)
  Version: 1.2
  
  Programa que lee n caracteres de la entrada estándar y los ordena con el algoritmo
  de ordenamiento Insercion.
  
  Complejidad: O(n^2).
  
  Observaciones: Se tomara la estructura Main de ordenBurbuja.c para realizar agilizar la tarea y realizar el ordenamiento por inserción.
  
  Compilación: Windows / Linux: gcc ordenInsercion.c -o insercion

  Ejecución: ./insercion {elementos a ordenar}  < lista_caracteres.txt
            ./insercion {elementos a ordenar} < lista_caracteres.txt > salida.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
void ordenInsercion(int *arregloDes, int n)
Recibe: int * arreglo como arregloDes y n como tamaño del arreglo
Devuelve: void (No retorna valor explicito)
Observaciones: Función que orderna el arregloDes de menor a mayor haciendo uso del
algoritmo de ordenamiento Insercion (acomodanto los elementos en orden asecendente y tomando elementos por elemento acomodandolo en su correspondiente lugar
en el arreglo ya ordenado) a razón de O(n^2).
*/
void ordenInsercion(int *arregloDes, int n) {
    // Iteraciones para recorrer el arreglo (menos el nombre del arreglo)
    for(int i = 0; i <= (n - 1); i++) {
        // Variable temporal para guardar el valor actual
        int j = i;
        // Variable temporal para almacenar el arreglo
        int temp = arregloDes[i];
        // Ciclo para recorrer el arreglo y acomodar los elementos en su lugar correcponente
        while(j > 0 && (temp < arregloDes[j - 1])){
            // Ordenamiento de los elementos
            arregloDes[j] = arregloDes[j - 1];
            j--;
        }
        // Asignar el valor temporal al arreglo
        arregloDes[j] = temp; 
    }
    
}

// Función principal
int main(int num_arg, char *arg_user[]) {

    //Recibir por argumento el tamaño de n y el valor / intervalo de valores a usar
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
	// Algoritmo de Ordenamiento Insercion
	//*****************************************
    // Llamar a la función de ordenamiento
    ordenInsercion(arreglo, n);
    
    // Mostrar el arreglo ordenado
    printf("Arreglo despues del ordenamiento: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d \n", arreglo[i]);
    }
    
    // Liberar la memoria
    free(arreglo);
    
    return 0;
}