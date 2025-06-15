#include <stdio.h>

// Define matriz 10x10 representando o tabuleiro de Batalha Naval
int tabuleiro[10][10]; // 0 = água, 3 = navio
int escolha, l, c, opcao = 0; // Variáveis para interações

void inicializar_tabuleiro() {
    // Inicializa o tabuleiro com "0" (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void mostrar_tabuleiro() {
    printf("Tabuleiro de batalha naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe matriz com números
        }
        printf("\n");
    }
}

int verificar_espaco(int linha, int coluna, int direcao) {
    // Verifica se há espaço disponível para o navio, evitando sobreposição
    for (int i = 0; i < 3; i++) { // Navios têm tamanho 3
        if (direcao == 1 && (linha + i >= 10 || tabuleiro[linha + i][coluna] != 0)) return 0; // Vertical
        if (direcao == 2 && (coluna + i >= 10 || tabuleiro[linha][coluna + i] != 0)) return 0; // Horizontal
        if (direcao == 3 && (linha + i >= 10 || coluna + i >= 10 || tabuleiro[linha + i][coluna + i] != 0)) return 0; // Diagonal
    }
    return 1;
}

void adicionar_navio() {
    for (int n = 0; n < 4; n++) { // Adiciona quatro navios
        printf("Navio %d - Escolha o posicionamento [1] Vertical, [2] Horizontal, [3] Diagonal:\n", n + 1);
        scanf("%d", &escolha);

        printf("Digite a linha (0 a 9) para posicionar:\n");
        scanf("%d", &l);
        printf("Digite a coluna (0 a 9) para posicionar:\n");
        scanf("%d", &c);

        if (l >= 0 && l < 10 && c >= 0 && c < 10 && verificar_espaco(l, c, escolha)) {
            for (int i = 0; i < 3; i++) {
                if (escolha == 1) tabuleiro[l + i][c] = 3; // Vertical
                else if (escolha == 2) tabuleiro[l][c + i] = 3; // Horizontal
                else if (escolha == 3) tabuleiro[l + i][c + i] = 3; // Diagonal
            }
            printf("Navio %d adicionado!\n", n + 1);
        } else {
            printf("Posição inválida ou espaço ocupado! Tente novamente.\n");
            n--; // Repetir tentativa
        }
    }
}

int main() {
    inicializar_tabuleiro();

    printf("Batalha Naval - Nível Aventureiro!\n");
    do {
        printf("\n[1] Mostrar Tabuleiro\n");
        printf("[2] Adicionar Navios\n");
        printf("[3] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrar_tabuleiro();
                break;
            case 2:
                adicionar_navio();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}


//int main() {
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10 (Ex: int tabuleiro[10][10];)
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.