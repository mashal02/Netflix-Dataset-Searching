#include "avl.h"

void AVL_strings::search(TreeNode* Node, string cname)
{
	loc = Node;
	if (Node == NULL) {
		loc = NULL;
	}
	else {
		if (Node->dataname == cname)
		{
			loc = Node;
		}
		if (Node->dataname > cname)
		{
			search(Node->lc, cname);
		}
		else if (Node->dataname < cname)
		{
			search(Node->rc, cname);
		}
	}
}

void AVL_movies::search(movie* Node, string mname)
{
	loc = Node;
	if (Node == NULL) {
		loc = NULL;
	}
	else {
		if (Node->title == mname)
		{
			loc = Node;
		}
		if (Node->title > mname)
		{
			search(Node->lc, mname);
		}
		else if (Node->title < mname)
		{
			search(Node->rc, mname);
		}
	}
}
void AVL_child::search(childnode* Node, string cname)
{	//Seperate search function to just print movies based on their country,director etc
	loc = Node;
	if (Node == NULL) {
		loc = NULL;
	}
	else {
		if (Node->dataname == cname)
		{
			loc = Node;
		}
		if (Node->dataname > cname)
		{
			search(Node->lc, cname);
		}
		else if (Node->dataname < cname)
		{
			search(Node->rc, cname);
		}
	}
}