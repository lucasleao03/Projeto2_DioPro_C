#include <stdio.h>

char tabuleiro[3][3];
char jogadorAtual = 'X';

void inicializarTabuleiro()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) tabuleiro[i][j] = ' ';
    }
    
}

void imprimirTabuleiro()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int jogadaValida(int linha, int coluna) 
{
    return linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ';
}

int verificarVitoria() 
{
    for (int i = 0; i < 3; i++) 
    {
        if (tabuleiro[i][0] == jogadorAtual && tabuleiro[i][1] == jogadorAtual && tabuleiro[i][2] == jogadorAtual) return 1;
        if (tabuleiro[0][i] == jogadorAtual && tabuleiro[1][i] == jogadorAtual && tabuleiro[2][i] == jogadorAtual) return 1;
    }
    if (tabuleiro[0][0] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][2] == jogadorAtual) return 1;
    if (tabuleiro[0][2] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][0] == jogadorAtual) return 1;
    return 0;
}

int tabuleiroCheio() 
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) if (tabuleiro[i][j] == ' ') return 0;
    }
    return 1;
}

void trocarJogador() 
{
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

int main() 
{
    int linha, coluna;
    inicializarTabuleiro();

    while (1) 
    {
        imprimirTabuleiro();
        printf("Jogador %c, informe a linha e coluna (0-2 0-2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (!jogadaValida(linha, coluna)) 
        {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        if (verificarVitoria()) 
        {
            imprimirTabuleiro();
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        }

        if (tabuleiroCheio()) 
        {
            imprimirTabuleiro();
            printf("Empate!\n");
            break;
        }

        trocarJogador();
    }
    return 0;
}