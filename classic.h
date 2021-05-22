////////////////////////////////classic.h file  ///////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a classic class which is a type of movie 
// child of the movie class, inheriting from Movie
//-----------------------------------------------------------------------------

struct actorNode {
    string actor; // major actor of the movie
    int stock;    // the number of stock for movies
    actorNode* next; // Node to keep track of actor 
};

class Classic : public Movie
{
public:
    
    Classic(char genre, char mediaType, string title, string director, int stock, int yearRelease, int monthReleased, string actor);               // constructor
    ~Classic();                                     // destructor
    
    // Overloaded operators
    virtual bool operator == (const Movie&) const;  // check if movies are equal
    virtual bool operator != (const Movie&) const;  // check if movies are not equal
    virtual bool operator > (const Movie&) const;   // check if this movie is greater than rhs movie
    virtual bool operator < (const Movie&) const;   // check if this movie is less than rhs movie
    
    // Accessors
    virtual int getMonth() const;
    virtual void display() const;                   // print out movie data and return string
    virtual string getActor() const;                // get the major actor for the movie
    int getTotalStock() const;                      // get total stock of all the same movies
    
    // Mutators
    virtual bool subtractFromStock(int);            // subtract from stock
    virtual void addSameMovies(Movie*&);            // add the same movie to the list of same movies
    
private:
    vector<Movie*> sameMoviesList;                  // List for the same movies
    string actor;				 // store the actor
    int monthReleased;                              // month of the movie release
};