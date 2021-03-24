#include<iostream>
#include<fstream>
#include"gameplay.h"
#include"player.h"
using namespace std;
int menu()
{
	int input = 0;
	cout << "   Menu " << endl;
	cout << "  ------" << endl;
	cout << " 1. NewGame" << endl;
	cout << " 2. LoadGame" << endl;
	cout << " 3. Show Student Information" << endl;
	cout << " 4. Quit" << endl;
	cout << ">";
	cin >> input;
	while (input < 1 || input>4)
	{
		cout << " Invalid Input !!!" << endl;
		cout << ">";
		cin>> input;
	}
	return input;
}
void showstudentinfo()
{
	cout << "  Noor ul huda Sadaqat " << endl;
	cout << "  bitf18m524 " << endl;
	cout << "  bitf18m524@pucit.edu.pk" << endl;

}
void loadgame(gameplay&game, player&p1, player&p2)
{
	string fname;
	cout << "Enter the name of file from which laod a game" << endl;
	cout << ">";
	cin >> fname;
	ifstream fin(fname + ".txt");
	game.fillfactoriesfromfile(fin);
	p1.resumefromfile(fin);
	p2.resumefromfile(fin);
}
void newgame(gameplay&game, player&p1, player&p2)
{
	 string name;
	cout << "Enter the name of player 1 :" << endl;
	cout << " >";
	cin >> name;
	p1.setname(name);
	cout << "Enter the name of player 2 :" << endl;
	cout << " >";
	cin >> name;
	p2.setname(name);
	game.fillfactories();
}
void turn(gameplay&game, player&p)
{
	game.showfactories();
	p.show(); int row, num, fact;
	char colour;
	cout << " turn >";
	cin >> fact >> colour >> row;
	while (!(game.validfact(colour, fact, num)) || !(p.validturn(colour, row)))
	{
			cout << "Invalid turn :((((" << endl;
			cout << " turn >";
			cin >> fact >> colour >> row;                                                                                                                                                                             
		
	}
	game.pickfromfactory(fact, colour);
	p.turn(colour,row, num,fact);
	cout << " Turn Successful :)))" << endl;
}
void round(gameplay&game, player&p1, player&p2)
{
	int count = 0;
	while (!(game.isempty()))
	{
		count++;
		if (count % 2 == 0)
		{
			turn(game, p2);
		}
		else turn(game, p1);
	}
	p1.updatemosaic();
	p2.updatemosaic();
	p1.show();
	p2.show();
}
void savegame(gameplay game,player p1,player p2)
{
	string fname;
	cout << "Enter the name of file in which you want to save :" << endl;
	cout << "> ";
	cin >> fname;
	ofstream fout(fname + ".txt");
	game.savefactories(fout);
	p1.savetofile(fout);
	p2.savetofile(fout);
}
int main()
{
	gameplay game; player p1, p2; int input, rounds=5;
	cout << " \t Welcome to Azul" << endl;
	cout << "\t------------------------\n\n" << endl;
	while (rounds > 0)
	{
		input = menu();
		if (input == 1)
		{
			char next;
			newgame(game, p1, p2);
		c:
			round(game, p1, p2);
			rounds--;
			game.setround(rounds);
			cout << " Want to play next round ?? Y/N :";
			cin.get(next);
			if (next == 'Y' || next == 'y')
			{
				goto c;
			}
		}
		else if (input == 2)
		{
			loadgame(game, p1, p2); char next;
			rounds = game.getround();
		a:
			round(game, p1, p2);
			rounds--;
			game.setround(rounds);
			cout << " Want to play next round ?? Y/N :";
			cin.get(next);
			if (next == 'Y' || next == 'y')
			{
				goto a;
			}
		}
		else if (input == 3)
		{
			showstudentinfo();
		}
		else
		{
			return 0;
		}
	}
	
	
}