#include "Stack.hpp"
#include "Node.hpp"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack()
{
    this->top = 0;
    this->count = 0;
}

void Stack::push(string payload)
{

    Node* n = new Node(payload);
    if(this->top)
    {
        //we have at least one element on our stack
        n->setNextNode(this->top);
        this->top = n;
        this->count++;
    }
    else
    {
        this->top = n;
        this->count++;
    }
    
}

string Stack::pop()
{
    Node* nodeToReturn = this->top;
    this->top = top->getNextNode();
    this->count--;
    string package = nodeToReturn->getPayload();
    delete nodeToReturn;
    return package;
}

string Stack::peek()
{
    return this->top->getPayload();
}

void Stack::display()
{
    if(this->top)
    {
        Node* currNode = this->top;
        while(currNode)
        {
            std::cout << currNode->getPayload() << "\n";
            currNode = currNode->getNextNode();
        }
    }
    else
    {
        std::cout << "Empty Stack\n";
    }
}








