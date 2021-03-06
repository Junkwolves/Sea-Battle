#include "pch.h"
#include "Game_Over.h"

#include <iostream>

bool GameOver(Game_ & Game, int(&P1)[10][10], int(&P2)[10][10], int SIZE, int & Winner)
{
	int Win = 0;

	if (Game.Player_Turn % 2 == 0)
	{
		Winner = 1;
	}
	else
	{
		Winner = 2;
	}

	if (Winner == 1)
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (P1[i][j] == 1 || P1[i][j] == 2 || P1[i][j] == 3 || P1[i][j] == 4)
				{
					Win++;
				}
			}
		}
	}
	else if (Winner == 2)
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (P2[i][j] == 1 || P2[i][j] == 2 || P2[i][j] == 3 || P2[i][j] == 4)
				{
					Win++;
				}
			}
		}
	}

	if (Win == 0) { return true; }
	else { return false; }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- END

void WinnerCheck(int Winner)
{
	if (Winner == 2)
	{
		std::cout << "        ||------------|||--------------------------------------------------------------------------------------------------------------------------------------------------|||------------||" << std::endl;
		std::cout << "        ||            |||                                                                                                                                                  |||            || " << std::endl;
		std::cout << "        ||=----------=|||-------------------------------------------------------------------PLAYER-1-WINS------------------------------------------------------------------|||=----------=|| " << std::endl;
		std::cout << "        ||            |||                                                                                                                                                  |||            || " << std::endl;
		std::cout << "        ||____________|||--------------------------------------------------------------------------------------------------------------------------------------------------|||____________||" << std::endl;
	}
	else
	{
		std::cout << "        ||------------|||--------------------------------------------------------------------------------------------------------------------------------------------------|||------------||" << std::endl;
		std::cout << "        ||            |||                                                                                                                                                  |||            || " << std::endl;
		std::cout << "        ||=----------=|||-------------------------------------------------------------------PLAYER-2-WINS------------------------------------------------------------------|||=----------=|| " << std::endl;
		std::cout << "        ||            |||                                                                                                                                                  |||            || " << std::endl;
		std::cout << "        ||____________|||--------------------------------------------------------------------------------------------------------------------------------------------------|||____________||" << std::endl;
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- END
