#pragma once

class Game_
{
public:
	static int Player_Turn;
	static int Move_Number;
	static int P1_Kill;
	static int P2_Kill;
	
	static int X_RAY;

	Game_();
	~Game_();

	void NextTurn();

	void PrintLine(int LN, int(&P1)[10][10], int(&P2)[10][10]); /* LN - LineNumber*/

	void Hide_Item(int(&PL)[10][10], int Leter, int Number);

	void Positon_Check(int(&PL)[10][10], int Letter, int Number);

	bool Barrier_Сheck(int(&PL)[10][10], int Letter, int Number, int Equally); 

	void Around_Check_1(int(&PL)[10][10], int Letter, int Number);
	
	bool Around_Check_2(int(&PL)[10][10], int Letter, int Number);

	bool Around_Check_3(int(&PL)[10][10], int Letter, int Number);

	bool Around_Check_4(int(&PL)[10][10], int Letter, int Number);

	int Shot(int(&PL)[10][10], int Letter, int Number);

	int TryHit(int(&P1)[10][10], int(&P2)[10][10], int Letter, int Number);

	void PrintMap(int(&P1)[10][10], int(&P2)[10][10], int X_RAY);

	void Print_X_RAY(int(&P1)[10][10], int(&P2)[10][10]);

	void Print_X_RAY_Line(int LN, int(&P1)[10][10], int(&P2)[10][10]);

	void Show_Item(int(&PL)[10][10], int Leter, int Number);

private:

	int Letter = 0;
	int Number = 0;
	int SDS_P1 = 0;  int SDS_P2 = 0;                                  //Single - deck ship.      |
	int DDS_P1 = 0;  int DDS_P2 = 0; 								  // Double - deck ship.     |
	int TDS_P1 = 0;  int TDS_P2 = 0; 								  // Three - deck ship.      |
	int FDS_P1 = 0;  int FDS_P2 = 0; 								  // Four - deck ship        |

	friend int ReadFile(Game_ &Player, int(&P1)[10][10], int Player_Number);
	friend bool GameOver(Game_ &Game, int(&P1)[10][10], int(&P2)[10][10], int SIZE, int &Winner);
};

