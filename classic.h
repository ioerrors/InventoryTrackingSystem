////////////////////////////////classic.cpp file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a Classic class which is a type of Movie 
// child of the Movie class, inheriting from Movie
//-----------------------------------------------------------------------------
// Note on implemenation:
// 
// in the data4movies.txt
// C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
// C, 10, George Cukor, Holiday, Cary Grant 9 1938
// 
// could be built into the movie set as:
// 
// C, 20, George Cukor, Holiday, <Katherine Hepburn, Cary Grant> 9 1938
// 
// OR into the movie set as:
// 
// C, 20, George Cukor, Holiday, Katherine Hepburn 9 1938
// C, 20, George Cukor, Holiday, Cary Grant 9 1938
// 
// These could both be valid based on the design document 
// 
// "In addition, for classical movies, one movie (e.g., Holiday) 
// may have multiple lines so the total stock of this movie 
// will be the sum of all the stocks in the lines about this movie
// (e.g., 20 for Holiday in the above example)."
// 
// We have implemented one object per movie, with a list of actors.
// This requires the addition of one check for title after checking the 
// normal sorting criteria of Release date --> Actor for Classics 
// which if positive will add to the existing actor list 
// rather than return a false negative in comparison operations


#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"
#include <set>

using namespace std;

class Classic : public Movie {
public:
  //---------------------------------------------------------------------------
  // Classic CONSTRUCTOR
  // Description: creates an empty Classic
  // PRE: Memory is available for Classic
  // POST: Empty Classic is created
  Classic();

  //---------------------------------------------------------------------------
  // Classic DESTRUCTOR
  // Description: deallocates all memory allocated for Classic
  // PRE: Classic exists
  // POST: All Classic memory is freed               
  ~Classic();             
  
  
  // Accessors
  char getGenre() const;
  string getTitle() const;       
  string getDirector() const;
  int getStock() const;
  int getReleaseYear() const;
  int getMonth() const;           // get the month of release

  // Mutators
  bool addStock(int); 
  bool subStock(int);             // subtract from stock

  set<string> getActors() const;  // get the actors of the movie object

  //---------------------------------------------------------------------------
  // setData()
  // Description: sets data fields
  // PRE: classic exists, stock is already set using addStock()
  //    input format "Hal Ashby, Harold and Maude, Ruth Gordon 3 1971"    
  // POST: all data fields set
  void setData(string movieData);  
  
  // Overloaded operators

  // check if movies are equal and adds actor to actor list
  bool operator==(const Movie& otherMovie);

  // check if movies are not equal  
  bool operator!=(const Movie& otherMovie);

  // check if this movie is greater than other movie  
  bool operator>(const Movie& otherMovie);

  // check if this movie is less than other movie  
  bool operator<(const Movie& otherMovie);
    
private:
    set<string> actorsList;       // List of actors
};

#endif
