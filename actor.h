#include <iostream>
#pragma once
using namespace std;

class actor //Node, contains data as name, will be used as nodes in the linked list of cast in movies
{
public:
	string name;
	actor* next = NULL;
};

//following is a linked list that contains pointers to actor class's objects
//this will contain addresses of all the actors
//to add a certain actor to specific movie's cast, that actor will be accessed from this list
//removing an actor from a cast of one movie will not delete that actor node in general i.e not from this list of actors

class all_actors {
public:
	actor* start; // special variable which stores address of the head node.
	actor* last; // special variable which stores address of the last node.
	actor* preloc; //to be used by Search(value) method to store address of logical predecessor of value in a list.
	actor* loc;   //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL.
	int length = 0;

	all_actors()   //constructor to create empty linked list
	{
		start = NULL;
		preloc = NULL;
		loc = NULL;
		last = NULL;
	}

	//other functions
	bool isEmpty(); // checks whether the list is empty or not. Returns true if empty and false otherwise.  
	void InsertAtEnd(actor* newactor); // takes input from a user and inserts it at the tail end of a list
	void PrintList(); //prints all data in the list
	void search(string value); //searches value entered by user, it will also be used in other functions like insertion etc

	//no need of these funcs of linked lists in this case
	//void Delete(string value); // searches value and then  deletes it if found.
	//void DestroyList(); // Distroys all nodes of the list leaving the list in empty state.

};


//list of actors to store casts of specific movies

class cast {
public:
	actor* start; // special variable which stores address of the head node.
	actor* last; // special variable which stores address of the last node.
	actor* preloc; //to be used by Search(value) method to store address of logical predecessor of value in a list.
	actor* loc;   //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL.
	int length = 0;

	cast()   //constructor to create empty linked list
	{
		start = NULL;
		preloc = NULL;
		loc = NULL;
		last = NULL;
	}

	//other functions
	bool isEmpty(); // checks whether the list is empty or not. Returns true if empty and false otherwise.  
	void InsertAtEnd(actor* newactor); // takes input from a user and inserts it at the tail end of a list
	void PrintList(); //prints all data in the list
	void search(string value); //searches value entered by user, it will also be used in other functions like insertion etc
	void Delete(string value); // searches value and then  deletes it if found.
	//no need of these funcs of linked lists in this case
	//
	//void DestroyList(); // Distroys all nodes of the list leaving the list in empty state.

};
