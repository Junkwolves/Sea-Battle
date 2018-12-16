#include "pch.h"
#include "Game_.h"
#include <iostream>


Game_::Game_()
{
}


Game_::~Game_()
{
}

void Game_::NextTurn()
{
	Player_Turn++;
	Move_Number++;
}

void Game_::PrintLine(int LN, int(&P1)[10][10], int(&P2)[10][10])
{
	if (LN < 10)
	{
		std::cout << "        |=|          |=||       " << LN << ".    | "; Hide_Item(P1, LN - 1, 0);
		std::cout << " | "; Hide_Item(P1, LN - 1, 1);
		std::cout << " | ";  Hide_Item(P1, LN - 1, 2);
		std::cout << " | ";  Hide_Item(P1, LN - 1, 3);
		std::cout << " | ";  Hide_Item(P1, LN - 1, 4);
		std::cout << " | ";  Hide_Item(P1, LN - 1, 5);
		std::cout << " | ";  Hide_Item(P1, LN - 1, 6);
		std::cout << " | ";  Hide_Item(P1, LN - 1, 7);
		std::cout << " | ";  Hide_Item(P1, LN - 1, 8);
		std::cout << " | "; Hide_Item(P1, LN - 1, 9); std::cout << " |";

		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		std::cout << "     |                          |    " << LN << ".     | "; Hide_Item(P2, LN - 1, 0);
		std::cout << " | "; Hide_Item(P2, LN - 1, 1);
		std::cout << " | "; Hide_Item(P2, LN - 1, 2);
		std::cout << " | "; Hide_Item(P2, LN - 1, 3);
		std::cout << " | "; Hide_Item(P2, LN - 1, 4);
		std::cout << " | "; Hide_Item(P2, LN - 1, 5);
		std::cout << " | "; Hide_Item(P2, LN - 1, 6);
		std::cout << " | "; Hide_Item(P2, LN - 1, 7);
		std::cout << " | "; Hide_Item(P2, LN - 1, 8);
		std::cout << " | "; Hide_Item(P2, LN - 1, 9);
		std::cout << " |       ||=|          |=| ";
	}
	else
	{
		std::cout << "        |=|__________|=||       " << LN << ".   | "; Hide_Item(P1, LN - 1, 0);
		std::cout << " | "; Hide_Item(P1, LN - 1, 1);
		std::cout << " | "; Hide_Item(P1, LN - 1, 2);
		std::cout << " | "; Hide_Item(P1, LN - 1, 3);
		std::cout << " | "; Hide_Item(P1, LN - 1, 4);
		std::cout << " | "; Hide_Item(P1, LN - 1, 5);
		std::cout << " | "; Hide_Item(P1, LN - 1, 6);
		std::cout << " | "; Hide_Item(P1, LN - 1, 7);
		std::cout << " | "; Hide_Item(P1, LN - 1, 8);
		std::cout << " | "; Hide_Item(P1, LN - 1, 9);
		std::cout << " |";

		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		std::cout << "     |                          |    " << LN << ".    | "; Hide_Item(P2, LN - 1, 0);
		std::cout << " | "; Hide_Item(P2, LN - 1, 1);
		std::cout << " | "; Hide_Item(P2, LN - 1, 2);
		std::cout << " | "; Hide_Item(P2, LN - 1, 3);
		std::cout << " | "; Hide_Item(P2, LN - 1, 4);
		std::cout << " | "; Hide_Item(P2, LN - 1, 5);
		std::cout << " | "; Hide_Item(P2, LN - 1, 6);
		std::cout << " | "; Hide_Item(P2, LN - 1, 7);
		std::cout << " | "; Hide_Item(P2, LN - 1, 8);
		std::cout << " | "; Hide_Item(P2, LN - 1, 9);
		std::cout << " |       ||=|__________|=| ";
	}
}

void Game_::Hide_Item(int(&PL)[10][10], int Leter, int Number)
{
	if (PL[Leter][Number] == 0 || PL[Leter][Number] == 1 || PL[Leter][Number] == 2 || PL[Leter][Number] == 3 || PL[Leter][Number] == 4)
	{
		std::cout << " ";
	}
	else if (PL[Leter][Number] == 5 || PL[Leter][Number] == 6 || PL[Leter][Number] == 7 || PL[Leter][Number] == 8)
	{
		std::cout << "X";
	}
	else if (PL[Leter][Number] == 9)
	{
		std::cout << "-";
	}
	else if (PL[Leter][Number] == 10)
	{
		std::cout << "~";
	}
}

