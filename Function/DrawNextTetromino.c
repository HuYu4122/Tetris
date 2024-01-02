#include "../Tetris.h"

extern Color colorTypes[];
extern int *tetrominoTypes[7][4];
extern tetromini[4];

void DrawNextTetromino(const int *tetromino)
{
    const int startOffSetX = (WINDOW_WIDTH - 350);
    const int startOffSetY = 50;
    
    DrawRectangleLines(startOffSetX, startOffSetY, TETROMINO_SIZE * TILE_SIZE * 2, TETROMINO_SIZE * TILE_SIZE * 2, LIGHTGRAY);
    for (int y = -1; y < TETROMINO_SIZE; y++)
    {
        for (int x = -1; x < TETROMINO_SIZE; x++)
        {
            const int posX = x * (TILE_SIZE * 2) + startOffSetX;
            const int posY = y * (TILE_SIZE * 2) + startOffSetY;
            const int offset = y * TETROMINO_SIZE + x;

            if (tetromino[offset] == 1)
            {
                DrawRectangle(
                    posX, posY,
                    TILE_SIZE * 2, TILE_SIZE * 2,
                    colorTypes[0]);
                DrawRectangleLines(
                    posX, posY,
                    TILE_SIZE * 2, TILE_SIZE * 2,
                    BLACK);
            }
        }
    }
}