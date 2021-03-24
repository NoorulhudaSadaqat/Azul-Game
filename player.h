#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
class player
{
private:
	string name;
	char** board;
	char mosaic[5][5];
	char mosaic_colour[5][5];
	int score;
	stringstream broken;
public:
	player();
	void setname(string name);
	void show();

	void savetofile(ofstream& fout);
	void resumefromfile(ifstream& fin);
	void updatemosaic();
	void turn(char colour, int row, int num, int fact);
	bool validturn(char colour, int row);
};
