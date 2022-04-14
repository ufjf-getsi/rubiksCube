// Arquivo para testes

#include <stdio.h>
#define DIM 3 // dimmension of the cube

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
    int frontFace[DIM][DIM];
    int leftFace[DIM][DIM];
    int rightFace[DIM][DIM];
    int backFace[DIM][DIM];
    int topFace[DIM][DIM];
    int bottomFace[DIM][DIM];

} Cube;

void setFace(int face[DIM][DIM], int value)
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            face[i][j] = value;
        }
    }
}

void showFace(int face[DIM][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            printf("%c", COLORS[face[i][j]]);
        }
        printf("\n");
    }
    printf("\n");
}

void showFrontFace(Cube cube)
{
    printf("frontFace\n");
    showFace(cube.frontFace);
}

void showLeftFace(Cube cube)
{
    printf("leftFace\n");
    showFace(cube.leftFace);
}

void showRightFace(Cube cube)
{
    printf("rightFace\n");
    showFace(cube.rightFace);
}

void showBackFace(Cube cube)
{
    printf("backFace\n");
    showFace(cube.backFace);
}

void showTopFace(Cube cube)
{
    printf("topFace\n");
    showFace(cube.topFace);
}

void showBottomFace(Cube cube)
{
    printf("bottomFace\n");
    showFace(cube.bottomFace);
}

int main()
{
    Cube cube1;
    setFace(cube1.frontFace, GREEN);
    setFace(cube1.leftFace, ORANGE);
    setFace(cube1.rightFace, RED);
    setFace(cube1.backFace, BLUE);
    setFace(cube1.topFace, WHITE);
    setFace(cube1.bottomFace, YELLOW);

    showFrontFace(cube1);
    showLeftFace(cube1);
    showRightFace(cube1);
    showBackFace(cube1);
    showTopFace(cube1);
    showBottomFace(cube1);

    return 0;
}