#include "pch.h"
#include "Choise_L_N.h"
#include "Game_.h"
#include "Menu.h"
#include "cls.h"

#include <iostream>
#include <string>
#include <conio.h>

//----------------CHOICE

int Choice_L();
int Choice_N();

//----------------CHOICE

int ChoiseNumber()
{
	std::cout << "        |--------------||                |------------------------------------------------------> Choose a number: ";
	int Number_ = Choice_N();
	std::cout << std::endl;
	return Number_;
}

int ChoiseLetter()
{
	std::cout << "        |--------------||                |------------------------------------------------------> Choose a letter: ";
	int Choice_ = Choice_L();
	std::cout << std::endl;
	return Choice_;
}

int Main_Choice(int Choice_)
{
	system("CLS");
	int tmp_N = 0;
	Prin_Menu(Choice_);

	while (tmp_N < 10)
	{
		if (_kbhit())
		{
			tmp_N = Choice_Item();
		}
	}

	if (tmp_N == 10)
	{
		return 11;
	}
	else if (tmp_N == 11)
	{
		return 12;
	}
}

int Choice_N()
{
	int Choice_N;
	while (true)
	{
		if (_kbhit())
		{
			switch (static_cast<Keys>(_getch()))
			{
			case Keys::ESC:
				Choice_N = Main_Choice(1);
				if (Choice_N == 11)
				{
					return 11;
				}
				else if (Choice_N == 12)
				{
					return 12;
				}
				break;

			case Keys::One:
				return 1;
				break;

			case Keys::Two:
				return 2;
				break;

			case Keys::Three:
				return 3;
				break;

			case Keys::Four:
				return 4;
				break;

			case Keys::Five:
				return 5;
				break;

			case Keys::Six:
				return 6;
				break;

			case Keys::Seven:
				return 7;
				break;

			case Keys::Eight:
				return 8;
				break;

			case Keys::Nine:
				return 9;
				break;

			case Keys::Ten:
				return 10;
				break;
			}
		}
	}
}
int Choice_L()
{
	int Choice_L;
	while (true)
	{
		if (_kbhit())
		{
			switch (static_cast<Keys>(_getch()))
			{
			case Keys::ESC:
				Choice_L = Main_Choice(1);
				if (Choice_L == 11)
				{
					return 11;
				}
				else if (Choice_L == 12)
				{
					return 12;
				}
				break;

			case Keys::A:
				return 0;
				break;

			case Keys::a:
				return 0;
				break;

			case Keys::B:
				return 1;
				break;

			case Keys::b:
				return 1;
				break;

			case Keys::C:
				return 2;
				break;

			case Keys::c:
				return 2;
				break;

			case Keys::D:
				return 3;
				break;

			case Keys::d:
				return 3;
				break;

			case Keys::E:
				return 4;
				break;

			case Keys::e:
				return 4;
				break;

			case Keys::F:
				return 5;
				break;

			case Keys::f:
				return 5;
				break;

			case Keys::G:
				return 6;
				break;

			case Keys::g:
				return 6;
				break;

			case Keys::H:
				return 7;
				break;

			case Keys::h:
				return 7;
				break;

			case Keys::I:
				return 8;
				break;

			case Keys::i:
				return 8;
				break;

			case Keys::J:
				return 9;
				break;

			case Keys::j:
				return 9;
				break;
			}
		}
	}
}