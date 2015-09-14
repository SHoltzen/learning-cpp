//
// Created by Steven Holtzen on 9/13/15.
//

#ifndef CLION_PRACTICE_PLAYER_H
#define CLION_PRACTICE_PLAYER_H

#include <vector>

using namespace std;

class GameState;

class Player {
private:
    int num_coins;
    /**
     * A sorted list of cards
     */
    vector<int> cards;
public:
    Player(int num_coins) : num_coins(num_coins) { }

    int getNumCoins() { return num_coins; }

    void takeTurn(const GameState *g);

    int calculateScore();

    static int scoreCards(vector<int> c);

    void setCards(const vector<int> c);

    vector<int> const &getCards() {
        return cards;
    }

    void addCard(int c);
};



#endif //CLION_PRACTICE_PLAYER_H
