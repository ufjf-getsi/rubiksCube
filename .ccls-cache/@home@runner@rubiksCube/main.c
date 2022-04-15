#include <stdio.h>
#define DI 3 // dimension of the cube
#define FACES 6

#define FRONT 0
#define LEFT 1
#define RIGHT 2
#define BACK 3
#define TOP 4
#define BOTTOM 5

#define GREEN 0
#define ORANGE 1
#define RED 2
#define BLUE 3
#define WHITE 4
#define YELLOW 5

char COLORS[FACES] = {'G', 'O', 'R', 'B', 'W', 'Y'};

void setFace(int face[][DI], int value)
{
    for (int i = 0; i < DI; i++)
    {
        for (int j = 0; j < DI; j++)
        {
            face[i][j] = value;
        }
    }

    return;
}

void showFace(int face[][DI])
{
    for (int i = 0; i < DI; i++)
    {
        for (int j = 0; j < DI; j++)
        {
            printf("%c", COLORS[face[i][j]]);
        }
        printf("\n");
    }
    return;
}

void showRow(int row, int face[][DI])
{
    for (int i = 0; i < DI; i++)
    {
        printf("%c", COLORS[face[row][i]]);
    }
    printf(" ");
    return;
}

void showBlankRow()
{
    printf("    ");
    return;
}

void showCube(int cube[FACES][DI][DI])
{
    printf("=== CUBE ===\n");
    // Parte superior
    for (int i = 0; i < DI; i++)
    {
        showBlankRow();
        showRow(i, cube[TOP]);
        printf("\n");
    }
    // Parte do meio
    for (int i = 0; i < DI; i++)
    {
        showRow(i, cube[LEFT]);
        showRow(i, cube[FRONT]);
        showRow(i, cube[RIGHT]);
        showRow(i, cube[BACK]);
        printf("\n");
    }
    // Parte inferior
    for (int i = 0; i < DI; i++)
    {
        showBlankRow();
        showRow(i, cube[BOTTOM]);
        printf("\n");
    }
    // printf("============\n\n");
    return;
}

int rotateFaceClockwise(int face[][DI])
{
    int newFace[DI][DI];
    for (int r = 0; r < DI; r++)
    {
        for (int c = 0; c < DI; c++)
        {
            int tc = DI - 1 - c;
            int tr = r;
            newFace[tr][tc] = face[r][c];
        }
    }
    for (int r = 0; r < DI; r++)
    {
        for (int c = 0; c < DI; c++)
        {
            face[r][c] = newFace[r][c];
        }
    }
    return 0;
}

void rotateFaceCounterClockwise(int face[][DI])
{
    return;
}

void slideRowRightHanded(int row, int face1[][DI], int face2[][DI], int face3[][DI], int face4[][DI])
{
    int auxFaceRow[DI];
    for (int c = 0; c < DI; c++)
    {
        auxFaceRow[c] = face1[row][c];
    }
    for (int c = 0; c < DI; c++)
    {
        face1[row][c] = face4[row][c];
        face4[row][c] = face3[row][c];
        face3[row][c] = face2[row][c];
    }
    for (int c = 0; c < DI; c++)
    {
        face2[row][c] = auxFaceRow[c];
    }
    return;
}

void slideRowLeftHanded(int row, int face1[][DI], int face2[][DI], int face3[][DI], int face4[][DI])
{
    int auxFaceRow[DI];
    for (int c = 0; c < DI; c++)
    {
        auxFaceRow[c] = face1[row][c];
    }
    for (int c = 0; c < DI; c++)
    {
        face1[row][c] = face2[row][c];
        face2[row][c] = face3[row][c];
        face3[row][c] = face4[row][c];
    }
    for (int c = 0; c < DI; c++)
    {
        face4[row][c] = auxFaceRow[c];
    }
    return;
}

// Interpreta o comando
void doMove(char move, int cube[FACES][DI][DI])
{
    switch (move)
    {
    case 'U':
        slideRowRightHanded(0, cube[FRONT], cube[LEFT], cube[BACK], cube[RIGHT]);
        rotateFaceClockwise(cube[TOP]);
        break;
    case 'u':
        slideRowLeftHanded(0, cube[FRONT], cube[LEFT], cube[BACK], cube[RIGHT]);
        rotateFaceCounterClockwise(cube[TOP]);
        break;
    case 'D':
        slideRowLeftHanded(2, cube[FRONT], cube[LEFT], cube[BACK], cube[RIGHT]);
        break;
    case 'd':
        slideRowRightHanded(2, cube[FRONT], cube[LEFT], cube[BACK], cube[RIGHT]);
        break;
    default:
        break;
    }
}

int main()
{
    int cube[FACES][DI][DI];
    char move;

    // Inicializa o cubo com as cores em ordem
    setFace(cube[FRONT], GREEN);
    setFace(cube[LEFT], ORANGE);
    setFace(cube[RIGHT], RED);
    setFace(cube[BACK], BLUE);
    setFace(cube[TOP], WHITE);
    setFace(cube[BOTTOM], YELLOW);

    // Para testes
    cube[TOP][0][0] = YELLOW;
    cube[TOP][0][2] = BLUE;
    
    // Repetição do jogo
    do
    {
        showCube(cube);
        printf("Move: ");
        move = getchar();
        if (move == '0')
        {
            break;
        }
        doMove(move, cube);
        printf("\n");
        // Limpa os demais caracteres digitados no comando
        while ((move = getchar()) != '\n' && move != EOF)
        {
        }
    } while (1);

    return 0;
}
