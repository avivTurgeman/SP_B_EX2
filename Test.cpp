#include <iostream>
#include <stdexept>

#include "doctest.h"
#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"

using namespace ariel;
using namespace std;


TEST_CASE("Player Initialization"){
    Player player("player");
    
    CHECK(player.stacksize() == 0);
    CHECK(player.cardesTaken() == 0);
}

TEST_CASE("Game Initialization"){
    Player player1("player1");
    Player player2("player2");
    Game game1(player1, player2);
    Game game2(player1, player1);

    CHECK(player1.stacksize == 26);
    CHECK(player2.stacksize == 26);
    CHECK_THROWS(game2.playTurn());
    CHECK_THROWS(game2.playAll());
}

TEST_CASE("Turn Played"){
    Player player1("player1");
    Player player2("player2");
    Game game(player1, player2);
    game.playTurn();

    CHECK(player1.stacksize == player2.stacksize);
}

TEST_CASE("Game played"){
    Player player1("player1");
    Player player2("player2");
    Game game(player1, player2);
    game.playAll();

    CHECK(player1.stacksize == 0);
    CHECK(player2.stacksize == 0);
}
