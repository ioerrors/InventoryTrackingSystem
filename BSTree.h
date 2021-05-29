////////////////////////////////BSTree.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice & Abraham Sham on 05/25/2021.
//
// BSTree class demonstrating data structure
// Can search a BSTree and find items in O(log n) time.
// No duplicates are allowed.

#ifndef ASS5_BSTREE_H
#define ASS5_BSTREE_H

#include "nodedata.h"
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
    NodeData* data = new NodeData();         // pointer to data object
    Node* left = nullptr;             // left subtree pointer
    Node* right= nullptr;            // right subtree pointer
  };

  Node* root;               // root of the tree

  //---------------------------- Sideways -------------------------------------
  // Helper method for displaySideways
  // Preconditions: NONE
  // Postconditions: BSTree remains unchanged.
  void sideways(Node*, int) const; 

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

  //---------------------------------------------------------------------------
  // heighthelper()
  // Description: recursively finds the height of a given node in the tree
  // PRE: BSTree Exists
  // POST: returns the height of the node in the BSTree
  //              value not found returns 0
  int heightHelper(Node* current, int height) const;

  //---------------------------------------------------------------------------
  // toArrayHelper()
  // Description: recursively converts bst to array
  // PRE: BSTree Exists, has <= array size nodes
  // POST: data is in the array
  void toArrayHelper(NodeData* [], int index, Node* current);

  //---------------------------------------------------------------------------
  // arrayToBSTreeHelper()
  // Description: recursive helper function for BSTree array to BST
  //              recursively adds nodes
  // PRE: BSTree exists with a root node already instantiated
  // POST: BSTree is constructed in full after all recursive calls finish
  void arrayToBSTreeHelper(int start, int end, NodeData* array[]);

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
  bool insert(NodeData*);

  //---------------------------------------------------------------------------
  // insert()
  // Description: attempts to retrieve node from BSTree, 
  //              returns status of success
  // PRE: BSTree Exists
  // POST: returns true if this BSTree contains Node, 
  //       and NodeData* & is now pointing to its location
  //       OR returns false if this BSTree does not contain node
  bool retrieve(const NodeData &, NodeData* &) const;


  //---------------------------------------------------------------------------
  // getHeight()
  // Description: finds the height of a given node in the tree
  // PRE: BSTree Exists
  // POST: returns the height of the node in the BSTree
  //              value not found returns 0
  int getHeight (const NodeData &) const;
  
  //---------------------------------------------------------------------------
  // bstreeToArray()
  // Description: converst bst to array, leaving bst empty
  // PRE: BSTree Exists, has <= arraysize nodes
  // POST: BSTree is now empty, data is in the array
  void bstreeToArray(NodeData* []);


  //---------------------------------------------------------------------------
  // arrayToBSTree()
  // Description: converts array to bst, leaving array full of nulls
  // PRE: BSTree Exists
  // POST: array is now empty, data is in the bst replacing any old data
  void arrayToBSTree(NodeData* []);

  //------------------------- displaySideways ---------------------------------
  // Displays a binary tree as though you are viewing it from the side;
  // hard coded displaying to standard output.
  // Preconditions: NONE
  // Postconditions: BSTree remains unchanged.
  void displaySideways() const;     // provided below, displays the tree sideways

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
