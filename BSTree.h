////////////////////////////////BSTree.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice & Abraham Sham on 05/25/2021.
//
// BSTree class demonstrating data structure
// Can search a BSTree and find items in O(log n) time.
// No duplicates are allowed.

#ifndef ASS5_BSTREE_H
#define ASS5_BSTREE_H

#include "movie.h"
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------
class BSTree {

  //---------------------------------------------------------------------------
  // Overloaded Operator <<
  // Description: traverses tree inorder, 
  //              and prints each node's data as it passes
  // PRE: BSTree exists
  // POST: All contained nodes are printed in order
  friend ostream &operator<<(ostream &os, const BSTree&);

private:

  struct Node {
    Movie* data = new Movie();         // pointer to data object
    Node* left = nullptr;             // left subtree pointer
    Node* right= nullptr;            // right subtree pointer
  };

  Node* root;               // root of the tree

  //---------------------------------------------------------------------------
  // copyHelper
  // Description: recursively creates deep copies of data from currentOther
  //              to the current tree
  // PRE: Memory is available for BSTree
  // POST: SHALLOW Copy of othercurrent is created in this tree
  void copyHelper(Node* current, Node* currentOther);

  //---------------------------------------------------------------------------
  // clear()
  // Description: deletes all nodes in BSTree
  //              traverses and delete in postorder fashion
  // PRE: BSTree exists
  // POST: BSTree is deletedd from memory
  //       all allocated memory for the BSTree is freed
  void clear(Node *subTreePtr);

  //---------------------------------------------------------------------------
  // equalsHelper
  // Description: recursively compares data from currentOther
  //              to the current tree
  // PRE: current and currentOther belong to seperate BSTree
  // POST: returns true if current node and currentOther node contain
  //       identical subtrees
  bool equalsHelper(Node* current, Node* currentOther) const;



public:

  //---------------------------------------------------------------------------
  // BSTree CONSTRUCTOR
  // Description: creates an empty BSTree
  // PRE: Memory is available for BSTree
  // POST: Empty BSTree is created
  BSTree(); 

  //---------------------------------------------------------------------------
  // BSTree COPY CONSTRUCTOR
  // Description: creates an BSTree that is an exact 
  //              deep copy of otherBSTree
  // PRE: Memory is available for BSTree
  // POST: Exact Deep Copy of otherBSTree is created
  BSTree(const BSTree &otherBSTree);       // copy constructor


  //---------------------------------------------------------------------------
  // BSTree DESTRUCTOR
  // Description: deallocates all memory allocated for BSTree
  //              calls makeEmpty()
  // PRE: BSTree exists
  // POST: All BSTree memory is freed, objects deleted
  ~BSTree();


  //---------------------------------------------------------------------------
  // isEmpty()
  // Description: checks to see if BSTree is empty
  // PRE: BSTree Exists
  // POST: returns true if BSTree contains no nodes
  //       returns false if BSTree contains any nodes
  bool isEmpty() const;


  //---------------------------------------------------------------------------
  // makeEmpty()
  // Description: clears the BSTree of all allocated nodes, freeing memory
  // PRE: BSTree Exists
  // POST: BSTree is now empty, memory of deleted nodes freed
  void makeEmpty();


  //---------------------------------------------------------------------------
  // operator =
  // Description: sets this BSTree equal to otherBSTree
  // PRE: BSTree Exists
  // POST: BSTree is now equal to otherBSTree, 
  //       any memory of deleted nodes freed
  // ASSUMPTION: Intent is to create a SHALLOW copy of otherBSTree
  BSTree& operator=(const BSTree &otherBSTree);


  //---------------------------------------------------------------------------
  // operator ==
  // Description: checks if this BSTree is equal to otherBSTree
  // PRE: BSTree Exists
  // POST: returns true if this BSTree is equal to otherBSTree
  //       OR returns false if this BSTree is not equal to otherBSTree
  bool operator==(const BSTree &otherBSTree) const;


  //---------------------------------------------------------------------------
  // operator !=
  // Description: checks if this BSTree is equal to otherBSTree
  //              calls operator == 
  // PRE: BSTree Exists
  // POST: returns false if this BSTree is equal to otherBSTree
  //       OR returns true if this BSTree is not equal to otherBSTree
  bool operator!=(const BSTree &otherBSTree) const;


  //---------------------------------------------------------------------------
  // insert()
  // Description: attempts to add node to BSTree, returns status of success
  // PRE: BSTree Exists
  // POST: returns false if this BSTree already contains Node
  //       OR returns true if this BSTree successfully added Node
  bool insert(Movie*);

  //---------------------------------------------------------------------------
  // insert()
  // Description: attempts to retrieve node from BSTree, 
  //              returns status of success
  // PRE: BSTree Exists
  // POST: returns true if this BSTree contains Node, 
  //       and Movie* & is now pointing to its location
  //       OR returns false if this BSTree does not contain node
  bool retrieve(const Movie &, Movie* &) const;

  //---------------------------------------------------------------------------
  // inOrderHelper()
  // Description: gives an inorder traversal of the tree to the ostream
  // PRE: BSTree Exists
  // POST: ostream now contains an inorder traversal of the tree
  string inOrderHelper(Node *current) const;


  //---------------------------------------------------------------------------
  // getRoot()
  // Description: returns the root of this BSTree
  // PRE: BSTree Exists
  // POST: returned the value of the root
  Node* getRoot() const;

};


#endif //ASS5_BSTREE_H
