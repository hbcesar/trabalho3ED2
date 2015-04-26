#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "TADfuncoesComuns.h"


float menor (float* vetor, int n, int* indice_menor){
	float menor = FLT_MAX;
	int i;
	for  (i=0;i<n;i++){
		if (vetor[i] < menor){
			menor = vetor[i];
			(*indice_menor) = i;
		}
	}

	return menor;
}

float** copiarMatriz(int n, float** matriz){
	int i, j;
	float** novo = alocarMatriz(n);

	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			novo[i][j] = matriz[i][j];
		}
	}

	return novo;
}


void nearestNeighbor(int primeira_cidade, int n, float** matriz){
	float** matriz_aux;
	float* vetor;
	int* caminho = (int*)malloc(n*sizeof(int));
	int i, j, indice_menor = primeira_cidade-1;
	float soma = 0, aux;

	matriz_aux = copiarMatriz(n, matriz);

	for (i=0;i<n-1;i++){
		for (j=0;j<n;j++){
			matriz_aux[j][indice_menor] = FLT_MAX;
		}

		vetor = matriz_aux[indice_menor];
		aux = menor(vetor, n, &indice_menor); //acha o menor valor da linha da matriz
		soma = soma + aux; // soma esses valores

		caminho[i]=indice_menor;
	}

	soma = soma + matriz[indice_menor][primeira_cidade-1];

	printf("%.2f \n", soma);

}
