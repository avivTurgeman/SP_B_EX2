#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
using namespace std;

namespace ariel{
    class Card
    {
    private:
        int number;
        string type;
    public:
        Card(int num, string c_type){
            number = num;
            type = c_type;
        }
    };
    
} 

#endif