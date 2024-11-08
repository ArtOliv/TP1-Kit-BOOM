#include "../Interface_kit/kit.h"

struct rusage usage;
struct timeval start, end;

int main(int argc, char *argv[]){
    FILE *arquivoComposicao = NULL; 
    FILE *arquivoConfiguracao = NULL;

    gettimeofday(&start, NULL);
    
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

    gettimeofday(&end, NULL);
    long segundos = end.tv_sec - start.tv_sec;
    long microsec = end.tv_usec - start.tv_usec;
    if(microsec < 0){
        microsec += 1000000;
    }

    getrusage(RUSAGE_SELF, &usage);

    printf("\nTempo de usuário do processador: %ld.%06ld segundos.\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("Tempo de sistema do processador: %ld.%06ld segundos.\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("Tempo atual do programa: %ld.%06ld segundos.\n", segundos, microsec);

    return 0;
}