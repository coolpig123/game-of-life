#include "../include/raylib.h"
#include "../headers/functions.h"
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    int fps = 60;
    bool pause = true;
    vector<pair<int,int>> grid = {};
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "game-of-life");
    SetTargetFPS(fps);          
    while (!WindowShouldClose())   
    {
        BeginDrawing();
            ClearBackground(BLACK);
            drawGrid(grid);
            DrawText(TextFormat("population : %i",grid.size()),0,0,30,GREEN);
            DrawText(TextFormat("fps : %i",fps),0,30,30,GREEN);
            if(pause){
                DrawText(TextFormat("paused"),0,60,30,GREEN);
            }
        EndDrawing();
        if(!pause){
                grid = updateGrid(grid);
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !search({GetMouseX()/10,GetMouseY()/10},grid)){
                grid.push_back({GetMouseX()/10,GetMouseY()/10});
            }else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && find({GetMouseX()/10,GetMouseY()/10},grid) != -1){
                grid.erase(grid.begin()+find({GetMouseX()/10,GetMouseY()/10},grid));
            }
            if(IsKeyPressed(KEY_SPACE)){
                pause = !pause;
            }
            if(IsKeyDown(KEY_LEFT) && fps > 30){
                fps--;
                SetTargetFPS(fps);
            }else if(IsKeyDown(KEY_RIGHT)){
                fps++;
                SetTargetFPS(fps);
            }
            if(IsKeyPressed(KEY_BACKSPACE)){
                grid.clear();
            }
    }
    CloseWindow();      
}