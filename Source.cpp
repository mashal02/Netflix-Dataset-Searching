#include <string>
#include <sstream>
#include <fstream>
#include "avl.h"

//following have complexity nlog(m)  (n is no. of movies and m its no. of countries
void searchmovibytitle(movie* root, string mname);
void searchmovibycast(movie* root, string aname);
void searchmovibyrate(movie* root, string rname);
void searchmovibygenre(movie* root, string aname);

//complexity of following searches are log(n)
void searchbycountry(string cname);
void searchbydirector(string dname);

AVL_movies all_movies_in_dataset;
movie* movies_Root = NULL;

AVL_strings all_countries;
TreeNode* countries_Root = NULL;

AVL_strings all_actors;
TreeNode* actors_root = NULL;

AVL_strings all_genre;
TreeNode* genreroot = NULL;

AVL_strings alld;
TreeNode* dRoot = NULL;

linklist_string all_ratings;
linklist_string all_ry;	//Release Years

AVL_child all_countries2;
childnode* countries_Root2 = NULL;

AVL_child all_directors2;
childnode* directors_root2 = NULL;

void Readcsv() {
	string data;
	string show_id, type, title, director, cast, country, date, release, rating, duration, genre, desc;
	fstream netflix; //File Pointer

	netflix.open("C:\\Users\\HP\\OneDrive\\Desktop\\DSA Project\\Netflix-2\\Netflix 2 Dataset\\project dataset\\input\\netflix-shows\\netflix_titles.csv", ios::in);
	if (netflix.fail()) {
		cout << "COULD NOT READ FILE\n";
		exit(1);
	}
	getline(netflix, data);
	int line = 0;
	while (!netflix.eof()) {
		movie* movienode = new movie();	  //create a movie node, first insert all data, then we'll add it to the avl containing this movies address
		line++;

		getline(netflix, show_id, ',');
		movienode->show_id = show_id;

		getline(netflix, type, ',');
		if (type == "Movie")
			movienode->type = true;
		else
			movienode->type = false;

		getline(netflix, title, ',');
		movienode->title = title;

		getline(netflix, director, ',');

		string tempd;
		istringstream ss1(director);
		ss1 >> ws;
		while (getline(ss1, tempd, '|'))
		{
			if (tempd != "")
			{
				TreeNode* tc = new TreeNode();
				tc->dataname = tempd;
				dRoot = alld.enter(dRoot, tc);
				alld.search(dRoot, tempd);
				movienode->movidirectors_root = movienode->movidirectors.enter(movienode->movidirectors_root, alld.loc);

				childnode* tc2 = new childnode();
				tc2->dataname = tempd;
				directors_root2 = all_directors2.enter(directors_root2, tc2);
				all_directors2.search(directors_root2, tc2->dataname);

				movie* tempmov = new movie();
				//we cant add movienode because currently its LC,RC are NULL but wont remain NULL afterwards
				//so create a copy
				tempmov->title = movienode->title; //and store only data, not the links
				all_directors2.loc->cmroot = all_directors2.loc->cmovies.enter(all_directors2.loc->cmroot, tempmov); //and add it to the avl of movies of a specific country
			}
		}
		getline(netflix, cast, ',');
		string tempact;
		istringstream dd(cast);
		dd >> ws;
		while (getline(dd, tempact, '|'))
		{
			if (tempact != "")
			{
				TreeNode* tc = new TreeNode();
				tc->dataname = tempact;
				actors_root = all_actors.enter(actors_root, tc);
				all_actors.search(actors_root, tempact);
				movienode->moviactors_root = movienode->moviactors.enter(movienode->moviactors_root, all_actors.loc);
			}
		}
		getline(netflix, country, ',');
		string tempcountry;
		istringstream ss(country);
		ss >> ws;
		cout << "INDEX:\t\t" << line << endl;
		while (getline(ss, tempcountry, '|'))
		{
			if (tempcountry != "")
			{
				TreeNode* tc = new TreeNode();
				tc->dataname = tempcountry;
				countries_Root = all_countries.enter(countries_Root, tc);
				all_countries.search(countries_Root, tempcountry);
				movienode->movicountries_root = movienode->movicountries.enter(movienode->movicountries_root, all_countries.loc);

				childnode* tc2 = new childnode();
				tc2->dataname = tempcountry;
				countries_Root2 = all_countries2.enter(countries_Root2, tc2);
				all_countries2.search(countries_Root2, tc2->dataname);

				movie* tempmov = new movie();
				tempmov->title = movienode->title;
				all_countries2.loc->cmroot = all_countries2.loc->cmovies.enter(all_countries2.loc->cmroot, tempmov);
			}
		}

		getline(netflix, date, ',');
		movienode->date_added = date;

		getline(netflix, release, ',');
		all_ry.Insertwithoutduplic(release);
		all_ry.search(release);
		movienode->release_year = all_ry.loc;

		getline(netflix, rating, ',');
		all_ratings.Insertwithoutduplic(rating);
		all_ratings.search(rating);
		movienode->rate_movie = all_ratings.loc;

		getline(netflix, duration, ',');
		movienode->duration = duration;

		getline(netflix, genre, ',');
		string tempg;
		istringstream gg(genre);
		gg >> ws;
		while (getline(gg, tempg, '|'))
		{
			if (tempg != "")
			{
				TreeNode* tc = new TreeNode();
				tc->dataname = tempg;
				genreroot = all_genre.enter(genreroot, tc);
				all_genre.search(genreroot, tempg);

				movienode->groot = movienode->genres.enter(movienode->groot, all_genre.loc);
			}
		}
		getline(netflix, desc);
		movienode->description = desc;
		//save the movie node's address to the global list of  movies
		movies_Root = all_movies_in_dataset.enter(movies_Root, movienode);
	}
	netflix.close();
}

