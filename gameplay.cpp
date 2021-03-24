#include<iostream>
#include<sstream>
#include<cstdlib>
#include<fstream>
#include<conio.h>
#include"factory.h"
#include"gameplay.h"
using namespace std;
gameplay::gameplay()
{
	char colour[5] = { 'L','U','R','Y','B' };
	for (int i = 0; i < 100; i++)
	{
		int random = rand() % 5;
		tilebox[i] = colour[random];
	}
}
void gameplay::fillfactories()
{
	char colour;
	if (remainingtiles > 0)
	{
		for (int i = 0; i < 4; i++)
		{
			colour = tilebox[remainingtiles - 1];
			remainingtiles--;
			tile t1(colour, NULL);
			fact1.insert(t1);
		}
		for (int i = 0; i < 4; i++)
		{
			colour = tilebox[remainingtiles - 1];
			remainingtiles--;
			tile t1(colour, NULL);
			fact2.insert(t1);
		}
		for (int i = 0; i < 4; i++)
		{
			colour = tilebox[remainingtiles - 1];
			remainingtiles--;
			tile t1(colour, NULL);
			fact3.insert(t1);
		}
		for (int i = 0; i < 4; i++)
		{
			colour = tilebox[remainingtiles - 1];
			remainingtiles--;
			tile t1(colour, NULL);
			fact4.insert(t1);
		}
		for (int i = 0; i < 4; i++)
		{
			colour = tilebox[remainingtiles - 1];
			remainingtiles--;
			tile t1(colour, NULL);
			fact5.insert(t1);
		}
		tile t2('0', NULL);
		fact0.insert(t2);
	}
}
void gameplay::savefactories(ofstream& fout)
{

	fout << round << endl;
	fact1.gotoBeginning(); char colour;
	while (!(fact1.isEmpty()))
	{
		colour = fact1.getcolour();
		fout << colour << " ";
		fact1.remove();
	}
	fout << endl;
	fact2.gotoBeginning();
	while (!(fact2.isEmpty()))
	{
		colour = fact2.getcolour();
		fout << colour << " ";
		fact2.remove();
	}
	fout << endl;
	fact3.gotoBeginning();
	while (!(fact3.isEmpty()))
	{
		colour = fact3.getcolour();
		fout << colour << " ";
		fact3.remove();
	}
	fout << endl;
	fact4.gotoBeginning();
	while (!(fact4.isEmpty()))
	{
		colour = fact4.getcolour();
		fout << colour << " ";
		fact4.remove();
	}
	fout << endl;
	fact5.gotoBeginning();
	while (!(fact5.isEmpty()))
	{
		colour = fact5.getcolour();
		fout << colour << " ";
		fact5.remove();
	}
	fout << endl;
	fact0.gotoBeginning();
	while (!(fact0.isEmpty()))
	{
		colour = fact0.getcolour();
		fout << colour << " ";
		fact0.remove();
	}
	fout << endl;

}
int gameplay::getround()
{
	return round;
}
void gameplay::setround(int rounds)
{
	round = rounds;
}
bool gameplay::validfact(char colour, int fact, int& num)
{
	bool flag = true; int count;
	if (fact == 0)
	{
		count = fact0.search(colour);
		num = count;
		if (count == 0)
		{
			flag = false;
		}
	}
	else if (fact == 1)
	{
		count = fact1.search(colour);
		num = count;
		if (count == 0)
		{
			flag = false;
		}
	}
	else if (fact == 2)
	{
		count = fact2.search(colour);
		num = count;
		if (count == 0)
		{
			flag = false;
		}
	}
	else if (fact == 3)
	{
		count = fact3.search(colour);
		num = count;
		if (count == 0)
		{
			flag = false;
		}
	}
	else if (fact == 4)
	{
		count = fact4.search(colour);
		num = count;
		if (count == 0)
		{
			flag = false;
		}
	}
	else if (fact == 5)
	{
		count = fact5.search(colour);
		num = count;
		if (count == 0)
		{
			flag = false;
		}
	}
	return flag;
}
bool gameplay::isempty()
{
	bool flag = false;
	if ((fact0.isEmpty()))
	{
		flag = true;
	}
	return false;
}
void gameplay::fillfactoriesfromfile(ifstream& fin)
{
	char colour; char end;
	fin >> round;
	fin.get(end);
	fin.get(colour);
	while (colour != '\n')
	{
		if (colour != ' ')
		{
			tile n1(colour, NULL);
			fact1.insert(n1);
		}
		fin.get(colour);
	}
	fin.get(colour);
	while (colour != '\n')
	{
		if (colour != ' ')
		{
			tile n1(colour, NULL);
			fact2.insert(n1);
		}
		fin.get(colour);
	}
	fin.get(colour);
	while (colour != '\n')
	{
		if (colour != ' ')
		{
			tile n1(colour, NULL);
			fact3.insert(n1);
		}
		fin.get(colour);
	}
	fin.get(colour);
	while (colour != '\n')
	{
		if (colour != ' ')
		{
			tile n1(colour, NULL);
			fact4.insert(n1);
		}
		fin.get(colour);
	}
	fin.get(colour);
	while (colour != '\n')
	{
		if (colour != ' ')
		{
			tile n1(colour, NULL);
			fact5.insert(n1);
		}
		fin.get(colour);
	}
	fin.get(colour);
	while (colour != '\n')
	{
		if (colour != ' ')
		{
			tile n1(colour, NULL);
			fact0.insert(n1);
		}
		fin.get(colour);
	}
}
void gameplay::showfactories()
{
	cout << " 0. ";
	fact0.showStructure();
	cout << endl;
	cout << " 1. ";
	fact1.showStructure();
	cout << endl;
	cout << " 2. ";
	fact2.showStructure();
	cout << endl;
	cout << " 3. ";
	fact3.showStructure();
	cout << endl;
	cout << " 4. ";
	fact4.showStructure();
	cout << endl;
	cout << " 5. ";
	fact5.showStructure();
	cout << endl;
}
void gameplay::pickfromfactory(int fact, char colour)
{
	if (fact == 1)
	{
		this->fact1.removecolour(colour);
		fact0.linkfactory(fact1);
	}
	else if (fact == 2)
	{
		this->fact2.removecolour(colour);
		fact0.linkfactory(fact2);
	}
	else if (fact == 3)
	{
		this->fact3.removecolour(colour);
		fact0.linkfactory(fact3);
	}
	else if (fact == 4)
	{
		this->fact4.removecolour(colour);
		fact0.linkfactory(fact4);
	}
	else if (fact == 5)
	{
		this->fact5.removecolour(colour);
		fact0.linkfactory(fact5);
	}
	else if (fact == 0)
	{
		this->fact0.removecolour(colour);
		this->fact0.removecolour('0');
	}
}
