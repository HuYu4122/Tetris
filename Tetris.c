#include <time.h>
#include <string.h>
#include <stdio.h>
#include "raylib.h"
#include "Tetris.h"

enum GamePhase
{
    TitlePhase,
    PlayPhase,
    GameOverPhase
};

enum GamePhase gamePhase = TitlePhase;

int stage[] = 
{
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   0,    0,      0,      0,      0,      0,      0,      0,      0,      0,      WALL,
    WALL,   WALL, WALL,   WALL,   WALL,   WALL,   WALL,   WALL,   WALL,   WALL,   WALL,   WALL,
};

#pragma region Tetromino
    #pragma region L
        const int lTetromino0[] =
        {
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 1, 1, 0,
            0, 0, 0, 0,
        };

        const int lTetromino90[] =
        {
            0, 0, 0, 0,
            1, 1, 1, 0,
            1, 0, 0, 0,
            0, 0, 0, 0,
        };

        const int lTetromino180[] =
        {
            1, 1, 0, 0,
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 0, 0, 0,
        };

        const int lTetromino270[] =
        {
            0, 0, 1, 0,
            1, 1, 1, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
        };
    #pragma endregion
    #pragma region J
        const int jTetromino0[] =
        {
            0, 1, 0, 0,
            0, 1, 0, 0,
            1, 1, 0, 0,
            0, 0, 0, 0,
        };

        const int jTetromino90[] =
        {
            1, 0, 0, 0,
            1, 1, 1, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
        };

        const int jTetromino180[] =
        {
            0, 1, 1, 0,
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 0, 0, 0,
        };

        const int jTetromino270[] =
        {
            0, 0, 0, 0,
            1, 1, 1, 0,
            0, 0, 1, 0,
            0, 0, 0, 0,
        };
    #pragma endregion
    #pragma region O
        const int oTetromino[] =
        {
            1, 1, 0, 0,
            1, 1, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
        };
    #pragma endregion
    #pragma region S
        const int sTetromino0[] =
        {
            0, 0, 0, 0,
            0, 1, 1, 0,
            1, 1, 0, 0,
            0, 0, 0, 0,
        };

        const int sTetromino90[] =
        {
            0, 0, 0, 0,
            0, 1, 0, 0,
            0, 1, 1, 0,
            0, 0, 1, 0,
        };

        const int sTetromino180[] =
        {
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 1, 1, 0,
            1, 1, 0, 0,
        };

        const int sTetromino270[] =
        {
            0, 0, 0, 0,
            1, 0, 0, 0,
            1, 1, 0, 0,
            0, 1, 0, 0,
        };
    #pragma endregion
    #pragma region T
        const int tTetromino0[] =
        {
            0, 0, 0, 0,
            1, 1, 1, 0,
            0, 1, 0, 0,
            0, 0, 0, 0,
        };

        const int tTetromino90[] =
        {
            0, 1, 0, 0,
            1, 1, 0, 0,
            0, 1, 0, 0,
            0, 0, 0, 0,
        };

        const int tTetromino180[] =
        {
            0, 1, 0, 0,
            1, 1, 1, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
        };

        const int tTetromino270[] =
        {
            1, 0, 0, 0,
            1, 1, 0, 0,
            1, 0, 0, 0,
            0, 0, 0, 0,
        };
    #pragma endregion
    #pragma region I
        const int iTetromino0[] =
        {
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 1, 0, 0,
        };

        const int iTetromino90[] =
        {
            0, 0, 0, 0,
            1, 1, 1, 1,
            0, 0, 0, 0,
            0, 0, 0, 0,
        };

        const int iTetromino180[] =
        {
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 1, 0, 0,
            0, 1, 0, 0,
        };

        const int iTetromino270[] =
        {
            0, 0, 0, 0,
            1, 1, 1, 1,
            0, 0, 0, 0,
            0, 0, 0, 0,
        };
    #pragma endregion
    #pragma region Z
        const int zTetromino0[] =
        {
            1, 1, 0, 0,
            0, 1, 1, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
        };

        const int zTetromino90[] =
        {
            0, 0, 1, 0,
            0, 1, 1, 0,
            0, 1, 0, 0,
            0, 0, 0, 0,
        };

        const int zTetromino180[] =
        {
            0, 0, 0, 0,
            1, 1, 0, 0,
            0, 1, 1, 0,
            0, 0, 0, 0,
        };

        const int zTetromino270[] =
        {
            0, 1, 0, 0,
            1, 1, 0, 0,
            1, 0, 0, 0,
            0, 0, 0, 0,
        };
    #pragma endregion

