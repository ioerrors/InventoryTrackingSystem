
#include <iostream>
#include <sstream>
#include <stack>

#include "BSTree.h"
#include "customer.h"
#include "hashTable.h"
#include "movieFactory.h"
#include "transaction.h"

using namespace std;

Customer::Customer() {
  setID(0);
  setFirstName("");
  setLastName("");
}

Customer::Customer(int cID, string first, string last) {
  setID(cID);
  setFirstName(first);
  setLastName(last);
}

int Customer::getID() const { return customerID; }

string Customer::getName() const {
  string fullName = firstName + " " + lastName;
  return fullName;
}

string Customer::getFirstName() const { return firstName; }

string Customer::getLastName() const { return lastName; }

stringstream Customer::getHistory() {
  stringstream os;
  while (!history.empty()) {
    os << history.top();
    history.pop();
  }
  return os;
}

void Customer::addHistory(string transaction) { history.push(transaction); }

bool Customer::setCustomerInfo(int cID, string first, string last) {
  return setID(cID) && setFirstName(first) && setLastName(last);
}

bool Customer::setID(int cID) {
  customerID = cID;
  return true;
}

bool Customer::setFirstName(string first) {
  firstName = first;
  return true;
}

bool Customer::setLastName(string last) {
  lastName = last;
  return true;
}
