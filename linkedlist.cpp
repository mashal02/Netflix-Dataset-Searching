#include "linkedlist.h"	//Already includes iostream namespacestd

bool linklist_string::isEmpty() {
	return start == NULL;
}
void linklist_string::search(string ra)
{	//Linked List searching function
	loc = start;
	preloc = NULL;
	if (isEmpty()) {
		return;
	}
	while (loc != NULL && loc->r != ra)
	{
		preloc = loc;
		loc = loc->next;
	}
	if (loc != NULL && loc->r != ra)
	{
		loc = NULL;	  //as value is not found so set loc equal to null. 
	}
}
void linklist_string::printlist()
{	//Linked List printing function
	loc = start;
	if (isEmpty())
	{
		return;
	}
	while (loc != NULL)
	{
		cout << loc->r << endl;
		loc = loc->next;
	}
}
void linklist_string::Insertwithoutduplic(string newr) //inserts at end
{	//Linked List insertion without duplication function
	linklist_string_node* temp = new linklist_string_node();
	temp->r = newr;
	if (isEmpty())
	{
		start = temp;
		last = temp;
	}
	else
	{
		search(newr);
		if (loc == NULL)
		{
			last->next = temp;
			last = temp;
		}
	}
}