#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define TAM_TABULEIRO 10  // tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3       // tamanho fixo dos navios (3 posições)
#define AGUA 0            // valor que representa água
#define NAVIO 3           // valor que representa uma parte do navio

int main() {
    // Nível Novato - Posicionamento dos Navios
    // ============================================================
    // 1. DECLARAÇÃO DO TABULEIRO E INICIALIZAÇÃO
    // ============================================================
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todo o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ============================================================
    // 2. DEFINIÇÃO DAS COORDENADAS INICIAIS DOS NAVIOS
    // ============================================================
    // As coordenadas são definidas diretamente no código.
    // Cada navio terá 3 posições.
    // O primeiro será horizontal e o segundo vertical.

    int linhaInicialNavio1 = 2;  // linha inicial do navio 1 (horizontal)
    int colunaInicialNavio1 = 4; // coluna inicial do navio 1 (horizontal)

    int linhaInicialNavio2 = 5;  // linha inicial do navio 2 (vertical)
    int colunaInicialNavio2 = 7; // coluna inicial do navio 2 (vertical)

    // ============================================================
    // 3. VALIDAÇÃO DAS COORDENADAS DOS NAVIOS
    // ============================================================
    // Verifica se o navio 1 cabe horizontalmente dentro dos limites
    if (colunaInicialNavio1 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: o navio 1 (horizontal) ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    // Verifica se o navio 2 cabe verticalmente dentro dos limites
    if (linhaInicialNavio2 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: o navio 2 (vertical) ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    // ============================================================
    // 4. POSICIONAMENTO DOS NAVIOS NO TABULEIRO
    // ============================================================
    // Coloca o navio 1 (horizontal)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaInicialNavio1][colunaInicialNavio1 + i] = NAVIO;
    }

    // Coloca o navio 2 (vertical)
    // Antes, verifica se há sobreposição com o navio 1
    int sobreposicao = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaInicialNavio2 + i][colunaInicialNavio2] == NAVIO) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios se sobrepõem! Escolha outras coordenadas.\n");
        return 1;
    }

    // Se não houver sobreposição, posiciona o segundo navio
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaInicialNavio2 + i][colunaInicialNavio2] = NAVIO;
    }

    // ============================================================
    // 5. EXIBIÇÃO DO TABULEIRO NO CONSOLE
    // ============================================================
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");
    printf("   ");
    for (int c = 0; c < TAM_TABULEIRO; c++) {
        printf("%2d ", c);  // imprime o número das colunas
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);  // imprime o número da linha
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
