#include <stdio.h>
#define DI 3 // dimension of the cube

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

char COLORS[6] = {'G', 'O', 'R', 'B', 'W', 'Y'};

typedef struct
{
    int frontFace[DI][DI];
    int leftFace[DI][DI];
    int rightFace[DI][DI];
    int backFace[DI][DI];
    int topFace[DI][DI];
    int bottomFace[DI][DI];

} Cube;

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

void showFrontFace(Cube cube)
{
    printf("frontFace\n");
    showFace(cube.frontFace);
    return;
}

void showLeftFace(Cube cube)
{
    printf("leftFace\n");
    showFace(cube.leftFace);
    return;
}

void showRightFace(Cube cube)
{
    printf("rightFace\n");
    showFace(cube.rightFace);
    return;
}

void showBackFace(Cube cube)
{
    printf("backFace\n");
    showFace(cube.backFace);
    return;
}

void showTopFace(Cube cube)
{
    printf("topFace\n");
    showFace(cube.topFace);
    return;
}

void showbottomFace(Cube cube)
{
    printf("bottomFace\n");
    showFace(cube.bottomFace);
    return;
}

void showCube(Cube cube)
{
    printf("== CUBE ==\n");
    showFrontFace(cube);
    showLeftFace(cube);
    showRightFace(cube);
    showBackFace(cube);
    showTopFace(cube);
    showbottomFace(cube);
    printf("==========\n");
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

void moveA(Cube cube)
{
    rotateFaceCounterClockwise(cube.topFace);
    slideRowRightHanded(0, cube.frontFace, 
    cube.leftFace, cube.backFace, cube.rightFace);
    return;
}

int main()
{
    Cube cube1;

    // Inicializa o cubo com as cores em ordem
    setFace(cube1.frontFace, GREEN);
    setFace(cube1.leftFace, ORANGE);
    setFace(cube1.rightFace, RED);
    setFace(cube1.backFace, BLUE);
    setFace(cube1.topFace, WHITE);
    setFace(cube1.bottomFace, YELLOW);

    // Exibe todos os lados do cubo
    showCube(cube1);

    return 0;
}