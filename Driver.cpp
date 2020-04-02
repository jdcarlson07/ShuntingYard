#include <string>
#include <iostream>
using namespace std;
#include "Split.hpp"


int main()
{
    string expression;
    string delims;
    cin >> expression;
    cin >> delims;

    Split* split = new Split();
    Queue* qOfStrings = split->split(expression, delims);
    qOfStrings->display();
    
    return 0;
}