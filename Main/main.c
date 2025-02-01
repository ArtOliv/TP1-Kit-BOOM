#include "../Interface_kit/kit.h"

int main(int argc, char *argv[]){
    FILE *arquivoComposicao = NULL; 
    FILE *arquivoConfiguracao = NULL;
    
    lerArquivos(argc, argv, &arquivoComposicao, &arquivoConfiguracao);

    int total_explosivos = lerComposicao(arquivoComposicao);
    
    int index = 1, eof = 0;
    while(eof != EOF){
        Caixa *caixa = criaCaixa();
        Explosivo *listaExplosivos = criaListaExplosivos(total_explosivos);
        
        eof = lerConfiguracao(arquivoConfiguracao, caixa, listaExplosivos, total_explosivos);
        
        verificaValidade(caixa, index);

        destroiLista(listaExplosivos);
        destroiCaixa(caixa);

        index++;
    }
    
    fclose(arquivoComposicao);
    fclose(arquivoConfiguracao);
    return 0;
}