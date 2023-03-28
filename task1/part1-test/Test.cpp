#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
using namespace ariel;



TEST_CASE("after I create a Player") {
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.stacksize()==0);
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.stacksize()==0);
    CHECK(p2.cardesTaken()==0);
}
TEST_CASE("Create a Game with just one Player") {
    Player p1("Alice");
    Game game1(p1,p1);
    CHECK(p1.stacksize()==26);//I got help from maya zand
    CHECK_THROWS (game1.playTurn());//I got help from maya zand
    CHECK(p1.cardesTaken()==0);
}
TEST_CASE("Create a Game with two Player and chack their stack size and crads taken") {
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1,p2);
    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==26);
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0);
}
TEST_CASE("Create a Game with two Player and chack their stack size and crads taken after one turn") {
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1,p2);
    game1.playTurn();
    CHECK(p1.stacksize()+p1.cardesTaken()+p2.stacksize()+p2.cardesTaken()==52);
    CHECK(p1.stacksize()==26-(p2.cardesTaken()/2));
    CHECK(p2.stacksize()==26-(p2.cardesTaken()/2));
}

TEST_CASE("Create a Game with two Player and chack their stack size and crads taken after one game") {
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1,p2);
    game1.playAll();
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
    CHECK(p1.cardesTaken()+p2.cardesTaken()==52);

}
TEST_CASE("Create a Game with two Player and chack that the print function before starting the game throw eror") {
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1,p2);
    CHECK_THROWS (game1.printLastTurn());
    CHECK_THROWS (game1.printWiner());
    CHECK_THROWS (game1.printLog());
}

TEST_CASE("Create a Game with two Player and chack that the print function after starting the game not throw eror") {
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1,p2);
    game1.playAll();
    CHECK_NOTHROW (game1.printLastTurn());
    CHECK_NOTHROW (game1.printWiner());
    CHECK_NOTHROW (game1.printLog());

}