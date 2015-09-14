//
// Created by Steven Holtzen on 9/13/15.
//

#include "Player.h"

int Player::scoreCards(vector<int> c) {
    int total = 0;
    int lowest_in_sequence = c[0];
    int prev = lowest_in_sequence;
    for (int i = 1; i < c.size(); i++) {
        if (c[i] - prev != 1) {  // sequence broken
            total += lowest_in_sequence;
            lowest_in_sequence = c[i];
        }
        prev = c[i];
    }
    total += lowest_in_sequence; // add the dangling lowest_in_sequence
    return total;
}

void Player::addCard(int c) {
    cards.push_back(c);
    sort(cards.begin(), cards.end());
}

int Player::calculateScore() {
    if (cards.empty()) {
        return -num_coins;
    }
    return scoreCards(cards) - num_coins;
}

void Player::setCards(const vector<int> c) {
    cards = c;
}

void Player::takeTurn(const GameState *g) {

}