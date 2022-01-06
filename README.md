# What-Should-I-watch-next-Netflix-project
In progress
This project uses the netflix dataset
First the data is parsed from the csv file in the readcsv() function insource.cpp
AVL trees are used to store the data, the avl_movies is used to create a global avl tree containing all movies and shows with their respective data. 
Inside each movie/show node, there are avls of cast  containing addresses of those relevant actors in the global avl of all actors present in the data set. 
Same case for directors, countries, genres as for actors.

Two different type of search complexities implemented in this project:
In one type, a simple avl of countires/actors/directors is stored in each movie node, if i want to search for all movies of one specific country, then I will traverse through 
the global avl of all movies, at each movie, check if the avl countries inside it contains that specific country or not, if so, then show that  movie in results

This has time complexity of O(n) where n is total no. of movies/shows

Other way to reduce time complexity to O(log(n)) is implementation of a child class of avl of countries/directors etc.
This avl now contains an avl of movies inside of it as well. As line of the csv is read, the movie's address is added to global list of all movies, its countries' addresses 
are added to the 
avl of countries inside that movie node, the country's address is also added to the global avl of all countries, and that movie's address is added to the avl of movies
inside that country node.
Now while searching for all movies of a specific country, search for that country in global avl of all countries, when found, display all movies present inside avl_movies in that
particular country.
Same case with other mullti valued attributes like directors,a ctors, genres.

This project is for my course "Data Structures and Algorithms". 

Hope you like it, specially the logic that I made for the two-way linking of movies to their attributes and attributes to their relevant movies! I did that to decrease
time complexity of searching.