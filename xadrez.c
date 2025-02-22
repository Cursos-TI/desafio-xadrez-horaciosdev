#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 8
#define BISPO_MOVES 5
#define TORRE_MOVES 5
#define RAINHA_MOVES 8
#define CAVALO_MOVES 1

struct posicao
{
    int x;
    int y;
};

void cls();
void wait(float seconds);
int clean_scanf(const char *format, void *arg);
int scanfValidIntValue(const char *prompt);
void exibirOpcoes();
void incializarTabuleiro(char tabuleiro[BOARD_SIZE][BOARD_SIZE]);
void exibirTabuleiro(char tabuleiro[BOARD_SIZE][BOARD_SIZE]);
void posicionarPeca(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao, char peca);
void moverBispo(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao);
void moverTorre(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao);
void moverRainha(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao);
void moverCavalo(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao);

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main()
{
    char tabuleiro[BOARD_SIZE][BOARD_SIZE];
    int opcao = -1;

    incializarTabuleiro(tabuleiro);

    do
    {
        int moves = 0;
        struct posicao posicaoPeca = (struct posicao){0, 0};
        cls();
        exibirTabuleiro(tabuleiro);

        printf("\n\n");
        exibirOpcoes();

        opcao = scanfValidIntValue("Opção: \n=> ");

        switch (opcao)
        {
        case 1:
            // Implementação de Movimentação do Bispo
            moves = 0;
            posicaoPeca = (struct posicao){0, 0};
            cls();
            posicionarPeca(tabuleiro, &posicaoPeca, 'B');
            exibirTabuleiro(tabuleiro);
            while (BISPO_MOVES > moves)
            {
                wait(0.5);
                cls();
                moverBispo(tabuleiro, &posicaoPeca);
                exibirTabuleiro(tabuleiro);
                moves++;
            }
            break;
        case 2:
            // Implementação de Movimentação da Torre
            moves = 0;
            posicaoPeca = (struct posicao){0, 0};
            cls();
            posicionarPeca(tabuleiro, &posicaoPeca, 'T');
            exibirTabuleiro(tabuleiro);
            while (TORRE_MOVES > moves)
            {
                wait(0.5);
                cls();
                moverTorre(tabuleiro, &posicaoPeca);
                exibirTabuleiro(tabuleiro);
                moves++;
            }
            break;
        case 3:
            // Implementação de Movimentação da Rainha
            moves = 0;
            posicaoPeca = (struct posicao){7, 0};
            cls();
            posicionarPeca(tabuleiro, &posicaoPeca, 'R');
            exibirTabuleiro(tabuleiro);
            while (RAINHA_MOVES > moves)
            {
                wait(0.5);
                cls();
                moverRainha(tabuleiro, &posicaoPeca);
                exibirTabuleiro(tabuleiro);
                moves++;
            }
            break;
        case 4:
            // Implementação de Movimentação do Cavalo
            moves = 0;
            posicaoPeca = (struct posicao){0, 0};
            cls();
            posicionarPeca(tabuleiro, &posicaoPeca, 'C');
            exibirTabuleiro(tabuleiro);
            while (CAVALO_MOVES > moves)
            {
                wait(0.5);
                cls();
                moverCavalo(tabuleiro, &posicaoPeca);
                exibirTabuleiro(tabuleiro);
                moves++;
            }
            break;
        default:
            printf("Opção inválida!\n");
            printf("Pressione Enter para continuar...");
            getchar();
            opcao = -1;
            break;
        }
    } while (opcao == -1);

    // printf("\n Aperte ENTER para encerrar o programa.");
    // getchar();

    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}

void cls()
{
    printf("\033[H\033[J");
}

void wait(float seconds)
{
    clock_t start_time = clock();
    while ((float)(clock() - start_time) / CLOCKS_PER_SEC < seconds)
        ;
}

void exibirOpcoes()
{
    printf("Escolha uma peça para testar a movimentação:\n");
    printf("1. - Bispo  [B] - 5 casas na diagonal direita para cima\n");
    printf("2. - Torre  [T] - 5 casas para a direita\n");
    printf("3. - Rainha [R] - 8 casas para a esquerda\n");
    printf("4. - Cavalo [C] - 1 vez em L para cima à direita\n");
}

void incializarTabuleiro(char tabuleiro[BOARD_SIZE][BOARD_SIZE])
{
    for (int y = BOARD_SIZE - 1; y >= 0; y--)
    {
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            tabuleiro[x][y] = '.';
        }
    }
}

void posicionarPeca(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao, char peca)
{
    tabuleiro[posicao->x][posicao->y] = peca;
}

void moverBispo(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao)
{
    tabuleiro[posicao->x][posicao->y] = '.';
    posicao->x++;
    posicao->y++;
    tabuleiro[posicao->x][posicao->y] = 'B';
}

void moverTorre(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao)
{
    tabuleiro[posicao->x][posicao->y] = '.';
    posicao->x++;
    tabuleiro[posicao->x][posicao->y] = 'T';
}

void moverRainha(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao)
{
    tabuleiro[posicao->x][posicao->y] = '.';
    posicao->x--;
    tabuleiro[posicao->x][posicao->y] = 'R';
}

void moverCavalo(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao)
{
    tabuleiro[posicao->x][posicao->y] = '.';
    posicao->x++;
    posicao->y+=2;
    tabuleiro[posicao->x][posicao->y] = 'C';
}

int clean_scanf(const char *format, void *arg)
{
    int result = scanf(format, arg);
    while (getchar() != '\n')
        ;
    return result;
}

int scanfValidIntValue(const char *prompt)
{
    int value;
    printf("%s", prompt);
    if (clean_scanf("%d", &value) != 1)
    {
        return -1;
    }
    else
    {
        return value;
    }
}

void exibirTabuleiro(char tabuleiro[BOARD_SIZE][BOARD_SIZE])
{
    for (int y = BOARD_SIZE - 1; y >= 0; y--)
    {
        printf("\n");
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            printf(" %c ", tabuleiro[x][y]);
        }
    }
    printf("\n\n");
}