void Game_::Positon_Check(int(&PL)[10][10], int Letter, int Number)
{
	if (Letter <= 9 && Number <= 9 && Letter >= 0 && Number >= 0)
	{
		PL[Letter][Number] = 10;
	}
}

bool Game_::Barrier_Сheck(int(&PL)[10][10], int Letter, int Number, int Equally)
{
	if (Letter <= 9 && Number <= 9 && Letter >= 0 && Number >= 0)
	{
		if (PL[Letter][Number] == Equally)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void Game_::Around_Check_1(int(&PL)[10][10], int Letter, int Number)
{
	Positon_Check(PL, Letter - 1, Number); // U 
	Positon_Check(PL, Letter + 1, Number); // D 
	Positon_Check(PL, Letter, Number + 1); // R
	Positon_Check(PL, Letter, Number - 1); // L
	Positon_Check(PL, Letter - 1, Number + 1); // U + R
	Positon_Check(PL, Letter - 1, Number - 1); // U + L
	Positon_Check(PL, Letter + 1, Number + 1); // D + R
	Positon_Check(PL, Letter + 1, Number - 1); // D + L

	if (Player_Turn % 2 == 0)
	{
		P2_Kill++;
		SDS_P1--;
	}
	else
	{
		P1_Kill++;
		SDS_P2--;
	}
}

bool Game_::Around_Check_2(int(&PL)[10][10], int Letter, int Number)
{
	if (Barrier_Сheck(PL, Letter + 1, Number, 6))
	{
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter + 2, Number + 1); // SD + R
		Positon_Check(PL, Letter + 2, Number - 1); // SD + L
		Positon_Check(PL, Letter + 2, Number); // SD
		Positon_Check(PL, Letter - 1, Number); // U 
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter, Number - 1); // L

		return true;
	}
	else if (Barrier_Сheck(PL, Letter - 1, Number, 6))
	{
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 2, Number + 1); // U + R
		Positon_Check(PL, Letter - 2, Number - 1); // U + L
		Positon_Check(PL, Letter - 2, Number); // SU
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter, Number + 1); // R

		return true;
	}
	else if (Barrier_Сheck(PL, Letter, Number + 1, 6))
	{
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number + 2); // SR + U
		Positon_Check(PL, Letter + 1, Number + 2); // SR + D
		Positon_Check(PL, Letter, Number + 2); // SR
		Positon_Check(PL, Letter - 1, Number); // U 
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter, Number - 1); // L

		return true;
	}
	else if (Barrier_Сheck(PL, Letter, Number - 1, 6))
	{
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number - 2); // U + SL
		Positon_Check(PL, Letter + 1, Number - 2); // D + sL
		Positon_Check(PL, Letter, Number - 2); // sL
		Positon_Check(PL, Letter - 1, Number); // U 
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter, Number + 1); // R

		return true;
	}
	else
	{
		return false;
	}
}

