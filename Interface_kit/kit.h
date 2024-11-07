#ifndef KIT_H
#define KIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct{
    char cor[3];
    int tamanho;
    int x_inicial, y_inicial;
    int x_final, y_final;
}Explosivo;

typedef struct{
    Explosivo ***matriz;
}Caixa;

int lerComposicao(FILE *arquivoComposicao);

int lerConfiguracao(FILE *arquivoConfiguracao, Caixa *caixa, Explosivo *listaExplosivos, int num_explosivos);

int lerArquivos(int argc, char *argv[], FILE **arquivoComposicao, FILE **arquivoConfiguracao);

int verificaValidade(Caixa *caixa);

Caixa *criaCaixa();

int destroiCaixa(Caixa *caixa);

Explosivo *criaListaExplosivos(int num_explosivos);

int destroiLista(Explosivo *listaExplosivos);

int verificarAdjacencia(Caixa *caixa);

int colocaExplosivo(Caixa *caixa, Explosivo config);

#endif
