#include "../Interface_kit/kit.h"

int lerComposicao(FILE *arquivoComposicao){
    int total_explosivos = 0;
    int quantidade, tamanho;
    char cor[3];
    while(fscanf(arquivoComposicao, "%d %1d%2s", &quantidade, &tamanho, cor) == 3){
        total_explosivos += quantidade;
    }
    return total_explosivos;
}

int lerConfiguracao(FILE *arquivoConfiguracao, Caixa *caixa, Explosivo *listaExplosivos, int num_explosivos){
    for(int i = 0; i < num_explosivos; i++){
        fscanf(arquivoConfiguracao, "%d %d %d %d %1d%2s", &listaExplosivos[i].x_inicial, &listaExplosivos[i].y_inicial, &listaExplosivos[i].x_final, &listaExplosivos[i].y_final, &listaExplosivos[i].tamanho, listaExplosivos[i].cor);
    }

    for(int i = 0; i < num_explosivos; i++){
        colocaExplosivo(caixa, listaExplosivos[i]);
    }
    return 1;
}

int lerArquivos(int argc, char *argv[], FILE **arquivoComposicao, FILE **arquivoConfiguracao){
    int opt;
    while((opt = getopt(argc, argv, "a:b:")) != -1){
        if(opt == 'a'){
            *arquivoComposicao = fopen(optarg, "r");
            if(*arquivoComposicao == NULL){
                printf("Erro ao ler o arquivo de composição!\n");
                return 1;
            }
        } else if(opt == 'b'){
            *arquivoConfiguracao = fopen(optarg, "r");
            if(*arquivoConfiguracao == NULL){
                printf("Erro ao ler o arquivo de configuração!\n");
                return 1;
            }
        } else {
            printf("Arquivos inválidos!\n");
            return 1;
        }
    }
    return 0;
}

int verificaValidade(Caixa *caixa){
    int validade = verificarAdjacencia(caixa);
    if(validade == 0){
        printf("A configuração dos explosivos na caixa é válida!\n");
    } else {
        printf("A configuração dos explosivos na caixa é inválida!\n");
    }
    return 0;
}