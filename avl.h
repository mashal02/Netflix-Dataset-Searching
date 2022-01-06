#include "linkedlist.h"	//Already includes iostream namespace std

class TreeNode { //AVL TreeNode and AVL_strings used to store name and height for alldirectors,countries,actors etc
public:
    string dataname;
    int height;
    TreeNode* lc, * rc; //Left and Right Child
    TreeNode() {
        dataname = "";
        lc = NULL;
        rc = NULL;
        height = 0;
    }
};
class AVL_strings {
public:
    TreeNode* loc = NULL; TreeNode* ploc = NULL;
    void search(TreeNode* Node, string cname);
    TreeNode* smallest(TreeNode* Node) {
        if (Node != NULL)
        {
            TreeNode* temp = Node;

            while (temp->lc != NULL)    //Smallest valued node is the left most leaf
                temp = temp->lc;
            return temp;
        }

    }
    int height(TreeNode* Node) {//Height of Node
        if (Node) {
            int Leftheight = height(Node->lc);
            int Rightheight = height(Node->rc);
            if (Leftheight > Rightheight)
                return Leftheight + 1;
            else
                return Rightheight + 1;
        }
        return 0;
    }
    int balancefactor(TreeNode* Node) {//Balancing factor of Node
        if (!Node)
            return 0;
        //Balance Factor = Left Subtree Height - Right Subtree Height
        return height(Node->lc) - height(Node->rc);
    }
    void preorder(TreeNode* Node) {
        if (Node) {
            cout << Node->dataname << endl;
            preorder(Node->lc);
            preorder(Node->rc);
        }
    }
    void inorder(TreeNode* Node) {
        if (Node) {
            inorder(Node->lc);
            cout << Node->dataname << endl;

            inorder(Node->rc);
        }
    }
    void postorder(TreeNode* Node) {
        if (Node) {
            postorder(Node->lc);
            postorder(Node->rc);
            cout << Node->dataname << endl;
        }
    }
    TreeNode* LR(TreeNode* x) { //Left Rotation
        TreeNode* y = x->rc;
        TreeNode* Temp = y->lc;
        //Rotation
        y->lc = x;
        x->rc = Temp;
        //Update height of both nodes
        x->height = height(x) - 1;
        y->height = height(y) - 1;
        // cout << "Left Rotation Performed." << endl;
        return y;   //Return Root
    }
    TreeNode* RR(TreeNode* x) { //Right Rotation
        TreeNode* y = x->lc;
        TreeNode* Temp = y->rc;
        //Rotation
        y->rc = x;
        x->lc = Temp;
        //Update height of both nodes
        x->height = height(x) - 1;
        y->height = height(y) - 1;
        //cout << "Right Rotation Performed." << endl;
        return y;   //Return Root
    }
    TreeNode* enter(TreeNode* Node, TreeNode* cname)
    {   //Enter new Value
        if (Node == NULL) {
            TreeNode* Node = new TreeNode();
            Node->lc = NULL;    //Right and Left Child = NULL
            Node->rc = NULL;
            Node->height = 0;   //Leaf is at height 0
            Node->dataname = cname->dataname;
            return(Node);
        }
        if (Node->dataname > cname->dataname)         //Enter as Left child
        {
            Node->lc = enter(Node->lc, cname);

        }
        else if (Node->dataname < cname->dataname)    //Enter as Right child 
        {
            Node->rc = enter(Node->rc, cname);

        }
        else {  //Value already exists in AVL Tree
            //cout << "Value already Exists." << endl;
            return Node;
        }    //To compensate for lack of search function (prevent duplication)

        //Height is updated for node after insertion
        Node->height = height(Node) - 1;
        //Balance Factor checked for node after insertion
        int Balance = balancefactor(Node);
        //Four cases of rotation
        if (Balance == 2) {
            if (balancefactor(Node->lc) >= 0)  //Left Left Case
                return RR(Node);
            else {//Left Right Case
                Node->lc = LR(Node->lc);
                return RR(Node);
            }
        }
        else if (Balance == -2) {
            if (balancefactor(Node->rc) <= 0)   //Right Right Case
                return LR(Node);
            else if (cname->dataname < Node->rc->dataname) {//Right Left Case
                Node->rc = RR(Node->rc);
                return LR(Node);
            }
        }
        return Node;
    }
};

