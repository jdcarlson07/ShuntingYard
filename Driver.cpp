#include <string>
#include <iostream>
using namespace std;
#include "ShuntingYard.hpp"


int main()
{
    string expression;
    string delims;
    cin >> expression;
    cin >> delims;

    ShuntingYard* shuntyard = new ShuntingYard();
    Queue* inputQ = shuntyard->split(expression, delims);
    cout << std::to_string(inputQ->count);
    cout << "\n";
    cout << "\n";
    inputQ->display();
    cout << "\n";
    cout << inputQ->peek();
    cout << "\n";
    cout << "\n";
    Queue* outputQ = shuntyard->outputQ(inputQ);
    outputQ->display();
    cout << "\n";
    cout << outputQ->peek();
    cout << "\n";
    
    return 0;
}