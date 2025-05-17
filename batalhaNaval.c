#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

// Inicializa o tabuleiro com zeros (representando água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Verifica se é possível posicionar um navio no tabuleiro
int podePosicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha, c = coluna;
        switch (direcao) {
            case 0: l = linha + i; break;             // Vertical
            case 1: c = coluna + i; break;            // Horizontal
            case 2: l = linha + i; c = coluna + i; break; // Diagonal principal (\)
            case 3: l = linha + i; c = coluna - i; break; // Diagonal secundária (/)
        }
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO || tabuleiro[l][c] != 0) {
            return 0;
        }
    }
    return 1;
}

// Posiciona um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha, c = coluna;
        switch (direcao) {
            case 0: l = linha + i; break;             // Vertical
            case 1: c = coluna + i; break;            // Horizontal
            case 2: l = linha + i; c = coluna + i; break; // Diagonal principal (\)
            case 3: l = linha + i; c = coluna - i; break; // Diagonal secundária (/)
        }
        tabuleiro[l][c] = NAVIO;
    }
}

// Exibe o tabuleiro formatado com letras e números
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("       TABULEIRO BATALHA NAVAL\n\n");
    printf("    ");
    for (char letra = 'A'; letra < 'A' + TAMANHO; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Define as posições iniciais e direções dos navios
    int navios[4][3] = {
        {2, 4, 1}, // Horizontal
        {0, 0, 0}, // Vertical
        {3, 1, 2}, // Diagonal principal (\)
        {1, 8, 3}  // Diagonal secundária (/)
    };

    // Tenta posicionar cada navio se possível
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int direcao = navios[i][2];

        if (podePosicionarNavio(tabuleiro, linha, coluna, NAVIO, direcao)) {
            posicionarNavio(tabuleiro, linha, coluna, NAVIO, direcao);
        } else {
            printf("Erro ao posicionar navio %d!\n", i + 1);
        }
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
