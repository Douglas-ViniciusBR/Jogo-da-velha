# 🧩 Jogo da Velha (Linguagem C)

Projeto acadêmico desenvolvido para a disciplina **Técnicas de Desenvolvimento de Algoritmos (TDA)** – 2025.2  
**Professor:** Wallace  

---

## 🎯 Objetivo

Implementar um **jogo da velha interativo** utilizando a linguagem **C**, explorando os principais fundamentos da programação estruturada, tais como:
- Estruturas de decisão e repetição  
- Modularização de código e uso de funções  
- Manipulação de arquivos texto (`ranking.txt`)  
- Matrizes bidimensionais e alocação dinâmica  
- Uso de `struct` para representar jogadores e ranking  

---

## 🕹️ Funcionalidades Principais

| Funcionalidade | Descrição |
|----------------|------------|
| 👥 **Modo Jogador vs Jogador** | Dois usuários alternam jogadas manualmente |
| 🤖 **Modo Jogador vs Computador** | Jogadas aleatórias do computador |
| 🏆 **Sistema de Ranking Automático** | Registra e acumula vitórias por jogador |
| 💾 **Persistência em Arquivo** | Armazena dados em `ranking.txt` de forma permanente |
| 📊 **Ranking Ordenado** | Mostra os 5 melhores jogadores com mais vitórias |
| 🧱 **Interface de Terminal** | Menu limpo e interativo, com navegação intuitiva |

---

## ⚙️ Como Compilar e Executar

### 💡 Pré-requisitos
- Compilador **GCC** instalado (recomendado: [MinGW](http://www.mingw.org/))
- Editor de código como **Visual Studio Code** (com extensão C/C++ da Microsoft)
- Sistema operacional Windows (mas também roda em Linux com pequenas alterações)

### 💻 Compilação
No terminal (cmd, PowerShell ou Git Bash), execute:
```bash
gcc main.c jogo.c utils.c ranking.c -o output/jogo.exe -Wall -Wextra -g3 -mconsole

▶️ Execução

Depois da compilação:

output\jogo.exe

🧱 Estrutura do Projeto
📦 Jogo-da-velha
 ┣ 📜 main.c              → Função principal e inicialização do jogo
 ┣ 📜 jogo.c              → Lógica principal do jogo (menu, turnos, vitórias)
 ┣ 📜 jogo.h              → Cabeçalhos do módulo de jogo
 ┣ 📜 utils.c             → Manipulação do tabuleiro e regras de jogadas
 ┣ 📜 utils.h             → Cabeçalhos de funções utilitárias
 ┣ 📜 ranking.c           → Sistema de ranking (leitura e gravação)
 ┣ 📜 ranking.h           → Estrutura e protótipos do ranking
 ┣ 📜 README.md           → Documentação do projeto
 ┣ 📜 .gitignore          → Arquivos ignorados pelo Git
 ┗ 📂 output/             → Diretório de saída do executável

📋 Regras do Jogo

Cada jogador escolhe um nome e é atribuído um símbolo:

Jogador 1 → X

Jogador 2 ou Computador → O

Os jogadores se alternam, informando linha e coluna (0, 1 ou 2).

O jogo termina quando:

Um jogador completa uma linha, coluna ou diagonal

Ou quando todas as casas estão preenchidas (empate)

O vencedor é salvo automaticamente no arquivo de ranking.

Equipe de Desenvolvimento:

Matheus Gabriel

Bruno Sena

Pedro Leão

Douglas Vinícius

Leonardo Henrique de Oliveira Silva
