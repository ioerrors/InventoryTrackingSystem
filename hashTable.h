////////////////////////////////tree.h file  //////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This class is a data structure to hold movies in a sorted format
//-----------------------------------------------------------------------------

struct Node { 				// BST Node contains pointer for left, right, and movie
    Node* left;
    Node* right;
    Movie* movie;
};

class BST {
    
    
    friend ostream& operator<< (ostream&, const BST&); 	// Overloaded << : prints BST in correct structure
    
public:
    
    BST ();             // constructor
    ~BST ();            // desctructor
    
    bool getMovie (const Movie&, Movie*&) const;            // get movie from the tree
    bool addMovie(Movie*&);                                 // add movie node
    bool getMovieByTitle (string, int, Movie*&);            // returns true if movie is found in BSTree by its title

    void resetCounted();                                    // reset movie counted status to false
    
    
private:
    Node* root;                                 // points to the root of the BST
    
    void makeEmptyHelper (Node* &);             // private functions
    void printHelpNode (Node* cur) const;         // helper method for print
    bool insertHelper (Node *&, Movie*&);       // helper method for insert
    bool retrieveHelper (const Movie&, Movie*& , Node*) const;   // helper method for retrieve
    void resetHelper(Node*);                    // helper method for reset
    bool getMovieByTitleHelper (string title, int year, Movie*&, Node*);  // helper method for getMovieByTitle
};