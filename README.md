# 🧩 Jogo da Velha (C Language Project)

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

