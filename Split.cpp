//yo
#include "Split.hpp"

void Split::split(string a, string b)
{
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
                    this->listOfStrings->addEnd(temp2);
                    
                }
                temp = stringAti;
                this->listOfStrings->addEnd(temp);
                
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
        this->listOfStrings->addEnd(temp2);
    }
    this->listOfStrings->display();
}


//update