#include "Node.hpp"

class Queue
{

    public:
        Node* head;
        int count;
        Node* tail;
        Queue();
        void addEnd(string payload);
        string getFront();
        void display();
        string peek();
};