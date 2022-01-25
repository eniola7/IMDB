/*
 * File: imdb.cpp
 * Course: CS216-00x
 * Project: Lab8 (as part of Project 2)
 * Purpose: Provide the implementation of the class named IMDB
 *          This class represents a movie-actor database
 */
#include <regex>  // needs c++11 standard
#include "imdb.h"

using namespace std;

// default constructor
IMDB::IMDB()
{
    //do nothing
    //since map class contains a default contructor
    //      which constructs an empty container, with no elements
}

// insert a pair<actorName, the set of movieTitle of this actor>
void IMDB::insert_an_actor(string actorName, set<string> movieTitles)
{
    /* First upgrade actors_db */
    // if the key actorName does not exist
    //        add the key to the map actors_db
    // if the key actorName does exist
    //        modify its associated set of movies in the map actors_db
   if (actors_db.find(actorName) != actors_db.end())
   {
	  actors_db[actorName] = movieTitles;
   }
   else
   {
	  actors_db[actorName] = movieTitles;
   } 
    
    
    /* Second upgrade movies_db */
    // for each movieTitle in the set of movieTitles,
    // insert actorName to its associated set of actors in the map, movies_db
for (auto movieTitles : movieTitles)
{
	movies_db[movieTitles].insert(actorName);
}


}

// insert a pair <movieTitle, the set of actor names in this movie>
// this function is optional to this Lab8 assignment
// however it is required in Project 2
void IMDB::insert_a_movie(string movieTitle, set<string> actorNames)       
{
    /* First upgrade movies_db */
    // if the key, movieTitle, does not exist
    //        add the key to the map, movies_db
    // if the key, movieTitle, does exist
    //        modify its associated set of actors in the map movies_db
	if (movies_db.find(movieTitle) != movies_db.end())
		{
			movies_db[movieTitle] = actorNames;
		}
	else
		{
			movies_db[movieTitle]=actorNames;
		}




    /* Second upgrade actors_db */
    // for each actorName in the set of actorNames
    // insert movieTitle to its associated set of movies in the map, actors_db
	for (auto actorName : actorNames)
	{
		actors_db[actorName].insert(movieTitle);
	}




}

// use passing-in parameter, movieTitle, as the pattern to match 
// one existing movie in the map
// return the matched movie title from the map
// otherwise return empty string
string IMDB::matchExistingMovie(string movieTitle) const
{
    string matchedMovie;
    bool found = false;
    // generate the regular expression to match 
    // which contains movieTitle as a substring
    // note that it performs case insensitive matching
    regex reg(movieTitle, regex_constants::icase);
    auto it = movies_db.begin();
    while (!found && it != movies_db.end())
    {
        if (regex_search(it->first, reg))
        {
            found = true;
            matchedMovie = it->first;
        }
        else
            it++;
    }
    return matchedMovie;
}

// check if a movieTitle does exist in the map
// return true if it does; otherwise return false
bool IMDB::isExistingMovie(string movieTitle) const
{
	if(movies_db.find(movieTitle) != movies_db.end())
	{
		return true;
	}
	else
	{
		return false;
	}

}

// check if an actorName does exist in the map
// return true if it does; otherwise return false
bool IMDB::isExistingActor(string actorName) const
{
	if (actors_db.find(actorName) != actors_db.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// return a set of movie titles which actorName was in
// if the passing-in parameter: actorName, is not in the map, 
//                   display message andreturn an empty set
set<string> IMDB::find_movies_for_an_actor(string actorName) const
{
	if (actors_db.find(actorName) != actors_db.end())
	{
		return actors_db.at(actorName);
	}
	else
	{
		set<string> empty;
		cout<< "Invalid movie title." <<endl;
		return empty;
	}

}

// return a set of actor names which were all in the movieTitle
// if the passing-in parameter: movieTitle is not in the map, 
//                   display message and return an empty set
set<string> IMDB::find_actors_in_a_movie(string movieTitle) const
{

	if (movies_db.find(movieTitle) != movies_db.end())
	{
		return movies_db.at(movieTitle);
	}
	else
	{
		set<string> empty;
		cout<<"Invalid"<<endl;
		return empty;
	}
}
