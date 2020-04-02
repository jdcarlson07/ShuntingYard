#include "Queue.hpp"

Queue::Queue()
{
    this->head = 0;
    this->count = -1;
}


void Queue::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
    cout << currNode->getPayload() << "\n";
}

string Queue::getFront()
{
    if(this->head != 0)
    {
        Node* currNode = this->head;
        if(!currNode->getNextNode())
        {
            string package = currNode->getPayload();
            delete currNode;
            return package;
        }
        else
        {
            Node* newHead = currNode->getNextNode();
            this->head = newHead;
            string package1 = currNode->getPayload();
            delete currNode;
            return package1;
        }
    }
    else
    {
        return "No front yet";
    }
}

void Queue::addEnd(string payload)
{
    Node* n = new Node(payload);
    if(!this->head)
    {
        this->head = n;
    }
    else
    {
        //run to the end of the list
        Node* currNode = this->head;
        while(currNode->getNextNode())
        {
            currNode = currNode->getNextNode();
        }
        currNode->setNextNode(n);
    }
    this->count++;
}