bool Game_::Around_Check_3(int(&PL)[10][10], int Letter, int Number)
{
	if (Barrier_Сheck(PL, Letter, Number + 1, 7) && Barrier_Сheck(PL, Letter, Number - 1, 7))
	{
		Positon_Check(PL, Letter - 1, Number); // U 
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter, Number + 2); // SR
		Positon_Check(PL, Letter, Number - 2); // sL
		Positon_Check(PL, Letter - 1, Number - 2); // U + SL
		Positon_Check(PL, Letter + 1, Number - 2); // D + sL
		Positon_Check(PL, Letter - 1, Number + 2); // U + SR
		Positon_Check(PL, Letter + 1, Number + 2); // D + SR

		return true;
	}
	else if (Barrier_Сheck(PL, Letter, Number + 1, 7) && Barrier_Сheck(PL, Letter, Number + 2, 7))
	{
		Positon_Check(PL, Letter - 1, Number); // U 
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 2, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number + 2); // U + SR
		Positon_Check(PL, Letter + 1, Number + 2); // D + SR
		Positon_Check(PL, Letter - 1, Number + 3); // U + SSR
		Positon_Check(PL, Letter + 1, Number + 3); // D + SSR
		Positon_Check(PL, Letter, Number + 3); // SSR

		return true;
	}
	else if (Barrier_Сheck(PL, Letter, Number - 1, 7) && Barrier_Сheck(PL, Letter, Number - 2, 7))
	{
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number); // U 
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter - 1, Number - 2); // U + SL
		Positon_Check(PL, Letter + 1, Number - 2); // D + SL
		Positon_Check(PL, Letter - 1, Number - 3); // U + SSL
		Positon_Check(PL, Letter + 1, Number - 3); // D + SSL
		Positon_Check(PL, Letter, Number - 3); // SSL

		return true;
	}
	else if (Barrier_Сheck(PL, Letter - 1, Number, 7) && Barrier_Сheck(PL, Letter + 1, Number, 7))
	{
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 2, Number + 1); // SU + R
		Positon_Check(PL, Letter - 2, Number - 1); // SU + L
		Positon_Check(PL, Letter - 2, Number); // SU
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter + 2, Number + 1); // SD + R
		Positon_Check(PL, Letter + 2, Number - 1); // SD + L
		Positon_Check(PL, Letter + 2, Number); // SD

		return true;
	}
	else if (Barrier_Сheck(PL, Letter - 1, Number, 7) && Barrier_Сheck(PL, Letter - 2, Number, 7))
	{
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 2, Number + 1); // SU + R
		Positon_Check(PL, Letter - 2, Number - 1); // SU + L
		Positon_Check(PL, Letter - 3, Number + 1); // SSU + R
		Positon_Check(PL, Letter - 3, Number - 1); // SSU + L
		Positon_Check(PL, Letter - 3, Number); // SSU

		return true;
	}
	else if (Barrier_Сheck(PL, Letter + 1, Number, 7) && Barrier_Сheck(PL, Letter + 2, Number, 7))
	{
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 1, Number); // U
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter + 2, Number + 1); // SD + R
		Positon_Check(PL, Letter + 2, Number - 1); // SD + L
		Positon_Check(PL, Letter + 3, Number + 1); // SSD + R
		Positon_Check(PL, Letter + 3, Number - 1); // SSD + L
		Positon_Check(PL, Letter + 3, Number); // SSD

		return true;
	}
	else
	{
		return false;
	}
}

