#include "../headers/functions.h"
#include "raylib.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
using namespace std;
void drawGrid(vector<pair<int,int>> grid){
    for(pair<int,int> i : grid){
        DrawRectangle(i.first*10,i.second*10,10,10,randomColor());
    }
}
bool search(pair<int,int> i, vector<pair<int,int>> grid){
    for(pair<int,int> j : grid){
        if(j.first == i.first && j.second == i.second){
            return true;
        }
    }
    return false;
}
int find(pair<int,int> i, vector<pair<int,int>> grid){
    for(int j = 0;j<grid.size();j++){
        if(grid[j].first == i.first && grid[j].second == i.second){
            return j;
        }
    }
    return -1;
}
vector<pair<int,int>> updateGrid(vector<pair<int,int>> grid){
    int whiteCells = 0;
    vector<pair<int,int>> newGrid;
    for(int i = 0;i<100;i++){
        for(int j = 0;j<100;j++){
            whiteCells = 0;
            for(int s = 0;s<grid.size();s++){
                if(grid[s].first <= i+1 && grid[s].first >= i-1 && grid[s].second <= j+1 && grid[s].second >= j-1 && !(grid[s].first == i && grid[s].second == j)){
                    whiteCells++;
                }
            }
            if(search({i,j},grid) && (whiteCells == 2 || whiteCells == 3)){
                newGrid.push_back({i,j});
            }else if(!search({i,j},grid) && whiteCells == 3){
                newGrid.push_back({i,j});
            }
            if(i == 29 && j == 29){
                cout << whiteCells << endl;
            }
        }
    }
    return newGrid;
}
Color randomColor(){
    Color colors[] = { DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE,
                       DARKBROWN, GRAY, RED, GOLD, LIME, BLUE, VIOLET, BROWN,
                       LIGHTGRAY, PINK, YELLOW, GREEN, SKYBLUE, PURPLE, BEIGE};
    Color newColor = colors[GetRandomValue(0,20)];
    return newColor;
}