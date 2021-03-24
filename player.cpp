#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"player.h"
using namespace std;
int brokentiles = 0;
int factory0 = 0;
player::player()
{
	name = " ";
	char colour[5] = { 'L','U','R','Y','B' };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			mosaic[i][j] = '.';
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			mosaic_colour[i][j] = colour[(i + j) % 5];
		}
	}
	board = new char* [5];
	for (int i = 0; i < 5; i++)
	{
		board[i] = new char[i + 1];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			board[i][j] = '.';
		}
	}
	score = 0;
}
void player::setname(string name)
{
	this->name = name;
}
void player::show()
{

	cout << "  Mosaic for " << name << endl;
	cout << "1:           " << board[0][0] << " ||  ";
	for (int i = 0; i < 5; i++)
		cout << mosaic[0][i] << " ";
	cout << endl;
	cout << "2:         " << board[1][1] << " " << board[1][0] << " ||  ";
	for (int i = 0; i < 5; i++)
		cout << mosaic[1][i] << " ";
	cout << endl;
	cout << "3:       " << board[2][2] << " " << board[2][1] << " " << board[2][0] << " ||  ";
	for (int i = 0; i < 5; i++)
		cout << mosaic[2][i] << " ";
	cout << endl;
	cout << "4:     " << board[3][3] << " " << board[3][2] << " " << board[3][1] << " " << board[3][0] << " ||  ";
	for (int i = 0; i < 5; i++)
		cout << mosaic[3][i] << " ";
	cout << endl;
	cout << "5:   " << board[4][4] << " " << board[4][3] << " " << board[4][2] << " " << board[4][1] << " " << board[4][0] << " ||  ";
	for (int i = 0; i < 5; i++)
		cout << mosaic[4][i] << " ";
	cout << endl;
	cout << "broken:" << broken.str() << "\t\t Score:" << score << endl;
}
void player::savetofile(ofstream& fout)
{
	string btiles;
	fout << name << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			fout << board[i][j] << " ";
		}
		fout << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			fout << mosaic[i][j] << " ";
		}
		fout << endl;
	}
	fout << score << endl;
	broken >> btiles;
	fout << btiles << endl;
}
void player::resumefromfile(ifstream& fin)
{
	string btiles; char end;
	fin >> name;
	fin.get(end);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			fin >> board[i][j];
		}
		fin.get(end);
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			fin >> mosaic[i][j];
		}
		fin.get(end);
	}
	fin >> score;
	fin.get(end);
	fin >> btiles;
	broken << btiles;


}
void player::updatemosaic()
{

	bool flag, flag2 = true; char colour;
	for (int i = 0; i < 5; i++)
	{
		flag = true; colour = ' ';
		for (int j = 0; j < i + 1; j++)
		{
			if (board[i][j] == '.')
			{
				flag = false;
			}
		}
		if (flag)
		{
			colour = board[i][0]; int count = 0;
			for (int k = 0; k < 5; k++)
			{
				if (mosaic_colour[i][k] == colour)
				{
					mosaic[i][k] = colour;
					for (int l = 0; l < 5; l++)
					{
						if (mosaic[i][l] != '.' && l != k)
						{
							flag2 = false;
							count++;
						}

					}
					for (int l = 0; l < 5; l++)
					{
						if (mosaic[l][k] != '.' && l != i)
						{
							flag2 = false;
							count++;
						}
					}
					if (flag2)score += 1;
					else
					{
						score += 1;
						score += count;
					}
					break;
				}
			}
			for (int g = 0; g < i + 1; g++)
			{
				board[i][g] = '.';
			}
		}
	}
	for (int i = 1; i <= brokentiles; i++)
	{
		if (i <= 2)
		{
			score--;
		}
		else if (i > 2 && i < 5)
		{
			score -= 2;
		}
		else if (i > 4 && i < 7)
		{
			score -= 4;
		}
		else
		{
			score -= 6;
		}
	}
	broken.str(" "); broken.clear();
	brokentiles = 0;
}
void player::turn(char colour, int row, int num, int fact)
{
	for (int i = 0; i < row; i++)
	{
		if (board[row - 1][i] == '.' && num != 0)
		{
			board[row - 1][i] = colour;
			num--;
		}
	}
	if (fact == 0)
	{
		factory0++;
		if (factory0 == 1)
		{
			broken << " 0";
			brokentiles++;
		}
	}
	for (int i = 0; i < num; i++)
	{
		broken << colour << " ";
		brokentiles++;
	}

}
bool player::validturn(char colour, int row)
{
	bool flag = true;
	for (int i = 0; i < row; i++)
	{
		if (board[row - 1][i] != '.')
		{
			if (board[row - 1][i] == colour)
			{
				cout << " internal if" << endl;
			}
			else flag = false;
		}
	}
	return flag;
}
