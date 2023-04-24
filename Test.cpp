#include <iostream>
#include <stdexcept>

#include "doctest.h"
#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"

using namespace ariel;
using namespace std;


TEST_CASE("Player Initialization"){
    Player Alice("Alice");
    Player Bob("Bob");
    Player Charlie("Charlie");
    Player Dani("Dani");

    CHECK(Alice.stacksize() == 0);
    CHECK(Alice.cardesTaken() == 0);

    Game game1(Alice, Bob);
    CHECK_NOTHROW(game1.playTurn());

    Game game2(Alice, Alice);
    CHECK_THROWS(game2.playTurn());
    CHECK_THROWS(game2.playAll());

    Game game3(Bob, Charlie);
    CHECK_THROWS(game3.playTurn());
    CHECK_THROWS(game3.playAll());

    Game game4(Charlie, Dani);
    CHECK_NOTHROW(game4.playTurn());
    CHECK_NOTHROW(game4.playAll());
}

TEST_CASE("Turn Played"){
    Player Alice("Alice");
    Player Bob("Bob");
    Game game(Alice, Bob);
    game.playTurn();
    
    bool cardesTaken1 = ((Alice.cardesTaken() % 2 == 0) && (Bob.cardesTaken()== 0));
    bool cardesTaken2 = ((Alice.cardesTaken() == 0) && (Bob.cardesTaken() % 2 == 0));
    bool cardesTaken3 = ((Alice.cardesTaken() == 26) && (Bob.cardesTaken() == 26));
    bool cardesTaken = cardesTaken1 || cardesTaken2 || cardesTaken3;
    CHECK(cardesTaken);

    for(int i = 0; i < 5; i++){
        game.playTurn();
        CHECK(Alice.stacksize() == Bob.stacksize());
    }
}

TEST_CASE("Game played"){
    Player Alice("Alice");
    Player Bob("Bob");
    Game game(Alice, Bob);

    CHECK(Alice.stacksize() == 26);
    CHECK(Bob.stacksize() == 26);
    game.playAll();
    CHECK(Alice.stacksize() == 0);
    CHECK(Bob.stacksize() == 0);
    CHECK_THROWS(game.playTurn());
}
