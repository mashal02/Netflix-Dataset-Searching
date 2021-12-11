#include <iostream>
#include <string>
#include <fstream>
#include "movie.h"
//#include "actor.h"

using namespace std;
LinkedList_movies all_movies_in_dataset;
void Readcsv() {

	movie* movienode = new movie();  //create a movie node, first insert all data, then we'll add it to the linked list that contains this movie's address
	string data;
	string show_id, type, title, director, cast, country, date_added, release, rating, duration, genre, desc;
	fstream netflix; //File Pointer
	netflix.open("C:\\Users\\HP\\OneDrive\\Desktop\\DSA Project\\Netflix-2\\Netflix 2 Dataset\\project dataset\\input\\netflix-shows\\netflix_titles.csv", ios::in);
	getline(netflix, data);
	int line = 0;
	while (!netflix.eof()) {
		getline(netflix, data);
		line++;
		show_id = data.substr(0, data.find(","));
		int start = data.find(",");
		type = data.substr(start + 1, (data.find(",", start + 1) - start - 1));
		start = data.find(",", start + 1);
		if (data.find("\"") == start + 1) {
			title = data.substr(start + 2, data.find("\"", start + 2) - start - 2);
			start = data.find("\"", start + 2);
		}
		else {
			title = data.substr(start + 1, (data.find(",", start + 1)) - start - 1);
			start = data.find(",", start + 1);
		}
		if (data.find("\"") == start + 1) {
		director = data.substr(start + 2, data.find("\"", start + 2) - start - 2);
			start = data.find("\"", start + 2);
			start++;
		}
		else {
			director = data.substr(start + 1, (data.find(",", start + 1)) - start - 1);
			start = data.find(",", start + 1);
		}
		if (data.find("\"", start + 1) == start + 1) {
			cast = data.substr(start + 2, data.find("\"", start + 2) - start - 2);
			start = data.find("\"", start + 2);
			start++;
		}
		else {
			cast = data.substr(start + 1, (data.find(",", start + 1)) - start - 1);
			start = data.find(",", start + 1);
		}

		if (data.find("\"", start + 1) == start + 1) {
		country = data.substr(start + 2, data.find("\"", start + 2) - start - 2);
			start = data.find("\"", start + 2);
			start++;
		}
		else {
			country = data.substr(start + 1, (data.find(",", start + 1)) - start - 1);
			start = data.find(",", start + 1);
		}
	date_added = data.substr(start + 1, (data.find(",", start + 1) - start - 1));
		start = data.find(",", start + 1);
		release = data.substr(start + 1, (data.find(",", start + 1) - start - 1));
		start = data.find(",", start + 1);
		rating = data.substr(start + 1, (data.find(",", start + 1) - start - 1));
		start = data.find(",", start + 1);
		duration = data.substr(start + 1, (data.find(",", start + 1) - start - 1));
		start = data.find(",", start + 1);
		if (data.find("\"", start + 1) == start + 1) {
			genre = data.substr(start + 2, data.find("\"", start + 2) - start - 2);
			start = data.find("\"", start + 2);
			start++;
		}
		else {
			genre = data.substr(start + 1, (data.find(",", start + 1)) - start - 1);
			start = data.find(",", start + 1);
		}
		desc = data.substr(start + 1, data.find("\n") - start - 4);

		// save the movie's address in movies list
		//all_movies_in_dataset.Insertnewmovieatend(movienode);

		cout << "INDEX:\t" << line << endl;
		cout << "Show_id:\t" << show_id << endl;
		cout << "Type:\t" << type << endl;
		cout << "Title:\t" << title << endl;
		cout << "Director:\t" << director << endl;
		cout << "Cast:\t" << cast << endl;
		cout << "Country:\t" << country << endl;
		cout << "Date_added:\t" << date_added << endl;
		cout << "Release:\t" << release << endl;
		cout << "Rating:\t" << rating << endl;
		cout << "Duration:\t" << duration << endl;
		cout << "Genre:\t" << genre << endl;
		cout << "Description:\t" << desc << endl;

		//show_id, type, title, director, cast, country, date_added, release, rating, duration, genre, desc
	}
	netflix.close();
}

int main() {
	Readcsv();
	
	//all_movies_in_dataset.PrintList();
	system("Pause");

	return 0;
}