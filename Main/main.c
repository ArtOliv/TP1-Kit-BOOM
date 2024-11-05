#include "../Interface_kit/kit.h"

int main(int argc, char *argv[]){
    FILE *arquivoComposicao = NULL; 
    FILE *arquivoConfiguracao = NULL;
    
    Caixa *caixa = criaCaixa();
    
    lerArquivos(argc, argv, &arquivoComposicao, &arquivoConfiguracao);
    
    int total_explosivos = lerComposicao(arquivoComposicao);
    
    Explosivo *listaExplosivos = criaListaExplosivos(total_explosivos);
    
    lerConfiguracao(arquivoConfiguracao, caixa, listaExplosivos, total_explosivos);
    
    verificaValidade(caixa);

    fclose(arquivoComposicao);
    fclose(arquivoConfiguracao);

    destroiLista(listaExplosivos);
    destroiCaixa(caixa);

    return 0;
}