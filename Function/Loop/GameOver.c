#include "../../Tetris.h"

void GameOver()
{
    DrawText(TextFormat("Game Over"), WINDOW_WIDTH / 6, WINDOW_HEIGHT / 3, 80, RED);
    DrawText(TextFormat("Press 'R' To Restart"), WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2.25, 30, RED);
    if (IsKeyPressed(KEY_R))
        InitGame();
}