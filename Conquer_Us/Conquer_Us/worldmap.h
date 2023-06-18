#pragma once
#define WORLD_WIDTH 77
#define WORLD_HEIGHT 39
#define BAR_WIDTH 50
#define LOGO_WIDTH 95
#define LOGO_HEIGHT 26

int population[1][BAR_WIDTH] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int vaccineMaturity[1][BAR_WIDTH] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int World[WORLD_HEIGHT][WORLD_WIDTH] = { //총합(827개)
      {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
      {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,5,6,5,5,5,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,6,6,6,6,9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,5,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,6,6,6,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,5,5,6,6,6,6,6,6,5,6,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,5,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,9,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,6,6,6,6,6,6,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,6,6,6,6,6,5,5,5,5,5,5,6,6,6,6,6,6,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,6,6,6,6,6,6,6,6,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,6,6,6,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,6,6,6,6,6,6,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,6,6,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,7,5,5,5,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,6,5,5,5,6,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,7,7,7,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,6,6,6,6,6,5,5,5,6,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,6,6,6,6,7,7,7,7,6,6,6,6,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,7,7,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,5,6,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,7,7,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,5,6,5,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,7,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,5,9,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,7,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,7,7,6,6,5,6,7,7,7,7,7,6,6,6,6,6,6,5,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,5,7,7,7,5,6,6,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,5,6,6,6,5,5,6,7,7,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,7,5,6,6,6,6,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,5,6,6,6,5,5,7,7,5,6,6,6,6,5,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,5,5,5,5,5,5,5,5,5,5,5,5,6,7,7,7,7,7,7,6,6,6,5,5,5,5,5,5,6,6,5,5,5,6,6,5,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,6,6,6,6,5,5,5,5,5,5,5,7,7,7,7,7,7,7,7,7,6,6,6,5,5,5,5,5,6,5,5,6,5,5,6,5,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,6,6,6,6,6,5,5,5,5,5,5,5,5,9,7,7,7,7,7,6,6,5,5,5,5,5,5,5,5,5,6,6,6,6,5,5,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,7,7,7,7,6,5,5,5,5,5,5,5,5,5,5,5,6,6,6,5,5,5,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,6,6,6,6,6,6,5,5,5,5,5,5,5,5,7,7,7,7,6,5,5,5,5,5,5,5,5,5,5,5,5,6,6,5,5,5,5,6,6,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,7,6,6,6,6,5,5,5,5,5,5,5,5,5,7,7,7,7,6,5,5,6,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,6,6,6,6,5,5,5,5,5,5,5,5,5,7,7,7,7,5,5,6,6,5,5,5,5,5,5,5,5,5,5,5,6,7,7,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,6,6,6,5,5,5,5,5,5,5,5,5,5,7,7,7,7,5,5,6,5,5,5,5,5,5,5,5,5,5,5,6,7,7,7,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,6,6,5,5,5,5,5,5,5,5,5,5,5,5,7,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,6,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,5,5,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6},
      {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6}
};

int NorthAmerica[16][30] = {         //x = 6, y = 4 북아메리카 (241개)
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,0},
      {0,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0},
      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0},
      {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0},
      {0,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0},
      {0,0,2,0,0,0,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,2,2,2,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,2,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,2,2,2,2,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,2,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,2,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int SouthAmerica[16][15] = { //x = 16, y = 20 남아메리카(74개)
    {2,0,2,2,2,0,1,1,0,0,0,0,0,0,0},
    {0,0,2,2,2,0,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,2,2,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,0,0,2,1,1,1,1,1,0,0},
    {0,0,0,0,0,0,2,2,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,2,2,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,2,2,2,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,2,2,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,2,2,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,2,2,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,2,2,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,2,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,0,0,0,0,0,0}
};

int EuAsia[21][39] = {      //x = 32,y = 6 유라시아(366개)
      {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
      {0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1},
      {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,0,0},
      {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,0,0,0,0},
      {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,0,0,0,1,0,0,0,0,0},
      {0,0,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,0,0,0,1,0,0,0,0,0},
      {0,0,0,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
      {0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,2,2,1,1,0,1,2,2,2,2,2,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,2,2,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int Africa[15][14] = {      //x = 34, y = 17 아프리카(98개)
      {0,1,1,1,1,0,0,0,0,0,0,0,0},
      {0,1,1,1,1,1,1,1,0,0,0,0,0},
      {1,1,1,1,1,1,1,1,0,0,0,0,0},
      {1,1,1,1,1,1,1,1,1,0,0,0,0},
      {1,1,1,1,1,1,1,1,1,1,0,0,0},
      {1,2,2,2,2,2,2,1,1,1,0,0,0},
      {2,2,2,2,2,2,2,2,2,1,1,1,0},
      {0,0,0,0,2,2,2,2,2,1,1,0,0},
      {0,0,0,0,0,2,2,2,2,1,0,0,0},
      {0,0,0,0,0,2,2,2,2,1,0,0,0},
      {0,0,0,0,0,2,2,2,2,1,0,0,1},
      {0,0,0,0,0,2,2,2,2,0,0,1,1},
      {0,0,0,0,0,2,2,2,2,0,0,1,0},
      {0,0,0,0,0,0,2,2,0,0,0,0,0},
      {0,0,0,0,0,0,2,2,0,0,0,0,0}
};

int Oceania[12][8] = {      //x = 57, y = 18 오세아니아(43개)
      {0,1,0,0,0,0,0,0},
      {0,1,1,0,0,0,0,0},
      {0,0,1,0,0,0,0,0},
      {0,0,0,1,1,0,0,0},
      {0,0,0,0,1,1,1,0},
      {0,0,0,0,0,1,1,0},
      {0,0,1,1,1,1,0,0},
      {0,1,2,2,1,1,1,0},
      {1,2,2,2,1,1,1,0},
      {1,1,1,1,1,1,1,1},
      {1,1,0,0,1,1,1,0},
      {0,0,0,0,0,1,1,0}
};

int MyShip[15][20] = {
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
    {0,0,2,2,2,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,1},
    {0,0,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0}
};