bool Game_::Around_Check_4(int(&PL)[10][10], int Letter, int Number)
{
	if (Barrier_Сheck(PL, Letter + 1, Number, 8) && Barrier_Сheck(PL, Letter + 2, Number, 8) && Barrier_Сheck(PL, Letter + 3, Number, 8))
	{
		Positon_Check(PL, Letter - 1, Number); // U
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter + 2, Number + 1); // SD + R
		Positon_Check(PL, Letter + 2, Number - 1); // SD + L
		Positon_Check(PL, Letter + 3, Number + 1); // SSD + R
		Positon_Check(PL, Letter + 3, Number - 1); // SSD + L
		Positon_Check(PL, Letter + 4, Number + 1); // SSD + R
		Positon_Check(PL, Letter + 4, Number - 1); // SSD + L
		Positon_Check(PL, Letter + 4, Number); // SSD

		return true;
	}
	else if (Barrier_Сheck(PL, Letter - 1, Number, 8) && Barrier_Сheck(PL, Letter - 2, Number, 8) && Barrier_Сheck(PL, Letter - 3, Number, 8))
	{
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 2, Number + 1); // SU + R
		Positon_Check(PL, Letter - 2, Number - 1); // SU + L
		Positon_Check(PL, Letter - 3, Number + 1); // SSU + R
		Positon_Check(PL, Letter - 3, Number - 1); // SSU + L
		Positon_Check(PL, Letter - 4, Number + 1); // SSSU + R
		Positon_Check(PL, Letter - 4, Number - 1); // SSSU + L
		Positon_Check(PL, Letter - 4, Number); // SSSU

		return true;
	}
	else if (Barrier_Сheck(PL, Letter - 1, Number, 8) && Barrier_Сheck(PL, Letter - 2, Number, 8) && Barrier_Сheck(PL, Letter + 1, Number, 8))
	{
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter + 2, Number + 1); // SD + R
		Positon_Check(PL, Letter + 2, Number - 1); // SD + L
		Positon_Check(PL, Letter + 2, Number); // SD
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 2, Number + 1); // SU + R
		Positon_Check(PL, Letter - 2, Number - 1); // SU + L
		Positon_Check(PL, Letter - 3, Number + 1); // SSU + R
		Positon_Check(PL, Letter - 3, Number - 1); // SSU + L
		Positon_Check(PL, Letter - 3, Number); // SSU

		return true;
	}
	else if (Barrier_Сheck(PL, Letter - 1, Number, 8) && Barrier_Сheck(PL, Letter + 1, Number, 8) && Barrier_Сheck(PL, Letter + 2, Number, 8))
	{
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 2, Number + 1); // SU + R
		Positon_Check(PL, Letter - 2, Number - 1); // SU + L
		Positon_Check(PL, Letter - 2, Number); // SU
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter + 2, Number + 1); // SD + R
		Positon_Check(PL, Letter + 2, Number - 1); // SD + L
		Positon_Check(PL, Letter + 3, Number + 1); // SSD + R
		Positon_Check(PL, Letter + 3, Number - 1); // SSD + L
		Positon_Check(PL, Letter + 3, Number); // SSD

		return true;
	}
	else if (Barrier_Сheck(PL, Letter, Number - 1, 8) && Barrier_Сheck(PL, Letter, Number - 2, 8) && Barrier_Сheck(PL, Letter, Number - 3, 8))
	{
		Positon_Check(PL, Letter, Number + 1); // R
		Positon_Check(PL, Letter - 1, Number); // U
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number - 2); // U + SL
		Positon_Check(PL, Letter + 1, Number - 2); // D + SL
		Positon_Check(PL, Letter - 1, Number - 3); // U + SSL
		Positon_Check(PL, Letter + 1, Number - 3); // D + SSL
		Positon_Check(PL, Letter - 1, Number - 4); // U + SSSL
		Positon_Check(PL, Letter + 1, Number - 4); // D + SSSL
		Positon_Check(PL, Letter, Number - 4); // SSSL

		return true;
	}
	else if (Barrier_Сheck(PL, Letter, Number + 1, 8) && Barrier_Сheck(PL, Letter, Number + 2, 8) && Barrier_Сheck(PL, Letter, Number + 3, 8))
	{
		Positon_Check(PL, Letter, Number - 1); // L
		Positon_Check(PL, Letter - 1, Number); // U
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 1, Number + 2); // U + SR
		Positon_Check(PL, Letter + 1, Number + 2); // D + SR
		Positon_Check(PL, Letter - 1, Number + 3); // U + SSR
		Positon_Check(PL, Letter + 1, Number + 3); // D + SSR
		Positon_Check(PL, Letter - 1, Number + 4); // U + SSSR
		Positon_Check(PL, Letter + 1, Number + 4); // D + SSSR
		Positon_Check(PL, Letter, Number + 4); // SSSR

		return true;
	}
	else if (Barrier_Сheck(PL, Letter, Number - 1, 8) && Barrier_Сheck(PL, Letter, Number + 1, 8) && Barrier_Сheck(PL, Letter, Number + 2, 8))
	{
		Positon_Check(PL, Letter - 1, Number); // U
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 1, Number + 2); // U + SR
		Positon_Check(PL, Letter + 1, Number + 2); // D + SR
		Positon_Check(PL, Letter - 1, Number - 2); // U + SL
		Positon_Check(PL, Letter + 1, Number - 2); // D + SL
		Positon_Check(PL, Letter, Number - 2); // SL
		Positon_Check(PL, Letter - 1, Number + 3); // U + SSR
		Positon_Check(PL, Letter + 1, Number + 3); // D + SSR
		Positon_Check(PL, Letter, Number + 3); // SSR

		return true;
	}
	else if (Barrier_Сheck(PL, Letter, Number - 1, 8) && Barrier_Сheck(PL, Letter, Number - 2, 8) && Barrier_Сheck(PL, Letter, Number + 1, 8))
	{
		Positon_Check(PL, Letter - 1, Number); // U
		Positon_Check(PL, Letter + 1, Number); // D
		Positon_Check(PL, Letter + 1, Number + 1); // D + R
		Positon_Check(PL, Letter + 1, Number - 1); // D + L
		Positon_Check(PL, Letter - 1, Number + 1); // U + R
		Positon_Check(PL, Letter - 1, Number - 1); // U + L
		Positon_Check(PL, Letter - 1, Number + 2); // U + SR
		Positon_Check(PL, Letter - 1, Number - 2); // U + SL
		Positon_Check(PL, Letter + 1, Number + 2); // D + SR
		Positon_Check(PL, Letter + 1, Number - 2); // D + SL
		Positon_Check(PL, Letter + 1, Number - 3); // D + SSL
		Positon_Check(PL, Letter - 1, Number - 3); // U + SSL
		Positon_Check(PL, Letter, Number - 3); // SSL
		Positon_Check(PL, Letter, Number + 2); // SR

		return true;
	}
	else
	{
	return false;
	}
}

