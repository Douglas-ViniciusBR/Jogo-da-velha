/*
Documentação
Função: Declara funções e estruturas do módulo de jogo.
Objetivo: Compartilhar funções do jogo.c com outros arquivos.
Conteúdo: Protótipos de funções e definições relacionadas ao jogo.
*/

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
