#include "pch.h"
#include "Choise_L_N.h"
#include "Game_.h"
#include "Menu.h"
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
				std::cout << "1";
				return 1;
				break;

			case Keys::Two:
				std::cout << "2";
				return 2;
				break;

			case Keys::Three:
				std::cout << "3";
				return 3;
				break;

			case Keys::Four:
				std::cout << "4";
				return 4;
				break;

			case Keys::Five:
				std::cout << "5";
				return 5;
				break;

			case Keys::Six:
				std::cout << "6";
				return 6;
				break;

			case Keys::Seven:
				std::cout << "7";
				return 7;
				break;

			case Keys::Eight:
				std::cout << "8";
				return 8;
				break;

			case Keys::Nine:
				std::cout << "9";
				return 9;
				break;

			case Keys::Ten:
				std::cout << "10";
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
				std::cout << "A";
				return 0;
				break;

			case Keys::a:
				std::cout << "A";
				return 0;
				break;

			case Keys::B:
				std::cout << "B";
				return 1;
				break;

			case Keys::b:
				std::cout << "B";
				return 1;
				break;

			case Keys::C:
				std::cout << "C";
				return 2;
				break;

			case Keys::c:
				std::cout << "C";
				return 2;
				break;

			case Keys::D:
				std::cout << "D";
				return 3;
				break;

			case Keys::d:
				std::cout << "D";
				return 3;
				break;

			case Keys::E:
				std::cout << "E";
				return 4;
				break;

			case Keys::e:
				std::cout << "E";
				return 4;
				break;

			case Keys::F:
				std::cout << "F";
				return 5;
				break;

			case Keys::f:
				std::cout << "F";
				return 5;
				break;

			case Keys::G:
				std::cout << "G";
				return 6;
				break;

			case Keys::g:
				std::cout << "G";
				return 6;
				break;

			case Keys::H:
				std::cout << "H";
				return 7;
				break;

			case Keys::h:
				std::cout << "H";
				return 7;
				break;

			case Keys::I:
				std::cout << "I";
				return 8;
				break;

			case Keys::i:
				std::cout << "I";
				return 8;
				break;

			case Keys::J:
				std::cout << "J";
				return 9;
				break;

			case Keys::j:
				std::cout << "J";
				return 9;
				break;
			}
		}
	}
}