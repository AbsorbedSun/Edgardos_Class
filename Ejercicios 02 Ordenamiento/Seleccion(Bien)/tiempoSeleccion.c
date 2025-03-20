/*
tiempo.c
Autor: Aldo Garcia Ambrosio (C) Marzo 2025
Autor origina: Edgardo Adrián Franco Martínez
Uso de IA (GPT o4, Claude)
Version: 1.0

Programa que lee n números de la entrada estandar y los coloca en un arreglo A, 
después ejecuta un algoritmo que invierte el arreglo y posteriormente pierde el 
tiempo en orden O(n^2).

Compilación 
Windows: gcc tiempo.c -o tiempo.exe
Linux: gcc tiempo.c -o tiempo

Ejecución: 
./burbuja {elementos a ordenar}  < lista_caracteres.txt
./burbuja {elementos a ordenar} < lista_caracteres.txt > salida.txt
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

/*
void ordenSeleccion(int *arregloDes, int n)
Recibe: int * arreglo (puntero) como arregloDes y n como tamaño del arreglo
Devuelve: void (No retorna valor explicito)
Observaciones: Función que ordena el arregloDes de menor a mayor haciendo uso del algoritmo de ordenamiento 
Seleccion (busca el mínimo en la parte desordenada y lo intercambia con el primer elemento de esa parte ademas de dividir en parte ordenada y no ordenada).
*/
void ordenSeleccion(int *arregloDes, int n) {
    // Iterar sobre el arreglo partiendo del segundo elemento¿?
    for(int k = 0; k <= (n - 2); k++){
        // Indice del menos valor en la parte ordenada, inicia tomando el primer elemento de la parte desordenada
        int posMin = k;
        // Iteracion para encontrar el minimo en la parte desordenada
        for(int i = k + 1; i <= (n - 1); i++){
            if(arregloDes[i] < arregloDes[posMin]){
                // Asignar el nuevo valor minimo
                posMin = i;
            }
        }
        // Intercambiar el valor minimo con el primer elemento de la parte desordenada
        int temp = arregloDes[posMin]; // Asigna el valor minimo a una variable temporal
        arregloDes[posMin] = arregloDes[k]; // Reemplaza el menor valor encontrado por el primer elemento de la parte desordenada
        arregloDes[k] = temp; // Coloca el menor valor en la posición k (moviendolo a la parte ordenada)
    }
}
	

// Funcion principal
int main(int num_arg, char* arg_user[]){	
    //Variables para la medición de tiempos    
    clock_t t_inicio, t_final;
    double t_intervalo;
	
	//Recibir por argumento el tamaño de n y el valor a buscar
	if (num_arg != 2) {
		printf("\nIndique el tamanio de n y el valor a buscar - Ejemplo: [user@equipo]$ %s 100\n",arg_user[0]);
		exit(1);
	} 
	
	//Tomar el argumento del main
	int n = atoi(arg_user[1]); //n
	
	// Apartar memoria para n números enteros
    int *arreglo = malloc(n * sizeof(int));
	if( arreglo == NULL){
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}	
	
	//Leer de la entrada estandar los n valores y colocarlos en el arreglo de números
	for(int i = 0; i < n; i++){
		scanf("%d",&arreglo[i]);
	}
	
	//*****************************************  
	//Algoritmo a medir el tiempo
	//*****************************************
	//Inicia medición del tiempo
	t_inicio = clock();

	//*****************************************  
	// Algoritmo de Ordenamiento Seleccion
	//*****************************************
	//Llamar al algoritmo
	ordenSeleccion(arreglo,n);
	
	//Termina medición del tiempo	
	t_final = clock();
	
	//Cálculo del tiempo y enviar mensaje a salida estandar con la medición  
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
    printf("\nTiempo medido: %.10f segundos.", t_intervalo);
	
	//Enviar a la salida estandar el arreglo final
	for(int i = 0; i < n; i++)
		printf("\nArreglo[%d] = %d", i, arreglo[i]);

	// Liberar la memoria
    free(arreglo);
	
	return 0;
}
