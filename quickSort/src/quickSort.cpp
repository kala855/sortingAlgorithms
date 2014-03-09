//============================================================================
// Name        : quickSort.cpp
// Author      : John H. Osorio Ríos - Yensy H. Gómez Villegas
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *A, int p, int r)
{
	int x, i, j,temp;
	x = A[r];
	i = p - 1;
	for (j = p; j <= r-1; ++j) {
		if (A[j]<=x) {
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	return i+1;
}

int quickSort(int *A, int p, int r){
	int q;
	if (p<r){
		q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
	return 0;
}

int printVector(int *A, int tamano){

	int i;
	for (i = 0; i < tamano; ++i) {
		printf("%d ", A[i]);
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
		printf("Uso: ./quickSort archivoEntrada archivoSalida numeroDatos\n");
		return EXIT_FAILURE;
	}
	clock_t start, end;
	double cpu_time_used;
	int *A, cantidadDatos;
	cantidadDatos = atoi(argv[3]);
	A = (int*)malloc(sizeof(int)*cantidadDatos);
	readData(A,cantidadDatos,argv[1]);
	start = clock();
	quickSort(A,0,cantidadDatos-1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time elapsed in seconds: %.5f\n", cpu_time_used);
	writeData(A,cantidadDatos,argv[2]);
	free(A);
	return 0;
}