// AVL for movies
class movie  //A single movie node
{
public:
    movie* lc, * rc;
    movie() { lc = NULL; rc = NULL; }
    bool type;
    //Data part of the movie node: 
    string show_id;
    string title, date_added, duration, description;

    linklist_string_node* rate_movie;  //contains address of the node from the global list 
    linklist_string_node* release_year;

    AVL_strings movicountries;
    TreeNode* movicountries_root = NULL;

    AVL_strings movidirectors;
    TreeNode* movidirectors_root = NULL;

    AVL_strings moviactors;
    TreeNode* moviactors_root = NULL;

    AVL_strings genres;
    TreeNode* groot = NULL;

    void printmoviedata()   //Function to display all data of a movie
    {
        cout << show_id << endl;
        cout << release_year->r << endl;
        if (type)
            cout << "Movie" << endl;
        else
            cout << "TV Show" << endl;
        cout << title << endl;
        cout << "Directors: " << endl; movidirectors.inorder(movidirectors_root);
        cout << "Actors: " << endl; moviactors.inorder(moviactors_root);
        cout << "Ratings:" << rate_movie->r << endl;
        cout << "Countries: " << endl; movicountries.inorder(movicountries_root);
        cout << "Genres: " << endl; genres.inorder(groot);
        cout << "Duration: " << duration << endl;
        cout << "Description: " << description << endl;
        cout << endl << endl;
    }
};

class AVL_movies {
public:
    movie* loc = NULL; movie* ploc = NULL;
    void search(movie* Node, string mname);

    movie* Smallest(movie* Node) {
        if (Node != NULL)
        {
            movie* temp = Node;
            while (temp->lc != NULL)    //Smallest valued node is the left most leaf
                temp = temp->lc;
            return temp;
        }

    }
    int height(movie* Node) {//Height of Node
        if (Node) {
            int Leftheight = height(Node->lc);
            int Rightheight = height(Node->rc);
            if (Leftheight > Rightheight)
                return Leftheight + 1;
            else
                return Rightheight + 1;
        }
        return 0;
    }
    int balancefactor(movie* Node) {//Balancing factor of Node
        if (!Node)
            return 0;
        //Balance Factor = Left Subtree Height - Right Subtree Height
        return height(Node->lc) - height(Node->rc);
    }
    void preorder(movie* Node) {
        if (Node) {
            Node->printmoviedata();
            preorder(Node->lc);
            preorder(Node->rc);
        }
    }
    void inorder(movie* Node, int mode) {
        if (Node) 
        {
            inorder(Node->lc, mode);
            if (mode == 1)
                cout << Node->title << endl;
            else { Node->printmoviedata(); }
            inorder(Node->rc, mode);
        }
    }
    void postorder(movie* Node) {
        if (Node) {
            postorder(Node->lc);
            postorder(Node->rc);
            Node->printmoviedata();
        }
    }
    movie* LR(movie* x) { //Left Rotation
        movie* y = x->rc;
        movie* Temp = y->lc;
        //Rotation
        y->lc = x;
        x->rc = Temp;
        
        //cout << "Left Rotation Performed." << endl;
        return y;   //Return Root
    }
    movie* RR(movie* x) { //Right Rotation
        movie* y = x->lc;
        movie* Temp = y->rc;
        //Rotation
        y->rc = x;
        x->lc = Temp;

        //cout << "Right Rotation Performed." << endl;
        return y;   //Return Root
    }
    movie* enter(movie* rootNode, movie* newmovi)
    {   //Enter new Value
        if (rootNode == NULL) {
            movie* Node = newmovi;
            Node->lc = NULL;    //Right and Left Child = NULL
            Node->rc = NULL;
            return(Node);
        }
        if (rootNode->title > newmovi->title)         //Enter as Left child
            rootNode->lc = enter(rootNode->lc, newmovi);
        else if (rootNode->title < newmovi->title)    //Enter as Right child 
            rootNode->rc = enter(rootNode->rc, newmovi);
        else {  //Value already exists in AVL Tree
            //cout << "Value already Exists." << endl;
            return rootNode;
        }    //To compensate for lack of search function (prevent duplication)

        //Height is updated for node after insertion
        //Balance Factor checked for node after insertion
        int Balance = balancefactor(rootNode);
        //Four cases of rotation
        if (Balance == 2) {
            if (balancefactor(rootNode->lc) >= 0)  //Left Left Case
                return RR(rootNode);
            else {//Left Right Case
                rootNode->lc = LR(rootNode->lc);
                return RR(rootNode);
            }
        }
        else if (Balance == -2) {
            if (balancefactor(rootNode->rc) <= 0)   //Right Right Case
                return LR(rootNode);
            else if (newmovi->title < rootNode->rc->title) {//Right Left Case
                rootNode->rc = RR(rootNode->rc);
                return LR(rootNode);
            }
        }
        return rootNode;
    }
};

