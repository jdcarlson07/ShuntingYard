//yo
#include "ShuntingYard.hpp"

Queue* ShuntingYard::split(string a, string b)
{
    Queue* qOfStrings = new Queue();
    int signal = 0;
    string stringToSplit = a;
    string delims = b;
    int length = stringToSplit.length();
    int lengthOfDelims = delims.length();
    string temp = "";
    string temp2 = "";
    for(int i = 0; i < length; ++i)
    {   
        char stringAti = stringToSplit.at(i);
        
        for(int j = 0; j < lengthOfDelims; ++j )
        {
            char delimAti = delims.at(j);
            if(stringAti != delimAti) //the char we are looking at is not a delimeter
            {
                temp = stringAti;
                signal = 1;
            }
            else //the char we are looking at is a delimeter
            {
                signal = 0;
                if(temp2 != "")
                {
                    qOfStrings->addEnd(temp2);
                    
                }
                temp = stringAti;
                qOfStrings->addEnd(temp);
                
                temp = "";
                temp2 = "";
                break;
            }
        }
        if(signal != 0)
        {
            temp2 = temp2 + temp;
        }
    } 
    if(temp2 != "")
    {
        qOfStrings->addEnd(temp2);
    }
    return qOfStrings;
}

Queue* ShuntingYard::outputQ(Queue* inputQ)
{
    
    Queue* outputQ = new Queue();
    Stack* operatorStack = new Stack();
    operatorStack->push(" ");
    string temp;
    int count = inputQ->count;
    
    for(int i = 0; i < count; i++)
    {
        temp = inputQ->getFront();
        
        //check to see if string is a number, if so take from inputQ and add to outputQ
        if(temp != "*" && temp != "/" && temp != "+" && temp != "-")
        {
            outputQ->addEnd(temp);
                
        }
        //we have hit an operator
        else
        {
            int tempPrecedence = this->convertToPrecedence(temp);
            //nothing in op stack yet
            if(!operatorStack->top)
            {
                operatorStack->push(temp);
            }
            //something in op stack
            else
            {
                while(this->convertToPrecedence(operatorStack->peek()) >= tempPrecedence )
                {
                    outputQ->addEnd(operatorStack->pop());
                }
                operatorStack->push(temp);
            }
        } 
    }
    int opCount = operatorStack->count;
    for(int j = 0; j < opCount; j++)
    {
        string temp1 = operatorStack->pop();
        outputQ->addEnd(temp1);
        
    }
    
    return outputQ;
}


int ShuntingYard::convertToPrecedence(string op)
{
    if(op == "*")
    {
        return 3;
    }
    else if(op == "/")
    {
        return 3;
    }
    else if(op == " ")
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

