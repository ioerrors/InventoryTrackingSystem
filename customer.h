class Customer {
public:
    Customer();                            // constructor
    Customer(int, string, string);         // ID, first, last
    ~Customer();                           // destructor
    
    // Accessors
    void display();                        // display customer's name and id
    
    int getID();                           // return ID of customer
    string getName();                      // return full name of customer
    
    // Mutators
    void addHistory(string);               // add transaction to history
    
private:
    struct historyNode {                   
        historyNode* next;		 // Node to keep track of history
        string data;                       // transaction summary
    };
    
    string lastName;			 // lastname of the customer
    string firstName;			 // firstname of the customer
    int ID; 				     // unique user ID
    historyNode* headHistory;               // linked list of transaction history nodes
 };