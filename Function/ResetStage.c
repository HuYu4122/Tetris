#include "../Tetris.h"

extern int stage[];

void ResetStage()
{
    for (int y = 0; y < STAGE_HEIGHT; y++)
    {
        for (int x = 0; x < STAGE_WIDTH; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            if (stage[offset] != WALL)
                stage[offset] = 0;
        }
    }
}