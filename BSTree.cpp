////////////////////////////////BSTree.cpp file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//
// BSTree class demonstrating data structure
// Can search a BSTree and find items in O(log n) time.
// No duplicates are allowed.

#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>


#include "transaction.h"
#include "return.h"
#include "inventory.h"
#include "history.h"
#include "HashTable.h"
#include "BSTree.h"
#include "business.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "customer.h"
#include "movieFactory.h"
#include "transactionFactory.h"
using namespace std;

//-----------------------------------------------------------------------------
// Overloaded Operator <<
// Description: traverses tree inorder,
//              and prints each node's data as it passes
// PRE: BSTree exists
// POST: All contained nodes are printed in order
ostream &operator<<(ostream &os, const BSTree &bst) {
  // return if the tree is empty
  if (bst.isEmpty()) {
    return os;
  }
  // iterate inOrderHelper
  os << bst.inOrderHelper(bst.getRoot()) << endl;
  return os;
}

//-----------------------------------------------------------------------------
// inOrderHelper()
// Description: gives an inorder traversal of the tree to the ostream
// PRE: BSTree Exists
// POST: ostream now contains an inorder travesral of the tree
string BSTree::inOrderHelper(Node *current) const {
  stringstream ss;
  ss << "";
  if (current != nullptr) {
    ss << inOrderHelper(current->left);
    ss << *current->data;
    ss << " ";
    ss << inOrderHelper(current->right);
  }
  return ss.str();
}

//-----------------------------------------------------------------------------
// BSTree CONSTRUCTOR
// Description: creates an empty BSTree
// PRE: Memory is available for BSTree
// POST: Empty BSTree is created
BSTree::BSTree() {
  root = new Node;
  root->data = nullptr;
  root->left = nullptr;
  root->right = nullptr;
}

//-----------------------------------------------------------------------------
// BSTree COPY CONSTRUCTOR
// Description: creates an BSTree that is an exact
//              deep copy of otherBSTree
// PRE: Memory is available for BSTree
// POST: Exact Deep Copy of otherBSTree is created
BSTree::BSTree(const BSTree &otherBSTree) {
  Node *currentOther = otherBSTree.getRoot();
  Node *current = root;
  copyHelper(current, currentOther);
}

//-----------------------------------------------------------------------------
// copyHelper
// Description: recursively creates deep copies of data from currentOther
//              to the current tree
// PRE: Memory is available for BSTree
// POST: SHALLOW Copy of othercurrent is created in this tree
void BSTree::copyHelper(Node *current, Node *currentOther) {
  if (currentOther->data != nullptr) {
    current->data = currentOther->data;
    if (currentOther->left != nullptr) {
      current->left = new Node;
      copyHelper(current->left, currentOther->left);
    }
    if (currentOther->right != nullptr) {
      current->right = new Node;
      copyHelper(current->right, currentOther->right);
    }
  }
}

//-----------------------------------------------------------------------------
// BSTree DESTRUCTOR
// Description: deallocates all memory allocated for BSTree
//              calls makeEmpty()
// PRE: BSTree exists
// POST: All BSTree memory is freed, objects deleted
BSTree::~BSTree() {
  makeEmpty();
  root = nullptr;
  delete root;
}

//-----------------------------------------------------------------------------
// isEmpty()
// Description: checks to see if BSTree is empty
// PRE: BSTree Exists
// POST: returns true if BSTree contains no nodes
//       returns false if BSTree contains any nodes
bool BSTree::isEmpty() const { return root->data == nullptr; }

//-----------------------------------------------------------------------------
// makeEmpty()
// Description: clears the BSTree of all allocated nodes, freeing memory
// PRE: BSTree Exists
// POST: BSTree is now empty, memory of deleted nodes freed
void BSTree::makeEmpty() {
  clear(root);
  root = new Node;
  root->data = nullptr;
  root->left = nullptr;
  root->right = nullptr;
}

//-----------------------------------------------------------------------------
// clear()
// Description: deletes all nodes in BSTree
//              traverses and deletes in postorder fashion
// PRE: BSTree exists
// POST: BSTree is deleted from memory
//       all allocated memory for the BSTree is freed
void BSTree::clear(Node *subTreePtr) {
  if (subTreePtr != nullptr) {
    if (subTreePtr->left != nullptr) {
      clear(subTreePtr->left);
    }
    if (subTreePtr->right != nullptr) {
      clear(subTreePtr->right);
    }
    subTreePtr->left = nullptr;
    subTreePtr->right = nullptr;
    if (subTreePtr != root) {
      delete subTreePtr;
    }
  }
}

