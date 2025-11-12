/*
Documentação
Função: Executa o programa principal do Jogo da Velha.
Objetivo: Iniciar o jogo, exibir o menu e chamar as funções principais.
Entradas: Escolha do jogador (modo de jogo, sair, etc.).
Processo: Mostra o menu, recebe opções e executa as ações correspondentes.
Saída: Interface do jogo ou resultados conforme a opção escolhida.
*/

#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main() {
    int tamanho = 3; // pode ser 3x3 ou 4x4 se quiser mudar
    menuPrincipal(tamanho);
    return 0;
}
