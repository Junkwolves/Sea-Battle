#include "pch.h"
#include "Menu.h"
#include "Choise_L_N.h"
#include <iostream>
#include <conio.h>

int tmp = 10;

int tmp_2 = 4;

enum class KEYS_2
{
	ESC = 27,
	W = 87,
	w = 119,
	S = 83,
	s = 115,
	A = 65,
	a = 97,
	D = 68,
	d = 100,
	Enter = 13
};

void Prin_Menu(int Choice)
{
	system("CLS");

	if (tmp == 1 && Choice == 1)
	{
		Choice = 2;
	}
	else if (tmp == 2 && Choice == 2)
	{
		Choice = 1;
	}
	else if (tmp == 2 && Choice == 1)
	{
		Choice = 3;
	}
	else if (tmp == 1 && Choice == 2)
	{
		Choice = 3;
	}
	else if (tmp == 3 && Choice == 1)
	{
		Choice = 1;
	}
	else if (tmp == 3 && Choice == 2)
	{
		Choice = 2;
	}
	else if (tmp == 3 && tmp_2 == 4 && Choice == 5)
	{
		Choice = 3; tmp_2 = 5;
	}
	else if (tmp == 3 && tmp_2 == 4 && Choice == 4)
	{
		Choice = 3; tmp_2 = 5;
	}
	else if (tmp == 3 && tmp_2 == 5 && Choice == 4)
	{
		Choice = 3; tmp_2 = 4;
	}
	else if (tmp == 3 && tmp_2 == 5 && Choice == 5)
	{
		Choice = 3; tmp_2 = 4;
	}
	else
	{

	}

	std::cout << std::endl << std::endl << std::endl;

	std::cout << "        ____________________________________________________________________________________________________________________________________________________________________________________ " << std::endl;
	std::cout << "        |=|____________||__________________________________________________________________________________________________________________________________________________||____________|=| " << std::endl;
	std::cout << "        |=|____________||__________________________________________________________________________________________________________________________________________________||____________|=| " << std::endl;
	std::cout << "        |=|            ||                                                                                                                                                  ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                  ===============================================                                                 ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                  ||                                           ||                                                 ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                  ||        XX   XX XXXXX XX  XX XX  XX        ||                                                 ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                  ||        XXX XXX XX    XXX XX XX  XX        ||                                                 ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                  ||        XX X XX XXXX  XX XXX XX  XX        ||                                                 ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                  ||        XX   XX XX    XX  XX XX  XX        ||                                                 ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                  ||        XX   XX XXXXX XX  XX  XXXX         ||                                                 ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                  ||                                           ||                                                 ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                  ===============================================                                                 ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                                                                                                                  ||            |=| " << std::endl;
	std::cout << "        |=|            ||__________________________________________________________________________________________________________________________________________________||            |=| " << std::endl;
	std::cout << "        |=|            ||__________________________________________________________________________________________________________________________________________________||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                                                                                                                  ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                     _________________________________________________________________________                                    ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                     |__|-----------------------------------------------------------------|__|                                    ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;

	if (Choice == 2 || Choice == 3)
	{
	std::cout << "        |=|            ||                                      | |              CONTINUE                                           | |                                     ||            |=| " << std::endl;
	}
	else if (Choice == 1)
	{
	std::cout << "        |=|            ||                                      | |            >  CONTINUE                                          | |                                     ||            |=| " << std::endl;
	tmp = 1;
	}

	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;

	if (Choice == 1 || Choice == 2)
	{
		if (tmp_2 == 4)
		{
	std::cout << "        |=|            ||                                      | |              X-RAY : OFF / on                                   | |                                     ||            |=| " << std::endl;
	tmp_2 = 4;
		}
		else if (tmp_2 == 5)
		{
	std::cout << "        |=|            ||                                      | |              X-RAY : off / ON                                   | |                                     ||            |=| " << std::endl;
	tmp_2 = 5;
		}
	}
	else if (Choice == 3 && tmp_2 == 4)
	{
	std::cout << "        |=|            ||                                      | |            >  X-RAY : OFF / on                                  | |                                     ||            |=| " << std::endl;
	tmp_2 = 4;
	tmp = 3;
	}
	else if (Choice == 3 && tmp_2 == 5)
	{
	std::cout << "        |=|            ||                                      | |            >  X-RAY : off / ON                                  | |                                     ||            |=| " << std::endl;
	tmp_2 = 5;
	tmp = 3;
	}

	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;

	if (Choice == 1 || Choice == 3)
	{
	std::cout << "        |=|            ||                                      | |              EXIT                                               | |                                     ||            |=| " << std::endl;
	}
	else if (Choice == 2)
	{
	std::cout << "        |=|            ||                                      | |            >  EXIT                                              | |                                     ||            |=| " << std::endl;
	tmp = 2;
	}

	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                      | |                                                                 | |                                     ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                      |_|                                                                 |_|                                     ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                     |  |_________________________________________________________________|  |                                    ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                     |__|_________________________________________________________________|__|                                    ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                                                                                                                  ||            |=| " << std::endl;
	std::cout << "        |=|            ||__________________________________________________________________________________________________________________________________________________||            |=| " << std::endl;
	std::cout << "        |=|            ||__________________________________________________________________________________________________________________________________________________||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                                                                                                                  ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                                                                                                                  ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                                                                                                                  ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                                                                                                                  ||            |=| " << std::endl;
	std::cout << "        |=|            ||                                                                                                                                                  ||            |=| " << std::endl;
	std::cout << "        |=|____________||__________________________________________________________________________________________________________________________________________________||____________|=| " << std::endl;
	std::cout << "        |=|____________||__________________________________________________________________________________________________________________________________________________||____________|=| " << std::endl;

	std::cout << "                                                                                                ";
}

int Choice_Item()
{
	while (true)
	{
		if (_kbhit())
		{
			switch (static_cast<KEYS_2>(_getch()))
			{
			case KEYS_2::W:
				Prin_Menu(1);
				return 1;
				break;

			case KEYS_2::w:
				Prin_Menu(1);
				return 1;
				break;

			case KEYS_2::S:
				Prin_Menu(2);
				return 2;
				break;

			case KEYS_2::s:
				Prin_Menu(2);
				return 2;
				break;

			case KEYS_2::A:
				if (tmp == 3)
				{
				Prin_Menu(4);
				return 1;
				}
				return 1;
				break;

			case KEYS_2::a:
				if (tmp == 3)
				{
					Prin_Menu(4);
					return 1;
				}
				return 1;
				break;

			case KEYS_2::D:
				if (tmp == 3)
				{
					Prin_Menu(5);
					return 1;
				}
				return 1;
				break;

			case KEYS_2::d:
				if (tmp == 3)
				{
					Prin_Menu(5);
					return 1;
				}
				return 1;
				break;

			case KEYS_2::Enter:
				if (tmp == 2)
				{
					exit(0);
				}
				else if (tmp == 1)
				{
					if (tmp_2 == 4)
					{
						system("CLS");
						return 10;
					}
					else if (tmp_2 == 5)
					{
						system("CLS");
						return 11;
					}
				}
				break;
			}
		}
	}
}