//-----------------------------------------------------------------------------
// operator =
// Description: sets this BSTree equal to otherBSTree
// PRE: BSTree Exists
// POST: BSTree is now equal to otherBSTree,
//       any memory of deleted nodes freed
// ASSUMPTION: Intent is to create a SHALLOW copy of otherBSTree
BSTree &BSTree::operator=(const BSTree &otherBSTree) {
  if (otherBSTree != *this) {
    makeEmpty();
    Node *currentOther = otherBSTree.getRoot();
    Node *current = root;
    copyHelper(current, currentOther);
    return *this;
  } else {
    return *this;
  }
}

//-----------------------------------------------------------------------------
// equalsHelper
// Description: recursively compares data from currentOther
//              to the current tree
// PRE: current and currentOther belong to seperate BSTree
// POST: returns true if current node and currentOther node contain
//       identical subtrees
bool BSTree::equalsHelper(Node *current, Node *currentOther) const {
  bool final = true;
  if (currentOther == nullptr && current != nullptr) {
    return false;
  }
  if (currentOther != nullptr && current == nullptr) {
    return false;
  }
  if (currentOther != nullptr && current != nullptr) {
    final = current->data == currentOther->data &&
            equalsHelper(current->left, currentOther->left) &&
            equalsHelper(current->right, currentOther->right);
  }
  return final;
}

//-----------------------------------------------------------------------------
// operator ==
// Description: checks if this BSTree is equal to otherBSTree
// PRE: BSTree Exists
// POST: returns true if this BSTree is equal to otherBSTree
//       OR returns false if this BSTree is not equal to otherBSTree
bool BSTree::operator==(const BSTree &otherBSTree) const {
  Node *currentOther = otherBSTree.getRoot();
  Node *current = this->root;
  if (current->data == currentOther->data) {
    return equalsHelper(current->left, currentOther->left) &&
           equalsHelper(current->right, currentOther->right);
  }
  return false;
}

//-----------------------------------------------------------------------------
// operator !=
// Description: checks if this BSTree is equal to otherBSTree
//              calls operator ==
// PRE: BSTree Exists
// POST: returns false if this BSTree is equal to otherBSTree
//       OR returns true if this BSTree is not equal to otherBSTree
bool BSTree::operator!=(const BSTree &otherBSTree) const {
  return !(*this == otherBSTree);
}

//-----------------------------------------------------------------------------
// insert()
// Description: attempts to add node to BSTree, returns status of success
// PRE: BSTree Exists
// POST: returns false if this BSTree already contains Node
//       OR returns true if this BSTree successfully added Node
bool BSTree::insert(Movie* insertMe) {
  if (insertMe == nullptr) {
    return false;
  }
  Node *current = root;
  if (root->data == nullptr) {
    root->data = insertMe;
  } else {
    while (current->right != nullptr && *current->data < *insertMe) {
      current = current->right;
      while (current->left != nullptr && *insertMe < *current->data) {
        current = current->left;
      }
    }
    while (current->left != nullptr && *insertMe < *current->data) {
      current = current->left;
      while (current->right != nullptr && *current->data < *insertMe) {
        current = current->right;
      }
    }
    if (*current->data == *insertMe) {
      return false;
    } else if (*insertMe < *current->data) {
      current->left = new Node;
      current = current->left;
      current->data = insertMe;
    } else {
      current->right = new Node;
      current = current->right;
      current->data = insertMe;
    }
  }
  return true;
}

//-----------------------------------------------------------------------------
// retrieve()
// Description: attempts to retrieve node from BSTree,
//              returns status of success
// PRE: BSTree Exists
// POST: returns true if this BSTree contains Node,
//       and Movie* & is now pointing to its location
//       OR returns false if this BSTree does not contain node
bool BSTree::retrieve(const Movie &checkMe, Movie *&setMe) const {
  Node *current = root;
  while (current->right != nullptr && *current->data < checkMe) {
    current = current->right;
  }
  while (current->left != nullptr && checkMe < *current->data) {
    current = current->left;
  }
  if (*current->data == checkMe) {
    setMe = current->data;
    return true;
  }
  return false;
}


//-----------------------------------------------------------------------------
// getRoot()
// Description: returns the root of this BSTree
// PRE: BSTree Exists
// POST: returned the value of the root
BSTree::Node *BSTree::getRoot() const { return root; }
