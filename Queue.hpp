#include "Node.hpp"

class Queue
{
    private:
        Node* head;
        int count;

    public:
        Queue();
        void addEnd(string payload);
        string getFront();
        void display();
};