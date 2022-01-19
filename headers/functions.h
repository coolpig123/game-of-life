#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;
void drawGrid(vector<pair<int,int>> grid);
vector<pair<int,int>> updateGrid(vector<pair<int,int>> grid);
bool search(pair<int,int> i, vector<pair<int,int>> grid);
int find(pair<int,int> i, vector<pair<int,int>> grid);
Color randomColor();