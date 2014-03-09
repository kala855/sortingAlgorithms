//============================================================================
// Name        : numberGenerator.cpp
// Author      : John H. Osorio Ríos - Yensy H. Gómez Villegas
// Version     :
// Copyright   : Use this code only for academic purposes
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int uniform_distribution(int rangeLow, int rangeHigh) {
    double myRand = rand()/(1.0 + RAND_MAX);
    int range = rangeHigh - rangeLow + 1;
    int myRand_scaled = (myRand * range) + rangeLow;
    return myRand_scaled;
}


int createVector(int *A, int longitud){
	int i;
	for (i = 0; i < longitud; ++i) {
		A[i] = uniform_distribution(0,3000000);
	}
	return 0;
}

int crearArchivoVector(int *A,int longitud, char *nombreArchivo) {
    FILE *pFile;
    int p;
    pFile = fopen(nombreArchivo, "w");
    for (p = 0; p < longitud; ++p) {
        fprintf(pFile, "%d \n",A[p]);
    }

    fclose(pFile);
    return EXIT_SUCCESS;
}


int main(int argc, char **argv) {
	int *A, cantidadDatos;
	srand (time(NULL));

	if (argc != 3){
		printf("Uso: ./numberGenerator nombreArchivo cantidadDatos\n");
		return EXIT_FAILURE;
	}
	cantidadDatos = atoi(argv[2]);
	A = (int*) malloc(sizeof(int)*cantidadDatos);
	createVector(A,cantidadDatos);
	crearArchivoVector(A,cantidadDatos,argv[1]);
	return 0;
}
