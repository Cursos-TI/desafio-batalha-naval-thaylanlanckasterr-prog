#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5   // tamanho fixo para as habilidades (5x5)
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5       // valor para representar área afetada pela habilidade

int main() {
    // ============================================================
    // 1. CRIAÇÃO DO TABULEIRO
    // ============================================================
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ============================================================
    // 2. POSICIONAMENTO DE NAVIOS (mesmo conceito dos níveis anteriores)
    // ============================================================
    int linhaInicial1 = 2, colunaInicial1 = 3; // horizontal
    int linhaInicial2 = 5, colunaInicial2 = 7; // vertical
    int linhaInicial3 = 0, colunaInicial3 = 0; // diagonal ↘
    int linhaInicial4 = 9, colunaInicial4 = 6; // diagonal ↙
    int TAM_NAVIO = 3;

    // Navio 1 (horizontal)
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaInicial1][colunaInicial1 + i] = NAVIO;

    // Navio 2 (vertical)
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaInicial2 + i][colunaInicial2] = NAVIO;

    // Navio 3 (diagonal ↘)
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaInicial3 + i][colunaInicial3 + i] = NAVIO;

    // Navio 4 (diagonal ↙)
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaInicial4 - i][colunaInicial4 + i] = NAVIO;

    // ============================================================
    // 3. MATRIZES DE HABILIDADE (Cone, Cruz, Octaedro)
    // ============================================================
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    int centro = TAM_HABILIDADE / 2;

    // -------- Habilidade em Cone (forma de triângulo apontando para baixo)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= centro - i && j <= centro + i) // expande horizontalmente conforme a linha desce
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // -------- Habilidade em Cruz (linhas e colunas centrais)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // -------- Habilidade em Octaedro (losango)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ============================================================
    // 4. DEFINIÇÃO DAS ORIGENS DAS HABILIDADES NO TABULEIRO
    // ============================================================
    int origemConeLinha = 1, origemConeColuna = 1;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaLinha = 7, origemOctaColuna = 3;

    // ============================================================
    // 5. FUNÇÃO DE SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO
    // ============================================================
    // Centramos a habilidade no ponto de origem e validamos os limites.
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Cone
            int lin = origemConeLinha - centro + i;
            int col = origemConeColuna - centro + j;
            if (cone[i][j] == 1 &&
                lin >= 0 && lin < TAM_TABULEIRO &&
                col >= 0 && col < TAM_TABULEIRO) {
                if (tabuleiro[lin][col] == AGUA)
                    tabuleiro[lin][col] = HABILIDADE;
            }

            // Cruz
            lin = origemCruzLinha - centro + i;
            col = origemCruzColuna - centro + j;
            if (cruz[i][j] == 1 &&
                lin >= 0 && lin < TAM_TABULEIRO &&
                col >= 0 && col < TAM_TABULEIRO) {
                if (tabuleiro[lin][col] == AGUA)
                    tabuleiro[lin][col] = HABILIDADE;
            }

            // Octaedro
            lin = origemOctaLinha - centro + i;
            col = origemOctaColuna - centro + j;
            if (octaedro[i][j] == 1 &&
                lin >= 0 && lin < TAM_TABULEIRO &&
                col >= 0 && col < TAM_TABULEIRO) {
                if (tabuleiro[lin][col] == AGUA)
                    tabuleiro[lin][col] = HABILIDADE;
            }
        }
    }

    // ============================================================
    // 6. EXIBIÇÃO DO TABULEIRO FINAL
    // ============================================================
    printf("\n=========== TABULEIRO FINAL - BATALHA NAVAL ===========\n\n");
    printf("   ");
    for (int c = 0; c < TAM_TABULEIRO; c++)
        printf("%2d ", c);
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf(" . ");  // Água
            else if (tabuleiro[i][j] == NAVIO)
                printf(" N ");  // Navio
            else if (tabuleiro[i][j] == HABILIDADE)
                printf(" * ");  // Habilidade
        }
        printf("\n");
    }

    printf("\nLegenda:\n");
    printf(" . = Água (0)\n N = Navio (3)\n * = Área de Habilidade (5)\n");

    return 0;
}
