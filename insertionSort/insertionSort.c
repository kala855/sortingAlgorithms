#include<stdio.h>

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


int main(){
	int vector[] = {4,5,2,3,1};
	insertionSort(vector, 5);
	printVector(vector,5);
	return 0;
}