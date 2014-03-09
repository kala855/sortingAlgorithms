//============================================================================
// Name        : insertionSort.cpp
// Author      : John H. Osorio Ríos - Yensy H. Gómez Villegas
// Version     :
// Copyright   : Use this code only for academic purposes
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertionSort(int *A, int longitud)
{
	int i,key,j;

	for (j = 1; j < longitud; ++j)
	{
		key = A[j];
		i = j - 1;
		while ((i > -1) && (A[i] > key)){

			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
	return 0;

}

int printVector(int *vector, int longitud){
	int i;
	for (i = 0; i < longitud; ++i)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
	return 0;
}


int readData(int *A,int cantidadDatos, char *nombreArchivo){
	int i;
	FILE *f;
	f = fopen(nombreArchivo, "r");

	if(f == NULL){
		printf("El archivo de entrada especificado no existe, verifique la dirección proporcionada\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < cantidadDatos; ++i) {
		fscanf(f, "%d", &A[i]);
	}

	fclose(f);
	return 0;
}

int writeData(int *A, int cantidadDatos, char *nombreArchivo){
	FILE *pFile;
	int i;
	pFile = fopen(nombreArchivo, "w");
	for (i = 0; i < cantidadDatos; ++i) {
		fprintf(pFile, "%d\n",A[i]);
	}

	fclose(pFile);
	return 0;
}


int main(int argc, char **argv){

	if (argc != 4){
		printf("Uso: ./insertionSort archivoEntrada archivoSalida numeroDatos\n");
		return EXIT_FAILURE;
	}

	clock_t start, end;
	double cpu_time_used;
	int *A, cantidadDatos;
	cantidadDatos = atoi(argv[3]);
	A = (int*)malloc(sizeof(int)*cantidadDatos);
	readData(A,cantidadDatos,argv[1]);
	start = clock();
	insertionSort(A, cantidadDatos);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time elapsed in seconds: %.5f\n", cpu_time_used);
	writeData(A,cantidadDatos,argv[2]);
	free(A);
	return 0;
}
