#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem){
    scanf("%d", ordem);
}

//manter como especificado
double **alocaMatriz(double **M, int ordem){
    M = (double**) malloc(ordem*sizeof(double*));
    if (M == NULL) {
        printf("Sem memoria");
        exit(1);
    }
    for (int i = 0; i < ordem; i++) {
        M[i] = (double*) malloc(ordem*sizeof(double));
        if (M[i] == NULL) {
            printf("Sem memoria");
            exit(1);
        }
    } 
    return M;
}

//manter como especificado
double **desalocaMatriz(double **M, int ordem){
    for (int i = 0; i < ordem; i++) {
        free(M[i]);
    }
    free(M);
    return NULL;
}

//manter como especificado
void lerOperacao(char *operacao){
    scanf(" %c", operacao);
}

void lerMatriz(double **M, int ordem){
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            scanf("%lf", &M[i][j]);
        }
    }
}

double somaMatriz(double **M, int ordem){
    double soma = 0;
    int ajuda = 0;
    for (int k = 0; k < ordem; k++) {
        for (int l = k+1; l < (ordem-1) - ajuda; l++) {
            soma += M[k][l]; 
        }
        ajuda++;
    }
    return soma;
}

double media(double resultado, int ordem){
    int base = ordem;
    int quantidade = 0;
    while (base != 2) {
        base -= 2;
        quantidade += base;
    }
    return resultado/quantidade;
}

void printResultado(double resultado){
    printf("%.1lf", resultado);
}
