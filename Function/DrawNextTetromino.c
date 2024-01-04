#include "../Tetris.h"

extern Color colorTypes[];
extern int *tetrominoTypes[7][4];
extern int tetromini[ARRAYTETROMINI];

void DrawArrayTetromini()
{
    const int startOffSetX = (WINDOW_WIDTH - 350);
    const int startOffSetY = 50;
    int plus = 0;

    DrawRectangleLines(startOffSetX, startOffSetY, TETROMINO_SIZE * TILE_SIZE, TETROMINO_SIZE * TILE_SIZE, LIGHTGRAY);
    for (int i = 1; i < ARRAYTETROMINI; i++)
    {
        drawTetromino(
            colorTypes[tetromini[i]],
            startOffSetX, startOffSetY + plus,
            0, 0,
            tetrominoTypes[tetromini[i]][0]);
        plus += TETROMINO_SIZE * TILE_SIZE;
    }
}

void GetTetromino()
{
    for (int i = 0; i < ARRAYTETROMINI - 1; i++)
    {
        tetromini[i] = tetromini[i + 1];
    }
    tetromini[ARRAYTETROMINI - 1] = GetRandomValue(0, 6);
}