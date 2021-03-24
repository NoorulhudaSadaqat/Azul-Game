#pragma once
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<fstream>
#include<conio.h>
#include"factory.h"
using namespace std;


class gameplay
{
	factory fact0, fact1, fact2, fact3, fact4, fact5;
	char tilebox[100] = " ";
	int remainingtiles = 100, round = 5;
public:
	gameplay();
	void fillfactories();
	void savefactories(ofstream& fout);
	int getround();
	void setround(int rounds);
	bool validfact(char colour, int fact, int& num);
	bool isempty();
	void fillfactoriesfromfile(ifstream& fin);
	void showfactories();
	void pickfromfactory(int fact, char colour);
};