#pragma endregion

const int *tetrominoTypes[7][4] =
{
    {zTetromino0, zTetromino90, zTetromino180, zTetromino270},
    {sTetromino0, sTetromino90, sTetromino180, sTetromino270},
    {tTetromino0, tTetromino90, tTetromino180, tTetromino270},
    {oTetromino, oTetromino, oTetromino, oTetromino},
    {iTetromino0, iTetromino90, iTetromino180, iTetromino270},
    {jTetromino0, jTetromino90, jTetromino180, jTetromino270},
    {lTetromino0, lTetromino90, lTetromino180, lTetromino270},
};

const Color colorTypes[8] =
{
    {0,     255,      255,    255},
    {255,     255,    0,    255},
    {128,   0,    128,      255},
    {0,   255,      0,    255},
    {255,     0,    0,      255},
    {0,   0,      255,      255},
    {255,     127,      0,    255},
    {127,   127,    127,    255},
};

int score = 0;
int tetromini[ARRAYTETROMINI];

int main(int argc, char **argv, char **environ)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Title");
    InitAudioDevice();
    SetTargetFPS(60);

#pragma region Variable
    const Color phantomTetromino = {127, 127, 127, 127};
    const int tetrominoStartX = STAGE_WIDTH / 2;
    const int tetrominoStartY = 0;

    int currentTetrominoX = tetrominoStartX;
    int currentTetrominoY = tetrominoStartY;

    int currentRotation = 0;

    const float maxTimerBreakLine = 1;
    float countBreakLine = maxTimerBreakLine;
    int lineToBreak;
    int breakingLine = 0;

    const float maxTimerMoveDownTetromino = 1.f;
    float countMoveDownTetromino = maxTimerMoveDownTetromino;
    float increaseSpeedDown = 1;
