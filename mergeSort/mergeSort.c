#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int merge(int *A, int p, int q, int r)
{
	int *L,*R;
	int n1,n2,i,j,k;
	n1 = q - p + 1;
	n2 = r - q;
	L = malloc(sizeof(int)*(n1 + 2));
	R = malloc(sizeof(int)*(n2 + 2));

	for (i = 1; i <= n1; ++i)
		L[i] = A[p+i-1];
	for (j = 1; j <= n2; ++j)
		R[j] = A[q+j];

	L[n1+1] = INT_MAX;
	R[n2+1] = INT_MAX;

	i = 1;
	j = 1;

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

int mergeSort(int *A, int p, int r){
	int q;
	if(p<r){
		q = (int)((p+r)/2);
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);
	}
	return 0;
}

int printVector(int *vector, int longitud){
	int i;
	for (i = 0; i < longitud; ++i)
		printf("%d ", vector[i]);
	printf("\n");
	return 0;
}

int main(){
	int vector[] = {6,4,5,2,3,1};
	mergeSort(vector, 1,6);
	printVector(vector,6);
	return 0;
}