#include <string.h>
#include "../Tetris.h"

extern int stage[];

void DeleteLines(int score)
{
    for (int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        int checkLine = 1;

        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if (stage[offset] == 0)
            {
                checkLine = 0;
                break;
            }
        }

        if (checkLine)
        {
            score++;
            DrawRectangle(STARTOFFSET_X, y * TILE_SIZE + STARTOFFSET_Y, TILE_SIZE * STAGE_WIDTH, TILE_SIZE, WHITE);
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));
            ResetLines(y);
        }
    }
}