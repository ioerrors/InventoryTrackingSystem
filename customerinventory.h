class CustomerInventory {
public:
    static const int MAX = 10000;            // max number of IDs
    
    CustomerInventory();                     // constructor
    ~CustomerInventory();                    // destructor
    
    Customer* getCustomer (int);             // get Customer with ID
    bool customerExist (int);                // check if customer exists with ID
    bool addCustomer(int, string, string);   // add customer to inventory
    bool removeCustomer(int);                // remove customer from inventory
    
private:
    struct customerNode {
        Customer* customer;                  // pointer for customer object
        customerNode* next;                  // pointer for moving to next object
    };
    customerNode* hashTable[MAX];            // open hash table for customer nodes
    
    // helper functions
    int hashFunction(int);                   // calculate which bucket to insert customer
};