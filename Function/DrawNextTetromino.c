#include "../Tetris.h"

extern Color colorTypes[];
extern int *tetrominoTypes[7][4];
extern int tetromini[ARRAYTETROMINI];

void DrawNextTetromino()
{
    const int nextOffSetX = (WINDOW_WIDTH - 350);
    int plus = 0;

    DrawTetrominoBase(nextOffSetX);
    for (int i = 1; i < ARRAYTETROMINI; i++)
    {
        drawTetromino(
            colorTypes[tetromini[i]],
            nextOffSetX, STARTOFFSET_Y + plus,
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