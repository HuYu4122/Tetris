#include "../Tetris.h"

extern int stage[];
extern Color colorTypes[8];
extern int score;

void DrawBase()
{
    DrawText(TextFormat("Score: %08i", score), 100, 30, 30, RED);

    for (int y = 0; y < STAGE_HEIGHT; y++)
    {
        for (int x = 0; x < STAGE_WIDTH; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int color = stage[offset] - 1;
            const int posX = x * TILE_SIZE + STARTOFFSET_X;
            const int posY = y * TILE_SIZE + STARTOFFSET_Y;

            if (stage[offset] == 8)
                DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, colorTypes[WALL - 1]);
            else if (stage[offset] == 0)
                DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, RAYWHITE);
            else
                DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, colorTypes[color]);
            DrawRectangleLines(posX, posY, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
        }
    }
}