int Game_::Shot(int(&PL)[10][10], int Letter, int Number)
{
	int You_Hit = 0;
	if (PL[Letter - 1][Number] == 0)
	{
		PL[Letter - 1][Number] = 9;
	}
	else if (PL[Letter - 1][Number] == 1)
	{
		You_Hit = 1;
		Player_Turn--;
		PL[Letter - 1][Number] = 5;
		Around_Check_1(PL, Letter - 1, Number);
	}
	else if (PL[Letter - 1][Number] == 2)
	{
		You_Hit = 1;
		Player_Turn--;
		PL[Letter - 1][Number] = 6;

		if (Around_Check_2(PL, Letter - 1, Number))
		{
			if (Player_Turn % 2 == 0)
			{
				P2_Kill++;
				DDS_P1--;
			}
			else
			{
				P1_Kill++;
				DDS_P2--;
			}
		}
	}
	else if (PL[Letter - 1][Number] == 3)
	{
		You_Hit = 1;
		Player_Turn--;
		PL[Letter - 1][Number] = 7;

		if (Around_Check_3(PL, Letter - 1, Number))
		{
			if (Player_Turn % 2 == 0)
			{
				P2_Kill++;
				TDS_P1--;
			}
			else
			{
				P1_Kill++;
				TDS_P2--;
			}
		}
	}
	else if (PL[Letter - 1][Number] == 4)
	{
		You_Hit = 1;
		Player_Turn--;
		PL[Letter - 1][Number] = 8;

		if (Around_Check_4(PL, Letter - 1, Number))
		{
			if (Player_Turn % 2 == 0)
			{
				P2_Kill++;
				FDS_P1--;
			}
			else
			{
				P1_Kill++;
				FDS_P2--;
			}
		}
	}
	else if (PL[Letter - 1][Number] == 5 || PL[Letter - 1][Number] == 6 || PL[Letter - 1][Number] == 7 || PL[Letter - 1][Number] == 8 || PL[Letter - 1][Number] == 9 || PL[Letter - 1][Number] == 10)
	{
		You_Hit = 3;
		Player_Turn--;
		Move_Number--;
	}

	return You_Hit;
}

int Game_::TryHit(int(&P1)[10][10], int(&P2)[10][10], int Letter, int Number)
{
	if (Player_Turn % 2 == 0)
	{
		return Shot(P2, Letter, Number);
	}
	else
	{
		return Shot(P1, Letter, Number);
	}
}

