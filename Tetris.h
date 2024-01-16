#include "raylib.h"

#define WINDOW_WIDTH 1240
#define WINDOW_HEIGHT 700
#define STARTOFFSET_X (WINDOW_WIDTH / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2)
#define STARTOFFSET_Y (WINDOW_HEIGHT / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2)

#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 24
#define TETROMINO_SIZE 4
#define WALL 8
#define ARRAYTETROMINI 2
#define WHENINCREASESPEED 100

void ResetStage();
int CheckCollision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino);
void drawTetromino(
    const Color currentColor,
    const int startOffsetX,
    const int startOffsetY,
    const int tetrominoStartX,
    const int tetrominoStartY,
    const int *tetromino);
void ResetLines(int startLineY);
int DeleteLines(int *toDeleteLine);
void DrawArrayTetromini();
void DrawHoldTetromino(int holdTetromino, Color holdTetrominoColor);
void DrawBase();
void GetTetromino();