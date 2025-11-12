/*
Documentação
Função: Declara funções e constantes auxiliares.
Objetivo: Permitir o uso das funções utilitárias em outros módulos.
Conteúdo: Protótipos e definições relacionadas ao tabuleiro.
*/

#ifndef UTILS_H
#define UTILS_H

char **criarTabuleiro(int tamanho);
void liberarTabuleiro(char **tab, int tamanho);
void mostrarTabuleiro(char **tab, int tamanho);
int jogadaValida(char **tab, int linha, int coluna, int tamanho);
int verificarVitoria(char **tab, int tamanho);
int verificarEmpate(char **tab, int tamanho);

#endif
