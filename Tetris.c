#include <time.h>
#include <string.h>
#include <stdio.h>
#include "raylib.h"
#include "Tetris.h"

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

#pragma region Tetromino Types
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
#pragma endregion

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

int main(int argc, char** argv, char** environ)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Title");
    InitAudioDevice();
    SetTargetFPS(60);

    #pragma region Variable
    const int tetrominoStartX = STAGE_WIDTH / 2;
    const int tetrominoStartY = 0;

    int currentTetrominoX = tetrominoStartX;
    int currentTetrominoY = tetrominoStartY;

    int currentTetrominoType = GetRandomValue(0, 6);
    int currentRotation = 0;
    int score = 0;

    float increaseSpeedDown = 1;
    const float moveTetrominoDownTimer = 1.f;
    float timeToMoveTetrominoDown = moveTetrominoDownTimer;
    #pragma endregion

    time_t unixTime;
    time(&unixTime);
    SetRandomSeed(unixTime);

    Music background_Music = LoadMusicStream("Sound/TetrisMusic.mp3");
    PlayMusicStream(background_Music);
    SetMasterVolume(0.1f);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if(!CheckCollision(currentTetrominoX,currentTetrominoY,tetrominoTypes[currentTetrominoType][currentRotation]))
        {
            UpdateMusicStream(background_Music);
            timeToMoveTetrominoDown -= GetFrameTime() * increaseSpeedDown;

            #pragma region KeyInput
                #pragma region Rotation Tetromino
                    if (IsKeyPressed(KEY_UP))
                    {
                        const int lastRotation = currentRotation;
                        currentRotation++;

                        if (currentRotation > 3) currentRotation = 0;

                        if (CheckCollision(currentTetrominoX,currentTetrominoY,tetrominoTypes[currentTetrominoType][currentRotation]))
                            currentRotation = lastRotation;
                    }
                #pragma endregion

                #pragma region Lateral Movement
                    if (IsKeyPressed(KEY_RIGHT))
                        // No need to check overflow, wall is your protector
                        if (!CheckCollision(currentTetrominoX+1,currentTetrominoY,tetrominoTypes[currentTetrominoType][currentRotation]))
                            currentTetrominoX++;

                    if (IsKeyPressed(KEY_LEFT))
                        // No need to check overflow, wall is your protector
                        if (!CheckCollision(currentTetrominoX-1,currentTetrominoY,tetrominoTypes[currentTetrominoType][currentRotation]))
                            currentTetrominoX--;
                #pragma endregion

                #pragma region Move Down
                    if(timeToMoveTetrominoDown <= 0 || IsKeyDown(KEY_DOWN))
                    {            
                        if(!CheckCollision(currentTetrominoX,currentTetrominoY+1,tetrominoTypes[currentTetrominoType][currentRotation]))
                        {
                            currentTetrominoY++;
                            timeToMoveTetrominoDown = moveTetrominoDownTimer;
                        }
                        else
                        {
                            for(int y = 0; y < TETROMINO_SIZE; y++)
                            {
                                for(int x = 0; x < TETROMINO_SIZE; x++)
                                {
                                    const int offset = y * TETROMINO_SIZE + x;

                                    const int *tetromino = tetrominoTypes[currentTetrominoType][currentRotation];

                                    if(tetromino[offset] == 1)
                                    {
                                        const int offset_stage = (y + currentTetrominoY) * STAGE_WIDTH + (x + currentTetrominoX);

                                        stage[offset_stage] = currentTetrominoType + 1;
                                    }
                                }
                            }

                            DeleteLines(score);

                            if(score % WHENINCREASESPEED <= 0) increaseSpeedDown += 0.2f;
                            
                            currentTetrominoType = GetRandomValue(0, 6);
                            currentTetrominoX = tetrominoStartX;
                            currentTetrominoY = tetrominoStartY;
                            currentRotation = 0;
                        }
                    }
                #pragma endregion
            #pragma endregion

            DrawText(TextFormat("Score: %08i", score), WINDOW_WIDTH / 4, 0, 30, RED);

            for(int y = 0; y < STAGE_HEIGHT; y++)
            {
                for(int x = 0; x < STAGE_WIDTH; x++)
                {
                    const int offset = y * STAGE_WIDTH + x;
                    const int color = stage[offset] - 1;
                    const int posX = x * TILE_SIZE + STARTOFFSET_X;
                    const int posY = y * TILE_SIZE + STARTOFFSET_Y;

                    if(stage[offset] == 8)
                        DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, colorTypes[WALL - 1]);
                    else if(stage[offset] == 0)
                        DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, RAYWHITE);
                        else
                        DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, colorTypes[color]);
                    DrawRectangleLines(posX, posY, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
                }
            }
            
            drawTetromino(
                colorTypes[currentTetrominoType],
                STARTOFFSET_X, STARTOFFSET_Y,
                currentTetrominoX, currentTetrominoY,
                tetrominoTypes[currentTetrominoType][currentRotation]
                );

        }
        else
        {
            GameOver();
        }
        EndDrawing();
    }
    UnloadMusicStream(background_Music);
    CloseAudioDevice();

    return 0;
}