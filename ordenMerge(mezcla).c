/*  
  Autor: Aldo Garcia Ambrosio (C) Marzo 2025
  Autor origina: Uso de IA (GPT o4, Claude)
  Version: 1.0
  
  Programa que lee n caracteres de la entrada estándar y los ordena con el algoritmo
  de ordenamiento Merge o mezcla.
  
  Complejidad: O(nlog2(n))
  
  Observaciones: Se tomara la estructura Main de ordenBurbuja.c para realizar agilizar la tarea y realizar el ordenamiento por merge
  
  Compilación: Windows / Linux: gcc ordenMerge(mezcla).c -o merge

  Ejecución: ./merge {elementos a ordenar} < lista_caracteres.txt
            ./merge {elementos a ordenar} < lista_caracteres.txt > salida.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
void mergeSort(int *arregloDes, int p, int r)
Recibe: int * arreglo como arregloDes y n como tamaño del arreglo       


Devuelve: void (No retorna valor explicito)
Observaciones: Función que orderna el arregloDes de menor a mayor haciendo uso del
algoritmo de ordenamiento Merge o mezcla ()
*/
void mergeSort(int *arregloDes, int p, int r) {
    if (p < r){
        int q = (int)((p + r) / 2);
        Mergesort(arregloDes, p, q);
        Mergesort(arregloDes, q + 1, r);
        Merge(arregloDes, p, q, r);
    }
}

/*
void Merge(int *arregloDes, int p, int q, int r)
Recibe: int * arreglo como arregloDes y n como tamaño del arreglo       


Devuelve: void (No retorna valor explicito)
Observaciones: Función que orderna el arregloDes de menor a mayor haciendo uso del
algoritmo de ordenamiento Merge o mezcla ()
*/
void Merge(int *arregloDes, int p, int q, int r){
    int l = r - p + 1, i = p, j = q + 1, k;
    int arregloAux[k];
    for(k = 0; k >= 1; k++){
        if(i <= q && j <= r){
            if(arregloDes[i] <= arregloDes[j]){
                arregloAux[k] = arregloDes[i];
                i++;
            }else{
                arregloAux[k] = arregloDes[j];
                j++;
            }
        } else if(i <= q){
            arregloAux[k] = arregloDes[i];
            i++;
        } else{
            arregloAux[k] = arregloDes[j];
            j++;
        }
    }
    k = p;
    for(int i = 0; i < 1; i++){
        arregloDes[k] = arregloAux[i];
        k++;
    }
}

// Función principal
int main(int num_arg, char *arg_user[]) {

    //Recibir por argumento el tamaño de n y el valor / intervalo de valores a usar
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
	// Algoritmo de Ordenamiento Merge
	//*****************************************
    // Llamar a la función de ordenamiento
    //                                                                  mergeSort(arreglo, n);
    
    // Mostrar el arreglo ordenado
    printf("Arreglo despues del ordenamiento: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d \n", arreglo[i]);
    }
    
    // Liberar la memoria
    free(arreglo);
    
    return 0;
}