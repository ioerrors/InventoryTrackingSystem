////////////////////////////////transaction.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to hold a single customer
//-----------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer {

public:
    Customer();                            // constructor

    Customer(int cID, string first, string last);         // ID, first, last

    ~Customer();                           // destructor
    



    // Accessors
    void display() const;                 // display customer's name and id
    
    int getID() const;                    // return ID of customer
    string getName() const;               // return full name of customer
    string getFirstName() const;
    string getLastName() const;

    //basically an overloaded << operator just for history
    ostream getHistory();           
  
    // Mutators
    void addHistory(string transaction);               // add transaction to history
    bool setCustomerInfo(int cID, string first, string last);        
    bool setID(int cID);
    bool setFirstName(string first);
    bool setLastName(string last);
    
private:
    // not sure about these structs
    struct historyNode {                   
        historyNode* next;     // Node to keep track of history
        string data;             // transaction summary
    };
    
    string lastName;       // lastname of the customer
    string firstName;      // firstname of the customer

    int customerID;        // unique user ID
    historyNode* headHistory;    // linked list of transaction history nodes
}; 
#endif