void Game_::PrintMap(int(&P1)[10][10], int(&P2)[10][10], int X_RAY)
{
	std::cout << "        |=-__________-=||=------------------------------------------------------------------------------------------------------------------------------------------------=||=-__________-=| " << std::endl;
	std::cout << "        |=|__________|=||-------------------------------------------------------------------------=------------------------------------------------------------------------||=|__________|=| " << std::endl;
	std::cout << "        |=|          |=||                                                                         |                                                                        ||=|          |=| " << std::endl;
	std::cout << "        |=|          |=||                            PLAYER |                       |--------------------------|                          PLAYER ||                        ||=| # = " << SDS_P2 << "    |=| " << std::endl;
	std::cout << "        |=| # = " << SDS_P1 << "    |=||                                                           | >---------INFO---------< |                                                           ||=|          |=| " << std::endl;
	std::cout << "        |=|          |=||               A   B   C   D   E   F   G   H   I   J       |                          |             A   B   C   D   E   F   G   H   I   J         ||=|          |=| " << std::endl;
	std::cout << "        |=| ## = " << DDS_P1 << "   |=||                                                           |     > Move Number:  " << Move_Number;
	if (Move_Number < 10)
	{
		std::cout << "    |                                                           ||=| ## = " << DDS_P2 << "   |=| " << std::endl;
	}
	else if (Move_Number >= 10 && Move_Number < 100)
	{
		std::cout << "   |                                                           ||=| ## = " << DDS_P2 << "   |=|  " << std::endl;
	}
	else if (Move_Number >= 100)
	{
		std::cout << "  |                                                           ||=| ## = " << DDS_P2 << "   |=|  " << std::endl;
	}
	PrintLine(1, P1, P2); std::cout << std::endl;
	std::cout << "        |=|          |=||           ---------------------------------------------   |                          |         ---------------------------------------------     ||=|          |=| " << std::endl;
	PrintLine(2, P1, P2); std::cout << std::endl;
	std::cout << "        |=| ### = " << TDS_P1 << "  |=||           ---------------------------------------------   | > P1 Kill Counter: " << P1_Kill; // Убийства игрока 1
	if (P1_Kill >= 10)
	{
		std::cout << "    |         ---------------------------------------------     ||=| ### = " << TDS_P2 << "  |=| " << std::endl;
	}
	else
	{
		std::cout << "     |         ---------------------------------------------     ||=| ### = " << TDS_P2 << "  |=| " << std::endl;
	}
	PrintLine(3, P1, P2); std::cout << std::endl;
	std::cout << "        |=|          |=||           ---------------------------------------------   |                          |         ---------------------------------------------     ||=|          |=| " << std::endl;
	PrintLine(4, P1, P2); std::cout << std::endl;
	std::cout << "        |=| #### = " << FDS_P1 << " |=||           ---------------------------------------------   | > P2 Kill Counter: " << P2_Kill; //  Убийства игрока 2
	if (P2_Kill >= 10)
	{
		std::cout << "    |         ---------------------------------------------     ||=| #### = " << FDS_P2 << " |=| " << std::endl;
	}
	else
	{
		std::cout << "     |         ---------------------------------------------     ||=| #### = " << FDS_P2 << " |=| " << std::endl;
	}
	PrintLine(5, P1, P2); std::cout << std::endl;
	std::cout << "        |=|          |=||           ---------------------------------------------   |                          |         ---------------------------------------------     ||=|          |=| " << std::endl;
	PrintLine(6, P1, P2); std::cout << std::endl;
	std::cout << "        |=|          |=||           ---------------------------------------------   |  ";
	if (Player_Turn % 2 == 0)
	{
		std::cout << "   > PLAYER 2 TURN!     |         ---------------------------------------------     ||=|          |=| " << std::endl;
	}
	else
	{
		std::cout << "   > PLAYER 1 TURN!     |         ---------------------------------------------     ||=|          |=| " << std::endl;
	}
	PrintLine(7, P1, P2); std::cout << std::endl;
	std::cout << "        |=|          |=||           ---------------------------------------------   |                          |         ---------------------------------------------     ||=|          |=|  " << std::endl;
	PrintLine(8, P1, P2); std::cout << std::endl;
	std::cout << "        |=|          |=||           ---------------------------------------------   |                          |         ---------------------------------------------     ||=|          |=|  " << std::endl;
	PrintLine(9, P1, P2); std::cout << std::endl;
	std::cout << "        |=|          |=||           ---------------------------------------------   |                          |         ---------------------------------------------     ||=|          |=|  " << std::endl;
	PrintLine(10, P1, P2); std::cout << std::endl;
	std::cout << "        |=|__________|=||                                                           |--------------------------|                                                           ||=|__________|=|  " << std::endl;
	std::cout << "        |=|-        -|=||                                                                         |                                                                        ||=-          -=|  " << std::endl;
	std::cout << "        |=------------=||-------------------------------------------------------------------------=------------------------------------------------------------------------||=------------=|  " << std::endl;
	std::cout << "        |--------------||--------------------------------------------------------------------------------------------------------------------------------------------------||--------------|  " << std::endl;

	if (X_RAY == 1)
	{
	Print_X_RAY(P1, P2);
	}
}

