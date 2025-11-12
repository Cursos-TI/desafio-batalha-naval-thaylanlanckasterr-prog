#include <stdio.h>

#define TAM_TABULEIRO 10  // tamanho fixo do tabuleiro
#define TAM_NAVIO 3       // tamanho fixo dos navios (3 posições)
#define AGUA 0            // valor que representa água
#define NAVIO 3           // valor que representa uma parte do navio

int main() {
    // ============================================================
    // 1. DECLARAÇÃO E INICIALIZAÇÃO DO TABULEIRO
    // ============================================================
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todas as posições com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ============================================================
    // 2. DEFINIÇÃO DAS COORDENADAS DOS 4 NAVIOS
    // ============================================================
    // Dois navios normais (horizontal e vertical)
    int linhaInicial1 = 2, colunaInicial1 = 3; // horizontal
    int linhaInicial2 = 5, colunaInicial2 = 7; // vertical

    // Dois navios diagonais
    int linhaInicial3 = 0, colunaInicial3 = 0; // diagonal ↘ (aumenta linha e coluna)
    int linhaInicial4 = 9, colunaInicial4 = 6; // diagonal ↙ (diminui coluna, aumenta linha)

    // ============================================================
    // 3. FUNÇÃO AUXILIAR: VERIFICAÇÃO DE SOBREPOSIÇÃO
    // ============================================================
    // (verifica antes de posicionar cada navio)
    int sobreposicao = 0;

    // ============================================================
    // 4. POSICIONAMENTO DOS DOIS NAVIOS NORMAIS
    // ============================================================

    // ---- Navio 1: Horizontal (linha constante, colunas crescentes)
    if (colunaInicial1 + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaInicial1][colunaInicial1 + i] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaInicial1][colunaInicial1 + i] = NAVIO;
        } else {
            printf("Erro: sobreposição detectada no navio 1 (horizontal).\n");
            return 1;
        }
    } else {
        printf("Erro: navio 1 (horizontal) fora dos limites do tabuleiro.\n");
        return 1;
    }

    // ---- Navio 2: Vertical (coluna constante, linhas crescentes)
    sobreposicao = 0;
    if (linhaInicial2 + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaInicial2 + i][colunaInicial2] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaInicial2 + i][colunaInicial2] = NAVIO;
        } else {
            printf("Erro: sobreposição detectada no navio 2 (vertical).\n");
            return 1;
        }
    } else {
        printf("Erro: navio 2 (vertical) fora dos limites do tabuleiro.\n");
        return 1;
    }

    // ============================================================
    // 5. POSICIONAMENTO DOS DOIS NAVIOS DIAGONAIS
    // ============================================================

    // ---- Navio 3: Diagonal ↘ (aumenta linha e coluna simultaneamente)
    sobreposicao = 0;
    if (linhaInicial3 + TAM_NAVIO <= TAM_TABULEIRO &&
        colunaInicial3 + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaInicial3 + i][colunaInicial3 + i] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaInicial3 + i][colunaInicial3 + i] = NAVIO;
        } else {
            printf("Erro: sobreposição detectada no navio 3 (diagonal ↘).\n");
            return 1;
        }
    } else {
        printf("Erro: navio 3 (diagonal ↘) fora dos limites.\n");
        return 1;
    }

    // ---- Navio 4: Diagonal ↙ (aumenta linha, diminui coluna)
    sobreposicao = 0;
    if (linhaInicial4 + TAM_NAVIO <= TAM_TABULEIRO &&
        colunaInicial4 - (TAM_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaInicial4 + i][colunaInicial4 - i] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaInicial4 + i][colunaInicial4 - i] = NAVIO;
        } else {
            printf("Erro: sobreposição detectada no navio 4 (diagonal ↙).\n");
            return 1;
        }
    } else {
        printf("Erro: navio 4 (diagonal ↙) fora dos limites.\n");
        return 1;
    }

    // ============================================================
    // 6. EXIBIÇÃO DO TABULEIRO
    // ============================================================
    printf("\n========== TABULEIRO BATALHA NAVAL ==========\n\n");
    printf("   ");
    for (int c = 0; c < TAM_TABULEIRO; c++)
        printf("%2d ", c);
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
