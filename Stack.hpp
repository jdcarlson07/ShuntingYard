#include "Node.hpp"
#include <string>
using namespace std;

class Stack
{
    private:
        
        

    public:
        Node* top;
        int count;
        Stack();
        void push(string payload);
        string pop();
        string peek();
        void display();
        
        
        
};