#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 8
#define BISPO_MOVES 5
#define TORRE_MOVES 5
#define RAINHA_MOVES 8
#define CAVALO_MOVES 3 // 1 movimento no eixo x e 2 movimentos no eixo y

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
void exibirTabuleiro(char tabuleiro[BOARD_SIZE][BOARD_SIZE]);
void incializarTabuleiro(char tabuleiro[BOARD_SIZE][BOARD_SIZE]);
void posicionarPeca(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao, char peca);
void moverBispo(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao);
void moverTorre(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao);
void moverRainha(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao);
void moverCavalo(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao, int moveCount);
void movePeca(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicaoPeca, int moveCount);

int main()
{
    int opcao = -1;
    char tabuleiro[BOARD_SIZE][BOARD_SIZE];
    do
    {
        incializarTabuleiro(tabuleiro);
        int moves = 0;
        struct posicao posicaoPeca = (struct posicao){0, 0};
        cls();
        exibirTabuleiro(tabuleiro);

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
            movePeca(tabuleiro, &posicaoPeca, BISPO_MOVES);
            break;
        case 2:
            // Implementação de Movimentação da Torre
            moves = 0;
            posicaoPeca = (struct posicao){0, 0};
            cls();
            posicionarPeca(tabuleiro, &posicaoPeca, 'T');
            exibirTabuleiro(tabuleiro);
            movePeca(tabuleiro, &posicaoPeca, TORRE_MOVES);
            break;
        case 3:
            // Implementação de Movimentação da Rainha
            moves = 0;
            posicaoPeca = (struct posicao){7, 0};
            cls();
            posicionarPeca(tabuleiro, &posicaoPeca, 'R');
            exibirTabuleiro(tabuleiro);
            movePeca(tabuleiro, &posicaoPeca, RAINHA_MOVES);
            break;
        case 4:
            // Implementação de Movimentação do Cavalo
            moves = 0;
            posicaoPeca = (struct posicao){0, 0};
            cls();
            posicionarPeca(tabuleiro, &posicaoPeca, 'C');
            exibirTabuleiro(tabuleiro);
            movePeca(tabuleiro, &posicaoPeca, CAVALO_MOVES);
            break;
        case 0:
            cls();
            printf("Encerrando o programa...\n");
            return 0;
        default:
            printf("Opção inválida!\n");
            printf("Pressione Enter para continuar...");
            getchar();
            continue;
        }        

        opcao = -1;
        printf("\nPressione Enter para continuar...");
        getchar();

    } while (opcao == -1);

    return 0;
}

void movePeca(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicaoPeca, int moveCount)
{
    wait(0.5);
    cls();
    switch(tabuleiro[posicaoPeca->x][posicaoPeca->y]){
        case 'B':
            moverBispo(tabuleiro, posicaoPeca);
            break;
        case 'T':
            moverTorre(tabuleiro, posicaoPeca);
            break;
        case 'R':
            moverRainha(tabuleiro, posicaoPeca);
            break;
        case 'C':
            moverCavalo(tabuleiro, posicaoPeca, moveCount);
            break;
    }
    exibirTabuleiro(tabuleiro);    
    if( moveCount > 1)
    {
        printf("Exibindo movimento da peça...");
        movePeca(tabuleiro, posicaoPeca, moveCount - 1);
    }else{
        printf("Movimento concluído!\n");
    }
}

void exibirOpcoes()
{
    printf("Escolha uma peça para testar a movimentação:\n");
    printf("1. - Bispo  [B] - 5 casas na diagonal direita para cima\n");
    printf("2. - Torre  [T] - 5 casas para a direita\n");
    printf("3. - Rainha [R] - 8 casas para a esquerda\n");
    printf("4. - Cavalo [C] - 1 vez em L para cima à direita\n");
    printf("0. - Sair\n");
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

void moverCavalo(char tabuleiro[BOARD_SIZE][BOARD_SIZE], struct posicao *posicao, int moveCount)
{
    tabuleiro[posicao->x][posicao->y] = '.';
    if(moveCount == CAVALO_MOVES){
        posicao->x++;
    }else{
        posicao->y++;
    }
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