void Game_::Show_Item(int(&PL)[10][10], int Leter, int Number)
{
		if (PL[Leter][Number] == 1 || PL[Leter][Number] == 2 || PL[Leter][Number] == 3 || PL[Leter][Number] == 4)
		{
			std::cout << "# ";
		}
		else if (PL[Leter][Number] == 5 || PL[Leter][Number] == 6 || PL[Leter][Number] == 7 || PL[Leter][Number] == 8)
		{
			std::cout << "X ";
		}
		else if (PL[Leter][Number] == 9 || PL[Leter][Number] == 10 || PL[Leter][Number] == 0)
		{
			std::cout << "  ";
		}
}

void Game_::Print_X_RAY_Line(int LN, int(&P1)[10][10], int(&P2)[10][10])
{
	if (LN < 10)
	{
		Show_Item(P1, LN - 1, 0); Show_Item(P1, LN - 1, 1); Show_Item(P1, LN - 1, 2); Show_Item(P1, LN - 1, 3);
		Show_Item(P1, LN - 1, 4); Show_Item(P1, LN - 1, 5); Show_Item(P1, LN - 1, 6); Show_Item(P1, LN - 1, 7);
		Show_Item(P1, LN - 1, 8); Show_Item(P1, LN - 1, 9);
		std::cout << "              " << LN << " ";
		Show_Item(P2, LN - 1, 0); Show_Item(P2, LN - 1, 1); Show_Item(P2, LN - 1, 2); Show_Item(P2, LN - 1, 3);
		Show_Item(P2, LN - 1, 4); Show_Item(P2, LN - 1, 5); Show_Item(P2, LN - 1, 6); Show_Item(P2, LN - 1, 7);
		Show_Item(P2, LN - 1, 8); Show_Item(P2, LN - 1, 9);
		std::cout << std::endl;
	}
	else
	{
		Show_Item(P1, LN - 1, 0); Show_Item(P1, LN - 1, 1); Show_Item(P1, LN - 1, 2); Show_Item(P1, LN - 1, 3);
		Show_Item(P1, LN - 1, 4); Show_Item(P1, LN - 1, 5); Show_Item(P1, LN - 1, 6); Show_Item(P1, LN - 1, 7);
		Show_Item(P1, LN - 1, 8); Show_Item(P1, LN - 1, 9);
		std::cout << "             " << LN << " ";
		Show_Item(P2, LN - 1, 0); Show_Item(P2, LN - 1, 1); Show_Item(P2, LN - 1, 2); Show_Item(P2, LN - 1, 3);
		Show_Item(P2, LN - 1, 4); Show_Item(P2, LN - 1, 5); Show_Item(P2, LN - 1, 6); Show_Item(P2, LN - 1, 7);
		Show_Item(P2, LN - 1, 8); Show_Item(P2, LN - 1, 9);
		std::cout << std::endl;
	}
}

void Game_::Print_X_RAY(int(&P1)[10][10], int(&P2)[10][10])
{

	std::cout << std::endl;
	std::cout << "         __________________________________________________________________________________________________________________________________________________________________________________   " << std::endl;
	std::cout << "        |__________________________________________________________________________________________________________________________________________________________________________________|  " << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "                                                                    P1   A B C D E F G H I J            P2   A B C D E F G H I J                                                             "<< std::endl;
	std::cout << "                                                                       1 "; Print_X_RAY_Line(1, P1, P2);
	std::cout << "                                                                       2 "; Print_X_RAY_Line(2, P1, P2);
	std::cout << "                                                                       3 "; Print_X_RAY_Line(3, P1, P2);
	std::cout << "                                                                       4 "; Print_X_RAY_Line(4, P1, P2);
	std::cout << "                                                                       5 "; Print_X_RAY_Line(5, P1, P2);
	std::cout << "                                                                       6 "; Print_X_RAY_Line(6, P1, P2);
	std::cout << "                                                                       7 "; Print_X_RAY_Line(7, P1, P2);
	std::cout << "                                                                       8 "; Print_X_RAY_Line(8, P1, P2);
	std::cout << "                                                                       9 "; Print_X_RAY_Line(9, P1, P2);
	std::cout << "                                                                      10 "; Print_X_RAY_Line(10, P1, P2);

	std::cout << std::endl;
	std::cout << "         __________________________________________________________________________________________________________________________________________________________________________________   " << std::endl;
	std::cout << "        |__________________________________________________________________________________________________________________________________________________________________________________|  " << std::endl;
	std::cout << std::endl << std::endl;
}