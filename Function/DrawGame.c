#include <string.h>
#include "../Tetris.h"

extern int stage[];
extern int colorTypes[];
extern int *tetrominoTypes[];

void DrawGame(int currentTetrominoX, int currentTetrominoY, int currentTetrominoType, int currentRotation)
{
    DrawText(TextFormat("Score: %08i", SCORE), WINDOW_WIDTH / 4, 0, 30, RED);

    for (int y = 0; y < STAGE_HEIGHT; y++)
    {
        for (int x = 0; x < STAGE_WIDTH; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int color = stage[offset];

            if (stage[offset] != 0)
            {
                DrawRectangle(x * TILE_SIZE + STARTOFFSET_X, y * TILE_SIZE + STARTOFFSET_Y, TILE_SIZE, TILE_SIZE, colorTypes[color - 1]);
            }

            DrawRectangleLines(x * TILE_SIZE + STARTOFFSET_X, y * TILE_SIZE + STARTOFFSET_Y, TILE_SIZE, TILE_SIZE, WHITE);
        }
    }

    drawTetromino(
        colorTypes[1],
        STARTOFFSET_X, STARTOFFSET_Y,
        currentTetrominoX, currentTetrominoY,
        tetrominoTypes[currentTetrominoType][currentRotation]);

    EndDrawing();
}