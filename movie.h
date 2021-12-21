#include <iostream>
#include <string>
#pragma once
#include "actor.h"

using namespace std;

class movie  //a single movie node, in the linked list of movies
{
public:
	movie* next = NULL;

	//data part of the node: 
	string show_id, release_year;
	string type, title, director, country, date_added, rating, duration, description;


	//linked list for cast
	cast moviecast;

	//enum for listed in



	void printmoviedata()
	{
		cout << show_id << endl;
		cout << release_year << endl;
		cout << type << endl;
		cout << title << endl;
		cout << director << endl;
		cout << country << endl;
		cout << date_added << endl;
		cout << rating << endl;
		cout << duration << endl;
		cout << description << endl;
	}
};


//this list contains pointers to movie nodes
class LinkedList_movies {
public:
	movie* start; // special variable which stores address of first movie
	movie* last; // special variable which stores address of the last movie
	movie* preloc; //to be used by Search(value) method to store address of logical predecessor of value in a list.
	movie* loc;   //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL.
	int length = 0;

	LinkedList_movies()   //constructor to create empty linked list
	{
		start = NULL;
		last = NULL;
		preloc = NULL;
		loc = NULL;
	}

	//other functions
	bool isEmpty(); // checks whether the list is empty or not. Returns true if empty and false otherwise.  
	void Insertnewmovieatend(movie* newmovie); // takes input from a user and inserts it at the tail end of a list
	void PrintList(); //prints all data in the list
	void search_titlebase(string value); //searches value entered by user, it will also be used in other functions like insertion etc
	void Delete(string value); // searches movie by title then deletes
	void DestroyList(); // Distroys all nodes of the list leaving the list in empty state.
	void printadd();
};