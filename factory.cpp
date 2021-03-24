#include<iostream>
#include"factory.h"
using namespace std;
factory::factory()
{
	head = NULL;
	cursor = NULL;
}
void factory::insert(tile& newItem)
{
	tile* ptr = new tile(newItem);

	if (cursor == NULL && head == NULL)
	{
		ptr->next = NULL;
		cursor = ptr;
		head = cursor;
	}
	else
	{
		ptr->next = cursor->next;
		cursor->next = ptr;
		cursor = ptr;
	}
}
void factory::showStructure()const
{
	if (head == NULL)
	{

	}
	else
	{
		tile* ptr = head;
		do
		{
			cout << ptr->colour << " ";
			ptr = ptr->next;
		} while (ptr != NULL);
	}
}
int factory::search(char colour)
{
	bool flag = false; int count = 0;
	if (head == NULL)
	{
	}
	else
	{
		tile* ptr = head;
		while (ptr != NULL)
		{
			if (ptr->colour == colour)
			{
				count++;
			}
			ptr = ptr->next;
		}

	}
	return count;
}
void factory::gotoBeginning()
{
	cursor = head;
}
void factory::remove()
{
	if (head == NULL)
	{

	}
	else if (cursor == head && head->next == NULL)
	{
		delete head;
		cursor = NULL;
		head = NULL;
	}
	else if (cursor == head)
	{
		tile* current = cursor;
		cursor = cursor->next;
		head = head->next;
		delete current;
	}
	else if (cursor->next == NULL)
	{
		tile* prev = head;
		tile* current = head->next;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		delete current;
		prev->next = NULL;
		cursor = head;
	}
	else
	{
		tile* prev = head;
		tile* current = head->next;
		while (current != cursor)
		{
			prev = current;
			current = current->next;
		}
		prev->next = cursor->next;
		delete current;
		cursor = prev->next;
	}
}
bool factory::isEmpty() const
{
	if (head == NULL)
	{
		return true;
	}
	else return false;
}
void factory::removecolour(char colour)
{
	this->gotoBeginning();
	while (cursor != NULL)
	{
		if (cursor->colour == colour)
		{
			this->remove();
		}
		else cursor = cursor->next;
	}
}
void factory::linkfactory(factory& fact)
{
	this->gotoBeginning();
	while (cursor->next != NULL)
	{
		cursor = cursor->next;
	}
	cursor->next = fact.head;
	fact.head = NULL;
}
char factory::getcolour()
{
	return cursor->colour;
}