#include <iostream>
#include "movie.h"

using namespace std;


bool LinkedList_movies::isEmpty()
{
	return start == NULL;
}
void LinkedList_movies::printadd()
{
	loc = start;
	while (loc != NULL)
	{
		cout << loc<<endl;
		loc = loc->next;
 
	}

}
void LinkedList_movies::Insertnewmovieatend(movie* newmovie)
{
	if (isEmpty())
	{
		start = newmovie;
		last = newmovie;
	}
	else
	{
		last->next = newmovie;
		last = newmovie;
	}
	length++;
}


void LinkedList_movies::PrintList()
{
	if (!isEmpty())
	{
		movie* temp = start;
		while (temp != NULL)
		{
			temp->printmoviedata();
			temp = temp->next;
		}
	}
	else
	{
		cout << "List is Empty.\n";
	}

}

void LinkedList_movies::search_titlebase(string stitle) //simple,exact search - spell checks not included
{

	loc = start;
	preloc = NULL;
	if (isEmpty())
	{
		return;
	}
	while (loc != NULL && loc->title != stitle)
	{
		preloc = loc;
		loc = loc->next;

	}
	if (loc != NULL && loc->title != stitle)
	{
		loc = NULL;	  //as value is not found so set loc equal to null. 
	}
}


void LinkedList_movies::Delete(string value)
{
	if (isEmpty())
	{
		return;
	}
	search_titlebase(value);
	if (loc != NULL)
	{
		if (preloc == NULL)//value is in headnode 
		{
			start = start->next;
		}
		else {
			//update link using ploc
			preloc->next = loc->next;
			//finally free memory using delete command.
			delete loc;
		}
	}
}
void LinkedList_movies::DestroyList()
{
	movie* temp;
	while (start != NULL)
	{
		temp = start;
		start = start->next;
		delete temp;
	}
	last = NULL;
}