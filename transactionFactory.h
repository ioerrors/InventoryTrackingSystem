/////////////////////////transactionFactory.h file  ///////////////////////////
//-----------------------------------------------------------------------------
// Created by Micah Rice and Abraham Sham on 05/25/2021.
//-----------------------------------------------------------------------------
// This is a class to build the action types
//-----------------------------------------------------------------------------

class TransactionFactory {
public:

    TransactionFactory();              // constructor
    ~TransactionFactory();             // destructor

    Transaction getTransaction(char type) {
        switch (type) {
            case type = 'H':
                return new History();
            case type = 'I':
                return new Inventory();
            case type = 'R':
                return new Return();
            case type = 'B':
                return new Borrow();
            default:
                throw new NotSupportedException("Transaction type not found");
        }
    }

 
};
