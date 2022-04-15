/*

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
    printf("============\n\n");
    return;
}

int rotateFaceClockwise(int face[][DI])
{
    int newFace[DI][DI];
    for (int r = 0; r < DI; r++)
    {
        for (int c = 0; c < DI; c++)
        {
            int tc = DI - c;
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
    return;
}

void moveA(int cube[FACES][DI][DI])
{
    rotateFaceCounterClockwise(cube[TOP]);
    slideRowRightHanded(0, cube[FRONT],
                        cube[LEFT], cube[BACK], cube[RIGHT]);
    return;
}

int main()
{
    int cube1[FACES][DI][DI];

    // Inicializa o cubo com as cores em ordem
    setFace(cube1[FRONT], GREEN);
    setFace(cube1[LEFT], ORANGE);
    setFace(cube1[RIGHT], RED);
    setFace(cube1[BACK], BLUE);
    setFace(cube1[TOP], WHITE);
    setFace(cube1[BOTTOM], YELLOW);

    showCube(cube1);

    moveA(cube1);

    showCube(cube1);

    return 0;
}

*/