class childnode : public TreeNode   //Use of inheritance where childnode is child of treenode
{   //Used for when countries,directors etc need to point back to movie
public:
    AVL_movies cmovies;
    childnode* lc; childnode* rc;
    movie* cmroot = NULL;
};
class AVL_child {
public:
    childnode* loc = NULL; childnode* ploc = NULL;
    void search(childnode* Node, string cname);
    childnode* Smallest(childnode* Node) {
        if (Node != NULL)
        {
            childnode* temp = Node;
            while (temp->lc != NULL)    //Smallest valued node is the left most leaf
                temp = temp->lc;
            return temp;
        }
    }
    int height(childnode* Node) {//Height of Node
        if (Node) {
            int Leftheight = height(Node->lc);
            int Rightheight = height(Node->rc);
            if (Leftheight > Rightheight)
                return Leftheight + 1;
            else
                return Rightheight + 1;
        }
        return 0;
    }
    int balancefactor(childnode* Node) {//Balancing factor of Node
        if (!Node)
            return 0;
        //Balance Factor = Left Subtree Height - Right Subtree Height
        return height(Node->lc) - height(Node->rc);
    }

    void inorder2(childnode* Node) {
        if (Node) {
            inorder2(Node->lc);
            cout << Node->dataname << endl;
            movie* t = NULL;
            cout << "Movies : \n";
            Node->cmovies.inorder(Node->cmroot, 1); cout << endl;
            // getchar();
            inorder2(Node->rc);
        }
    }
    childnode* LR(childnode* x) { //Left Rotation
        childnode* y = x->rc;
        childnode* Temp = y->lc;
        //Rotation
        y->lc = x;
        x->rc = Temp;

        return y;   //Return Root
    }
    childnode* RR(childnode* x) { //Right Rotation
        childnode* y = x->lc;
        childnode* Temp = y->rc;
        //Rotation
        y->rc = x;
        x->lc = Temp;

        //cout << "Right Rotation Performed." << endl;
        return y;   //Return Root
    }
    childnode* enter(childnode* Node, childnode* cname)
    {   //Enter new Value
        if (Node == NULL) {
            childnode* Node = new childnode();
            Node->lc = NULL;    //Right and Left Child = NULL
            Node->rc = NULL;
            Node->dataname = cname->dataname;
            //Node->cmroot = cname->cmroot;
            return Node;
        }
        if (Node->dataname > cname->dataname)         //Enter as Left child
        {
            Node->lc = enter(Node->lc, cname);

        }
        else if (Node->dataname < cname->dataname)    //Enter as Right child 
        {
            Node->rc = enter(Node->rc, cname);

        }
        else {  //Value already exists in AVL Tree
            //cout << "Value already Exists." << endl;
            return Node;
        }    //To compensate for lack of search function (prevent duplication)


        //Balance Factor checked for node after insertion
        int Balance = balancefactor(Node);
        //Four cases of rotation
        if (Balance == 2) {
            if (balancefactor(Node->lc) >= 0)  //Left Left Case
                return RR(Node);
            else {//Left Right Case
                Node->lc = LR(Node->lc);
                return RR(Node);
            }
        }
        else if (Balance == -2) {
            if (balancefactor(Node->rc) <= 0)   //Right Right Case
                return LR(Node);
            else if (cname->dataname < Node->rc->dataname) {//Right Left Case
                Node->rc = RR(Node->rc);
                return LR(Node);
            }
        }
        return Node;
    }
};