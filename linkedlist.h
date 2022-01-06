#include <iostream>
using namespace std;

class linklist_string_node //LinkedList Node
{   //Used for ratings and release years as less amount of data
public:
    string r;
    linklist_string_node* next;
};
class linklist_string
{
public:
    linklist_string_node* start;
    linklist_string_node* last;
    linklist_string_node* preloc; //to be used by Search(value) method to store address of logical predecessor of value in a list.
    linklist_string_node* loc;   //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL.
    int length = 0;
    linklist_string()   //constructor to create empty linked list
    {
        start = NULL;
        preloc = NULL;
        loc = NULL;
        last = NULL;
    }
    bool isEmpty();
    void search(string ra);
    void printlist();
    void Insertwithoutduplic(string newr);// takes input from a user and inserts it at the tail end of a list
};