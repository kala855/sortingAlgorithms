//============================================================================
// Name        : mergeSortOptimizado.cpp
// Author      : John H. Osorio Ríos - Yensy H. Gómez Villegas
// Version     :
// Copyright   : Use this code only for academic purposes
// Description : C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int mergeAux(int *A, int *L, int *R, int p,int q,int r)
{
	int i,j,k,n1,n2;
	n1 = q - p + 1;
	n2 = r - q;

	for (i = 0; i < n1; ++i)
		L[i] = A[p+i];
	for (j = 0; j < n2; ++j)
		R[j] = A[q+j+1];

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	i = 0;
	j = 0;

	for (k = p; k <= r; ++k)
	{
		if(L[i]<= R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}
	return 0;
}

int mergeSortAux(int *A, int *L, int *R, int p, int r){
	int q;
	if(p<r){
		q = (int)((p+r)/2);
		mergeSortAux(A,L,R,p,q);
		mergeSortAux(A,L,R,q+1,r);
		mergeAux(A,L,R,p,q,r);
	}
	return 0;
}

int mergeSortOptimize(int *A, int p, int r){
	int q,*L,*R,n1,n2;
	if(p<r){
		q = (int)((p+r)/2);
		n1 = q;
		n2 = r - q;
		L = (int*)malloc(sizeof(int)*(n1+1));
		R = (int*)malloc(sizeof(int)*(n2+1));
		mergeSortAux(A,L,R,p,r);
	}
	free(L);
	free(R);
	return 0;

}

int printVector(int *vector, int longitud){
	int i;
	for (i = 0; i < longitud; ++i)
		printf("%d ", vector[i]);
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

int main(int argc, char **argv) {

	if (argc != 4){
		printf("Uso: ./mergeSortOptimizado archivoEntrada archivoSalida numeroDatos\n");
		return EXIT_FAILURE;
	}

	clock_t start, end;
	double cpu_time_used;
	int *A, cantidadDatos;
	cantidadDatos = atoi(argv[3]);
	A = (int*)malloc(sizeof(int)*cantidadDatos);
	readData(A,cantidadDatos,argv[1]);
	start = clock();
	mergeSortOptimize(A,0,cantidadDatos-1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time elapsed in seconds: %.5f\n", cpu_time_used);
	writeData(A,cantidadDatos,argv[2]);
	free(A);
	return 0;
}
