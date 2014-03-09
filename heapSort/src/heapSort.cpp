#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heapSize;


int parent(int i){
	return (i-1)/2;
}

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i + 2;
}

int maxHeapify(int *A, int i){

	int l,r,largest, temp;
	l = left(i);
	r = right(i);

	if ((l<= heapSize) && (A[l]>A[i]))
		largest = l;
	else
		largest = i;

	if ((r<= heapSize) && (A[r]>A[largest]))
			largest = r;

	if (largest != i){
		temp = A[largest];
		A[largest] = A[i];
		A[i] = temp;
		maxHeapify(A,largest);
	}

	return 0;
}

int buildMaxHeap(int *A, int tamano)
{
	heapSize = tamano - 1;
	int i;
	for (i = ((tamano)/2); i >=0; --i) {
		maxHeapify(A,i);
	}
	return 0;
}


int heapSort(int *A, int tamano)
{
	buildMaxHeap(A,tamano);
	int temp;
	int i;
	for (i = tamano-1; i >= 1; --i) {
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapSize = heapSize - 1;
		maxHeapify(A,0);
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
		printf("Uso: ./heapSort archivoEntrada archivoSalida numeroDatos\n");
		return EXIT_FAILURE;
	}
	clock_t start, end;
	double cpu_time_used;
	int *A, cantidadDatos;
	cantidadDatos = atoi(argv[3]);
	A = (int*)malloc(sizeof(int)*cantidadDatos);
	readData(A,cantidadDatos,argv[1]);
	start = clock();
	heapSort(A,cantidadDatos);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time elapsed in seconds: %.5f\n", cpu_time_used);
	writeData(A,cantidadDatos,argv[2]);
	free(A);
	return 0;
}
