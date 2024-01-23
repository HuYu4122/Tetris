#include "../Tetris.h"

void DrawTetrominoBase(const int pos_x)
{
    for (int y = 0; y < TETROMINO_SIZE; y++)
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            DrawRectangleLines(pos_x + (x * TILE_SIZE), STARTOFFSET_Y + (y * TILE_SIZE),
                               TILE_SIZE, TILE_SIZE,
                               BLACK);
        }
    }
}