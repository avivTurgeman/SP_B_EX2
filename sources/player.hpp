#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string.h>
#include "card.hpp"
using namespace std;

namespace ariel{
    class Player{
        private:
            string name;
            int stackSize;
            int cards_winning_balanse;

        public:
            Player(string Name){
            name = Name;
            stackSize = 0;
            cards_winning_balanse = 0;
            }
            Player(){
                name = "player";
            }
            int stacksize(){
                return stackSize;
            }
            int cardesTaken(){
                return cards_winning_balanse;
            }
    };
}

#endif