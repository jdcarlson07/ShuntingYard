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
    split->split(expression, delims);
    
    return 0;
}