#pragma once

#include "Game_.h"

bool GameOver(Game_ &Game_, int(&P1)[10][10], int(&P2)[10][10], int SIZE, int &Winner);

void WinnerCheck(int Winner);