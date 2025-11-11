#ifndef JOGO_H
#define JOGO_H

typedef struct {
    char nome[50];
    char simbolo;
    int vitorias;
} Jogador;

void menuPrincipal(int tamanho);
void jogar(int tamanho, int modoComputador);

#endif
