#include <iostream>
#include "actor.h"
using namespace std;

//functions of all_actors
bool all_actors::isEmpty()
{
	return start == NULL;
}
void all_actors::InsertAtEnd(actor* newactor)
{
	if (isEmpty())
	{
		start = newactor;
		last = newactor;
	}
	else
	{
		last->next = newactor;
		last = newactor;
	}
}

void all_actors::PrintList()
{
	if (!isEmpty())
	{
		actor* temp = start;
		while (temp != NULL)
		{
			cout << temp->name << "\t";
			temp = temp->next;
		}
	}
	else
	{
		cout << "List is Empty.\n";
	}
}
void all_actors::search(string value)
{

	loc = start;
	preloc = NULL;
	if (isEmpty())
	{
		return;
	}
	while (loc != NULL && loc->name != value)
	{
		preloc = loc;
		loc = loc->next;

	}
	if (loc != NULL && loc->name != value)
	{
		loc = NULL;	  //as value is not found so set loc equal to null. 
	}
}


//list of actors to store casts of specific movies
bool cast::isEmpty()
{
	return start == NULL;
}
void cast::InsertAtEnd(actor* newactor)//this address to be taken from all_actors list
//when adding an actor to a cast of a movie search his/her name in all actors
//upon searching, get that actor node's address from all_actors
//use that address in function call of this function, to insert that actor node's address in this list of cast
{

	if (isEmpty())
	{
		start = newactor;
		last = newactor;
	}

	else
	{
		last->next = newactor;
		last = newactor;
	}
}

void cast::PrintList()
{
	if (!isEmpty())
	{
		actor* temp = start;
		while (temp != NULL)
		{
			cout << temp->name << "\t";
			temp = temp->next;
		}
	}
	else
	{
		cout << "List is Empty.\n";
	}
}
void cast::search(string value)
{

	loc = start;
	preloc = NULL;
	if (isEmpty())
	{
		return;
	}
	while (loc != NULL && loc->name != value)
	{
		preloc = loc;
		loc = loc->next;

	}
	if (loc != NULL && loc->name != value)
	{
		loc = NULL;	  //as value is not found so set loc equal to null. 
	}
}
void cast::Delete(string value)
{
	if (isEmpty())
	{
		return;
	}
	search(value);
	if (loc != NULL)
	{
		if (preloc == NULL)//value is in headnode 
		{
			start = start->next;
		}
		else {
			//update link using ploc
			preloc->next = loc->next;
			//note that we will not "delete loc", as the actor is still in all_actors list
		}
	}
}