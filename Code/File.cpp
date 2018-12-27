#include "pch.h"
#include "File.h"
#include "Game_.h"

int ReadFile(Game_ & Player, int(&P1)[10][10], int Player_Number)
{
	int T_SDS = 0;
	int T_DDS = 0;
	int T_TDS = 0;
	int T_FDS = 0;

	if (Player_Number == 1)
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (P1[i][j] == 1)
				{
					T_SDS++;
				}
				else if (P1[i][j] == 2)
				{
					T_DDS++;
				}
				else if (P1[i][j] == 3)
				{
					T_TDS++;
				}
				else if (P1[i][j] == 4)
				{
					T_FDS++;
				}
			}

		}

		Player.SDS_P1 = T_SDS;
		Player.DDS_P1 = T_DDS / 2;
		Player.TDS_P1 = T_TDS / 3;
		Player.FDS_P1 = T_FDS / 4;

		if (Player.SDS_P1 >= 10 || Player.DDS_P1 >= 10 || Player.TDS_P1 >= 10 || Player.FDS_P1 >= 10)
		{
			return 1;
		}
	}
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (P1[i][j] == 1)
				{
					T_SDS++;
				}
				else if (P1[i][j] == 2)
				{
					T_DDS++;
				}
				else if (P1[i][j] == 3)
				{
					T_TDS++;
				}
				else if (P1[i][j] == 4)
				{
					T_FDS++;
				}
			}
		}

		Player.SDS_P2 = T_SDS;
		Player.DDS_P2 = T_DDS / 2;
		Player.TDS_P2 = T_TDS / 3;
		Player.FDS_P2 = T_FDS / 4;

		if (Player.SDS_P2 >= 10 || Player.DDS_P2 >= 10 || Player.TDS_P2 >= 10 || Player.FDS_P2 >= 10)
		{
			return 1;
		}
	}
}
