#include <iostream>
#include <string.h>
#include "card.hpp"
using namespace std;

namespace ariel{
    class Player{
        private:
            string name;
            int stackSize;

        public:
            Player(string Name){
            name = Name;
            stackSize = 0;
            }
            Player(){
                name = "player";
            }
            int stacksize(){
                return stackSize;
            }
            // cardesTaken();
    };
}

