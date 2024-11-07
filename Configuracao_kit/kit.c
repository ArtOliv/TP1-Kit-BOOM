#include "../Interface_kit/kit.h"

Caixa *criaCaixa(){
    Caixa *caixa = (Caixa*) malloc (sizeof(Caixa));
    if(caixa != NULL){
        caixa->matriz = (Explosivo***) malloc (6 * sizeof(Explosivo**));
        if(caixa->matriz == NULL){
            free(caixa);
            return NULL;
        }

        for(int i = 0; i < 6; i++){
            caixa->matriz[i] = (Explosivo**) malloc (6 * sizeof(Explosivo*));
            if(caixa->matriz[i] == NULL){
                for(int j = 0; j < i; j++){
                    free(caixa->matriz[j]);
                }
                free(caixa->matriz);
                free(caixa);
                return NULL;
            }
            
            for(int j = 0; j < 6; j++){
                caixa->matriz[i][j] = NULL;
            }
        } 
    }
    return caixa;
}

int destroiCaixa(Caixa *caixa){
    if(caixa != NULL){
        for(int i = 0; i < 6; i++){
            free(caixa->matriz[i]);
        }
        free(caixa->matriz);
        free(caixa);
        return 1;
    }
    return 0;
}

Explosivo *criaListaExplosivos(int num_explosivos){
    Explosivo *listaExplosivos = (Explosivo*) malloc (num_explosivos * sizeof(Explosivo));
    if(listaExplosivos == NULL){
        return NULL;
    }
    return listaExplosivos;
}

int destroiLista(Explosivo *listaExplosivos){
    free(listaExplosivos);
    return 0;
}

int colocaExplosivo(Caixa *caixa, Explosivo config){
    int x_inicial = config.x_inicial - 1;
    int y_inicial = config.y_inicial - 1;
    int x_final = config.x_final - 1;
    int y_final = config.y_final - 1;

    Explosivo *novo_explosivo = (Explosivo*) malloc (sizeof(Explosivo));

    if(novo_explosivo != NULL){
        *novo_explosivo = config;
        for(int i = x_inicial; i <= x_final; i++){
            for(int j = y_inicial; j <= y_final; j++){
                caixa->matriz[i][j] = novo_explosivo;
            }
        }
    }
    return 0;
}

int verificarAdjacencia(Caixa *caixa){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            Explosivo *explosivo_atual = caixa->matriz[i][j];
            if(explosivo_atual != NULL){
                if(i > 0){
                    Explosivo *explosivo_acima = caixa->matriz[i - 1][j];
                    if(explosivo_acima != NULL && strcmp(explosivo_acima->cor, explosivo_atual->cor) == 0 && !(explosivo_acima->x_inicial == explosivo_atual->x_inicial && explosivo_acima->y_inicial == explosivo_atual->y_inicial)){
                        return 1;
                    }
                }
                
                if(j > 0){   
                    Explosivo *explosivo_esquerda = caixa->matriz[i][j - 1];
                    if(explosivo_esquerda != NULL && strcmp(explosivo_esquerda->cor, explosivo_atual->cor) == 0 && !(explosivo_esquerda->x_inicial == explosivo_atual->x_inicial && explosivo_esquerda->y_inicial == explosivo_atual->y_inicial)){
                        return 1;
                    }
                }
                
                if(i < 5){    
                    Explosivo *explosivo_abaixo = caixa->matriz[i + 1][j];
                    if(explosivo_abaixo != NULL && strcmp(explosivo_abaixo->cor, explosivo_atual->cor) == 0 && !(explosivo_abaixo->x_inicial == explosivo_atual->x_inicial && explosivo_abaixo->y_inicial == explosivo_atual->y_inicial)){
                        return 1;
                    }
                }
                
                if(j < 5){  
                    Explosivo *explosivo_direita = caixa->matriz[i][j + 1]; 
                    if(explosivo_direita != NULL && strcmp(explosivo_direita->cor, explosivo_atual->cor) == 0 && !(explosivo_direita->x_inicial == explosivo_atual->x_inicial && explosivo_direita->y_inicial == explosivo_atual->y_inicial)){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}