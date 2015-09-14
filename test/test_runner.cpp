//
// Created by Steven Holtzen on 9/13/15.
//

#include "test_runner.h"
#include "catch.h"
#include "main.h"
#include <vector>

using namespace std;

TEST_CASE( "Calculating player scores", "[player]" ) {
    Player p(0);
    p.setCards(vector<int>{1, 2, 3, 6});
    REQUIRE(p.calculateScore() == 7);
    p.setCards(vector<int>{});
    REQUIRE(p.calculateScore() == 0);
    p.setCards(vector<int>{1});
    REQUIRE(p.calculateScore() == 1);
    p.setCards(vector<int>{1,3,5});
    REQUIRE(p.calculateScore() == 9);
    p.setCards(vector<int>{-1, 1});
    REQUIRE(p.calculateScore() == 0);
}

TEST_CASE("Adding cards", "[player]") {
    Player p(0);
    p.addCard(5);
    p.addCard(3);
    auto cards = p.getCards();
    auto expected = vector<int>{3,5};
    REQUIRE(cards == expected);
}