int main() {

	cout << "Welcome to our Netflix Search program" << endl;
	Readcsv();
	while (1) {
		cout << "\nSelect an option how you want to search for movies and shows.\n";
		cout << "1-Search by name(All Details).\n2-Search by country.\n3-Search by directors.\n4-Search by ratings(All Details).\n5-Search by cast(All Details).\n6-Show all\n7-By Genres\n";
		int choice; cin >> choice; string search;
		switch (choice) {
		case 1: {
			getchar(); cout << "Enter movie name.\n";
			getline(cin, search);
			searchmovibytitle(movies_Root, search);
			break;
		}
		case 2: {
			getchar();
			cout << "Enter country name.\n";
			getline(cin, search);
			cout << "Movies of " << search << endl;
			searchbycountry(search);
			break;
		}
		case 3: {
			getchar();
			cout << "Enter  directors.\n";
			getline(cin, search);
			cout << "Movies of " << search << endl;
			searchbydirector(search);
			break;
		}
		case 4: {
			getchar();
			cout << "Enter  rating.\n";
			getline(cin, search);
			cout << "Movies of " << search << endl;
			searchmovibyrate(movies_Root, search);
			break;
		}
		case 5: {
			getchar();
			cout << "Enter  actors name.\n";
			getline(cin, search);
			cout << "Movies of " << search << endl;
			searchmovibycast(movies_Root, search);
			break;
		}
		case 6: {
			all_movies_in_dataset.inorder(movies_Root, 2);
			break;
		}
		case 7: {
			getchar();
			cout << "Enter  genre.\n";
			getline(cin, search);
			cout << "Movies of " << search << endl;
			searchmovibygenre(movies_Root, search);
			break;
		}
		
		}
	}
	system("Pause");
}

void searchmovibycast(movie* root, string aname)
{
	//traverse all movies in order
	if (root) {
		searchmovibycast(root->lc, aname);
		//search the AVL Tree of directrs inside the movie node (movidirectors)
		root->moviactors.search(root->moviactors_root, aname);
		if (root->moviactors.loc != NULL)
		{
			root->printmoviedata();
		}
		searchmovibycast(root->rc, aname);
	}
}
void searchmovibytitle(movie* root, string mname)
{
	all_movies_in_dataset.loc = root;
	if (root == NULL) {
		all_movies_in_dataset.loc = NULL;
	}
	else {
		if (root->title == mname)
		{
			root->printmoviedata();
		}
		else if (root->title > mname)
		{
			searchmovibytitle(root->lc, mname);
		}
		else if (root->title < mname)
		{
			searchmovibytitle(root->rc, mname);
		}
	}
}

void searchmovibyrate(movie* root, string rname)
{
	//traverse all movies in order
	if (root) {
		searchmovibyrate(root->lc, rname);
		if (root->rate_movie->r == rname)
		{
			root->printmoviedata();
		}
		searchmovibyrate(root->rc, rname);
	}
}

void searchmovibygenre(movie* root, string aname)
{
	//traverse all movies in order
	if (root) {
		searchmovibygenre(root->lc, aname);
		//search the AVL Tree of directrs inside the movie node (movidirectors)
		root->genres.search(root->groot, aname);
		if (root->genres.loc != NULL)
		{
			root->printmoviedata();
		}
		searchmovibygenre(root->rc, aname);
	}
}


void searchbycountry(string cname)
{
	all_countries2.search(countries_Root2, cname);
	if (all_countries2.loc) {
		all_countries2.loc->cmovies.inorder(all_countries2.loc->cmroot, 1);
	}
}

void searchbydirector(string cname)
{
	all_directors2.search(directors_root2, cname);
	if (all_directors2.loc) {
		all_directors2.loc->cmovies.inorder(all_directors2.loc->cmroot, 1);
	}
}