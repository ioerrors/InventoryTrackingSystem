class Customer {
public:
    Customer();                            // constructor
    Customer(int cID, string first, string last);         // ID, first, last
    ~Customer();                           // destructor
    
    void setCustomer(int cID, string first, string last);
    // Accessors
    void display();                        // display customer's name and id
    
    int getID();                           // return ID of customer
    string getName();                      // return full name of customer
    
    historyNode* getHistory(); //maybe return ostream?

    // Mutators
    void addTrans(string);               // add transaction to history
    
private:
    struct historyNode {                   
        historyNode* next;		 // Node to keep track of history
        string data;                       // transaction summary
    };
    
    string lastName;			 // lastname of the customer
    string firstName;			 // firstname of the customer
    int customerID; 				     // unique user ID
    historyNode* headHistory;               // linked list of transaction history nodes
 };