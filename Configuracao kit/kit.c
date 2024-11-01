#include "kit.h"
#include <stdio.h>
#include <stdlib.h>

Caixa *criaCaixa(int largura, int altura) {
    Caixa *caixa = (Caixa *) malloc(sizeof(Caixa));
    if (caixa != NULL) {
        caixa->largura = largura;
        caixa->altura = altura;
        caixa->matriz = (Explosivo **) malloc(largura * altura * sizeof(Explosivo *));
        for (int i = 0; i < largura * altura; i++) {
            caixa->matriz[i] = NULL;
        }
    }
    return caixa;
}

int destroiCaixa(Caixa *caixa) {
    if (caixa != NULL) {
        free(caixa->matriz);
        free(caixa);
        return 0;
    }
    return -1;
}

int verificarAdjacencia(Caixa *caixa) {
    for (int i = 0; i < caixa->largura; i++) {
        for (int j = 0; j < caixa->altura; j++) {
            Explosivo *explosivo = caixa->matriz[i * caixa->largura + j];
            if (explosivo != NULL) {
                if (i > 0 && caixa->matriz[(i - 1) * caixa->largura + j] &&
                    caixa->matriz[(i - 1) * caixa->largura + j]->cor == explosivo->cor) return -1;
                if (j > 0 && caixa->matriz[i * caixa->largura + (j - 1)] &&
                    caixa->matriz[i * caixa->largura + (j - 1)]->cor == explosivo->cor) return -1;
            }
        }
    }
    return 0;
}

int colocaExplosivo(Caixa *caixa, Explosivo config) {
    for (int i = config.x_inicial; i <= config.x_final; i++) {
        for (int j = config.y_inicial; j <= config.y_final; j++) {
            int idx = i * caixa->largura + j;
            caixa->matriz[idx] = &config;
        }
    }
    return 0;
}

int verificaValidade(Explosivo explosivos[], int num_explosivos) {
    int total_area = 0;
    for (int i = 0; i < num_explosivos; i++) {
        int area = (explosivos[i].x_final - explosivos[i].x_inicial + 1) * (explosivos[i].y_final - explosivos[i].y_inicial + 1);
        total_area += area;
    }
    return total_area <= TAMANHO_CAIXA * TAMANHO_CAIXA;
}