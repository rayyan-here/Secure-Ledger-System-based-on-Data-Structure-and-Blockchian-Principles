
#include <iostream>
#include "include/Utils.h"
#include "include/Block.h"
using namespace std;


int main() {string hash = Utils::sha256("Hello Blockchain");
    cout << "Hash: " << hash << endl;
    
    string randomStr = Utils::generateRandomString(10);
    cout << "Random: " << randomStr << endl;
    
    cout << "Timestamp: " << Utils::getCurrentTimestamp() << endl;



// main.cpp (update)
    Block block(1, "0000000000", "ValidatorA");
    
    Transaction tx1("Alice", "Bob", 50);
    tx1.signTransaction();
    block.addTransaction(tx1);
    
    Transaction tx2("Bob", "Charlie", 25);
    tx2.signTransaction();
    block.addTransaction(tx2);
    
    block.finalizeBlock();
    block.print();
    
    cout << "Block valid? " << (block.isValid() ? "Yes" : "No") << endl;
    
    return 0;
}