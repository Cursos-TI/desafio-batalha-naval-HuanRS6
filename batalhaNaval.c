#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO_TABULEIRO 10
// Tamanho fixo dos navios
#define TAMANHO_NAVIO 3

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Matriz representando o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Vetores representando os navios (conteúdo irrelevante — usamos apenas para indicar tamanho)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios (linha, coluna)
    int linhaH = 2, colunaH = 4;  // navio horizontal começando na posição (2,4)
    int linhaV = 5, colunaV = 7;  // navio vertical começando na posição (5,7)

    // Validação do navio horizontal
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se há espaço livre (sem sobreposição)
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        } else {
            printf("Erro: Sobreposição detectada ao posicionar o navio horizontal.\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Validação do navio vertical
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se há espaço livre (sem sobreposição)
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        } else {
            printf("Erro: Sobreposição detectada ao posicionar o navio vertical.\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // Imprime o tabuleiro no console
    imprimirTabuleiro(tabuleiro);

    return 0;
}