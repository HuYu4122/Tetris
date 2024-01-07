#include <string.h>
#include <stdio.h>
#include "../Tetris.h"

extern int stage[];
extern int score;

int DeleteLines(int *countLinesToDelete)
{
    int line_Y;
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
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));
            ResetLines(y);
            score++;
            line_Y = y;
            *countLinesToDelete += 1;
        }
    }
    return line_Y;
}