#pragma endregion

    time_t unixTime;
    time(&unixTime);
    SetRandomSeed(unixTime);

    Music title_Music = LoadMusicStream("Sound/Title.mp3");
    Music background_Music = LoadMusicStream("Sound/BackgroundPlay.mp3");
    Music gameover_Music = LoadMusicStream("Sound/GameOver.mp3");
    PlayMusicStream(title_Music);
    PlayMusicStream(background_Music);
    PlayMusicStream(gameover_Music);
    SetMasterVolume(0.5f);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (gamePhase == TitlePhase)
        {
            UpdateMusicStream(title_Music);
            DrawText(TextFormat("TETRIS"), WINDOW_WIDTH / 3, WINDOW_HEIGHT / 3, 90, BLACK);
            DrawText(TextFormat("Press 'Enter' To Play"), WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2, 30, RED);
            if (IsKeyPressed(KEY_ENTER))
            {
                ResetStage();
                gamePhase = PlayPhase;
                StopMusicStream(title_Music);
                PlayMusicStream(background_Music);
            }
        }

        if (gamePhase == PlayPhase)
        {
            if (CheckCollision(currentTetrominoX, currentTetrominoY, tetrominoTypes[tetromini[0]][currentRotation]))
            {
                gamePhase = GameOverPhase;
                StopMusicStream(gameover_Music);
                PlayMusicStream(gameover_Music);
            }
            UpdateMusicStream(background_Music);
            if (!breakingLine)
            {
                countMoveDownTetromino -= GetFrameTime() * increaseSpeedDown;

                #pragma region KeyInput
                #pragma region Rotation Tetromino
                if (IsKeyPressed(KEY_UP))
                {
                    const int lastRotation = currentRotation;
                    currentRotation++;

                    if (currentRotation > 3)
                        currentRotation = 0;

                    if (CheckCollision(currentTetrominoX, currentTetrominoY, tetrominoTypes[tetromini[0]][currentRotation]))
                        currentRotation = lastRotation;
                }
                #pragma endregion

                #pragma region Lateral Movement
                if (IsKeyPressed(KEY_RIGHT))
                    // No need to check overflow, wall is your protector
                    if (!CheckCollision(currentTetrominoX + 1, currentTetrominoY, tetrominoTypes[tetromini[0]][currentRotation]))
                        currentTetrominoX++;

                if (IsKeyPressed(KEY_LEFT))
                    // No need to check overflow, wall is your protector
                    if (!CheckCollision(currentTetrominoX - 1, currentTetrominoY, tetrominoTypes[tetromini[0]][currentRotation]))
                        currentTetrominoX--;
                #pragma endregion

                #pragma region Move Down
                if (countMoveDownTetromino <= 0 || IsKeyPressed(KEY_DOWN))
                {
                    if (!CheckCollision(currentTetrominoX, currentTetrominoY + 1, tetrominoTypes[tetromini[0]][currentRotation]))
                    {
                        currentTetrominoY++;
                        countMoveDownTetromino = maxTimerMoveDownTetromino;
                    }
                    else
                    {
                        for (int y = 0; y < TETROMINO_SIZE; y++)
                        {
                            for (int x = 0; x < TETROMINO_SIZE; x++)
                            {
                                const int offset = y * TETROMINO_SIZE + x;

                                const int *tetromino = tetrominoTypes[tetromini[0]][currentRotation];

                                if (tetromino[offset] == 1)
                                {
                                    const int offset_stage = (y + currentTetrominoY) * STAGE_WIDTH + (x + currentTetrominoX);

                                    stage[offset_stage] = tetromini[0] + 1;
                                }
                            }
                        }

                        lineToBreak = DeleteLines(&breakingLine);

                        if (score != 0 && score % WHENINCREASESPEED == 0)
                            increaseSpeedDown += 0.2f;

                        GetTetromino();
                        currentTetrominoX = tetrominoStartX;
                        currentTetrominoY = tetrominoStartY;
                        currentRotation = 0;
                    }
                }
                #pragma endregion
                
                #pragma region Speed Fall

                if(IsKeyPressed(KEY_SPACE))
                {
                    while(!CheckCollision(currentTetrominoX, currentTetrominoY + 1, tetrominoTypes[tetromini[0]][currentRotation]))
                    {
                        currentTetrominoY++;
                    }
                }

                #pragma endregion
                
                #pragma endregion
            }

            DrawBase();
            DrawArrayTetromini();
            

            if (breakingLine)
            {
                if (countBreakLine <= 0)
                {
                    countBreakLine = maxTimerBreakLine;
                    breakingLine = 0;
                }
                else
                {
                    countBreakLine -= GetFrameTime();
                    DrawRectangle(STARTOFFSET_X + TILE_SIZE, lineToBreak * TILE_SIZE + STARTOFFSET_Y, TILE_SIZE * (STAGE_WIDTH - 2), TILE_SIZE, BLACK);
                }
            }
            else
            {
                int phantomTetrominoY = currentTetrominoY;
                while(!CheckCollision(currentTetrominoX, phantomTetrominoY + 1, tetrominoTypes[tetromini[0]][currentRotation]))
                {
                    phantomTetrominoY++;
                }
                drawTetromino(
                    phantomTetromino,
                    STARTOFFSET_X, STARTOFFSET_Y,
                    currentTetrominoX, phantomTetrominoY,
                    tetrominoTypes[tetromini[0]][currentRotation]);

                drawTetromino(
                    colorTypes[tetromini[0]],
                    STARTOFFSET_X, STARTOFFSET_Y,
                    currentTetrominoX, currentTetrominoY,
                    tetrominoTypes[tetromini[0]][currentRotation]);
            }
                
        }

        if (gamePhase == GameOverPhase)
        {
            UpdateMusicStream(gameover_Music);
            DrawText(TextFormat("Game Over"), WINDOW_WIDTH / 6, WINDOW_HEIGHT / 3, 80, RED);
            DrawText(TextFormat("Press 'R' To Restart"), WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2.25, 30, RED);
            if (IsKeyPressed(KEY_R))
            {
                ResetStage();
                gamePhase = TitlePhase;
                StopMusicStream(gameover_Music);
                PlayMusicStream(title_Music);
            }
        }

        EndDrawing();
    }

    UnloadMusicStream(title_Music);
    UnloadMusicStream(background_Music);
    UnloadMusicStream(gameover_Music);
    CloseAudioDevice();

    return 0;
}