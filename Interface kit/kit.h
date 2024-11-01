#ifndef KIT_H
#define KIT_H

#define TAMANHO_CAIXA 6
#define MAX_EXPLOSIVO 30

typedef struct{
    char cor[3];
    int quantidade;
    int tamanho;
    int x_inicial, y_inicial;
    int x_final, y_final;
}Explosivo;

typedef struct{
    Explosivo **matriz;
    int largura, altura;
}Caixa;

int lerComposicao(char *arquivoComposicao, Explosivo explosivos[]);

int lerConfiguracao(char *arquivoConfiguracao, Explosivo explosivos[]);

Caixa *criaCaixa(int largura, int altura);

int destroiCaixa(Caixa *caixa);

int verificarAdjacencia(Caixa *caixa);

int colocaExplosivo(Caixa *caixa, Explosivo config);

int verificaValidade(Explosivo explosivos[], int num_explosivos);

#endif
