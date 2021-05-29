////////////////////////////////hashTable.h file  /////////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This class is a data structure to hold customers
// in a quickly accessable format
//-----------------------------------------------------------------------------

class HashTable {
    
    friend ostream& operator<< (ostream&, const HashTable&); 	// Overloaded << : prints HashTable in correct structure
    
public:
    
    HashTable ();             // constructor
    ~HashTable ();            // desctructor
    

    //find
    bool getCustomer (const int cID, Customer*&) const;            // get Customer
    
    //insert
    bool addCustomer(Customer*&);                                 // add Customer 
    
private:

};