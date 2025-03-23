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
void Merge(int *arregloDes, int posIni, int mitad, int posFin)
Recibe: int * arreglo (puntero) como arregloDes, posIni como posición inicial, mitad como punto medio y posFin como posición final
Devuelve: void (No retorna valor explícito)
Observaciones: Función que mezcla dos subarreglos ordenados en un solo arreglo ordenado
*/
void Merge(int *arregloDes, int posIni, int mitad, int posFin){
    // Calcula el tamaño del arreglo a mezclar, indice para el subarreglo izquierdo, indice para el subarreglo derecho y un indice auxiliar
    int l = posFin - posIni + 1, i = posIni, j = mitad + 1, k;
    // Arreglo auxiliar para almacenar los valores ordenados
    int *arregloAux = malloc(l * sizeof(int));

    // Iteracion que recorre los elementos del arreglo auxiliar
    for(k = 0; k <= (l - 1); k++){
        // Verifica si los indices no han llegado al final de los subarreglos
        if(i <= mitad && j <= posFin){
            // Compara elementos de ambos subarreglos y toma el menor
            if(arregloDes[i] < arregloDes[j]){
                arregloAux[k] = arregloDes[i];
                i++;
            }else{
                arregloAux[k] = arregloDes[j];
                j++;
            }
        } else if(i <= mitad){
            // Si ya no hay elementos en el subarreglo derecho, toma los del izquierdo
            arregloAux[k] = arregloDes[i];
            i++;
        } else{
            // Si ya no hay elementos en el subarreglo izquierdo, toma los del derecho
            arregloAux[k] = arregloDes[j];
            j++;
        }
    }
    // Copia los elementos mezclados de vuelta al arreglo original
    k = posIni;
    for(int i = 0; i < (l); i++){ // ---------------------> Elinminar (l-1) a (l) para obtener el ordenamiento correcto
        arregloDes[k] = arregloAux[i]; 
        k++;
    }

    free(arregloAux);
}

/*
void mergeSort(int *arregloDes, int posIni, int posFin)
Recibe: int * arreglo (puntero)como arregloDes y posIni y posFin como enteros indica la posición inicial y final del arreglo.   
Devuelve: void (No retorna valor explicito)
Observaciones: Función que orderna el arregloDes de menor a mayor haciendo uso del
algoritmo de ordenamiento Merge o mezcla de forma recursiva (divide el arreglo en mitades, ordena cada mitad y luego las mezcla).
*/
void mergeSort(int *arregloDes, int posIni, int posFin) {
    if (posIni < posFin){
        // Calcula el punto medio/mitad del arreglo
        int mitad = (int)((posIni + posFin) / 2);
        // Llamada recursiva para la primera mitad
        mergeSort(arregloDes, posIni, mitad);
        // Llamada recursiva para la segunda mitad
        mergeSort(arregloDes, (mitad + 1), posFin);
        // Mezcla las dos mitades ordenadas
        Merge(arregloDes, posIni, mitad, posFin);
    }
}
	

/*
int main(int num_arg, char *arg_user[])
Recibe: int num_arg como el total de argumentos ingresadoros al programa y char * arg_user (puntero) 
como un arerglo que alamcena los argumentos de entrada del programa.
Devuelve: 0 si termina correctamente
Observaciones: Función principal que permite hacer uso de la función de ordenamiento burbuja
para ordenar un arreglo de n elementos, ademas de imprimir el tiempo de ejecucion y elresultado en lista .
*/
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
    int *arreglo = malloc((n + 1) * sizeof(int));
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
	// Algoritmo de Ordenamiento Merge
	//*****************************************
    // Llamar a la función de ordenamiento
    mergeSort(arreglo, 0, n - 1);
	
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
