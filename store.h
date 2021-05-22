////////////////////////////////store.h file  /////////////////////////////////
//-----------------------------------------------------------------------------
// Created by Group 1 on 05/19/2021.
//-----------------------------------------------------------------------------
// This is a class to hold the main actions of the Inventory management 
// system of the media store
//-----------------------------------------------------------------------------

class Store {
public:
    Store();         // constructor
    ~Store();        // destructor
    
    void readCustomerFile (ifstream&);             // load customers into customerTable
    void readMovieFile (ifstream&);                // load movies into movieTable
    void readTransactionFile (ifstream&);          // read transactions and execute
    bool performTransaction (Transaction*);        // execute a transaction
    
private:
    MovieInventory movieTree;                      // BST of movies
    CustomerInventory customerTable;               // hash table of customers
    TransactionFactory transFactory;               // transaction factory
    
};