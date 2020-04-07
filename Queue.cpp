#include "Queue.hpp"

Queue::Queue()
{
    this->head = 0;
    this->count = 0;
    this->tail = 0;
}


void Queue::display()
{
    Node* currNode = this->head;
    while(currNode)
    {
        cout << currNode->getPayload() << " ";
        currNode = currNode->getNextNode();
    }
    cout << "\n";
}

string Queue::getFront()
{
    if(this->head)
    {
        Node* temp = this->head;
        this->head = this->head->getNextNode();
        string package = temp->getPayload();
        delete temp;
        this->count--;
        return package;
    }
    else
    {
        return "No front yet"; //will never happen
    }
}

void Queue::addEnd(string payload)
{
    Node* n = new Node(payload);
    if(this->tail)
    {
        this->tail->setNextNode(n);
        this->tail = n;
        
    }
    else
    {
        this->head = n;
        this->tail = n;
    }
    this->count++;
}

string Queue::peek()
{
    string package = this->head->getPayload();
    return package;
}