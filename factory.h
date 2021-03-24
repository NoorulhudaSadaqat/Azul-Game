#pragma once
#include<iostream>

using namespace std;
class tile
{
	friend class factory;
private:
	char colour;
	tile* next; //address of the next available object.
public:
	tile(char colour, tile* next) //parameterized constructor
	{
		this->colour = colour;
		this->next = next;
	}
};
class factory
{
private:
	tile* head; //start of the list
	tile* cursor; //current item of the list
public:
	factory(); //default constructor
	void insert(tile& newItem);
	void showStructure()const;
	int search(char colour);
	void gotoBeginning();
	void remove();
	bool isEmpty() const;
	void removecolour(char colour);
	void linkfactory(factory& fact);
	char getcolour();
};
