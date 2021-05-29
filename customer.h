#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
    Customer();                            // constructor
    // should we use string for ID?
    Customer(int, string, string);         // ID, first, last
    ~Customer();                           // destructor
    
    // Accessors
    void display();                        // display customer's name and id
    
    int getID();                           //return ID of customer
    string getName();                      // return full name of customer
    
    //Should we use this instead?
    string getFirstName() const;
    string getLastName() const;

    // Mutators
    void addHistory(string);               // add transaction to history
    bool setID(int);
    bool setFirstName(string);
    bool setLastName(string);
    bool setCustomerInfo(int, string, string);

private:
    // not sure about these structs
    struct historyNode {                   
        historyNode* next;		 // Node to keep track of history
        string data;                       // transaction summary
    };
    
    struct checkedOutNode {                
        checkedOutNode* next;		 // Node to keep track of movies borrowed
        Movie* movieBorrowed;              // pointer to movies borrowed
    };
    
    string lastName;			 // lastname of the customer
    string firstName;			 // firstname of the customer
    int ID; 				 // unique user ID
    vector<string> *history;               // linked list of transaction history nodes
 };

 #endif