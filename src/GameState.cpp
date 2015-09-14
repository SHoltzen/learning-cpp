//
// Created by Steven Holtzen on 9/13/15.
//

#include "GameState.h"
#include "Player.h"

using namespace std;

GameState::GameState(int num_players, int num_coins, vector<int> newdeck) {
    // init players
    for(int i = 0; i < num_players; i++) {
        players.push_back(make_shared<Player>(num_coins));
    }
    this->deck = newdeck;
    num_coins_in_pool = 0;
}

GameState::GameState(int num_players, int num_coins, int deck_lower, int deck_upper) :
        GameState(num_players, num_coins, vector<int>()) {
    vector<int> deck;
    for(int i = deck_lower; i < deck_upper; i++) {
        deck.push_back(i);
    }
    // init deck
    random_shuffle(deck.begin(), deck.end());
    // remove float_pct% of the deck
    for(int i = 0; i < (int)(deck.size() * GameState::missing_rate); i++){
        deck.pop_back();
    }
    this->deck = deck;
}

void GameState::takeTurn() {
    for(shared_ptr<Player> p : players) {
        p->takeTurn(this);
    }
}

void GameState::runGame() {
    while(!deck.empty()) {
        takeTurn();
    }
}

const int GameState::showTop() { return deck.back(); }

const int GameState::numCoinsInPool() {return num_coins_in_pool; }

void GameState::takeCard() { deck.pop_back(); num_coins_in_pool = 0; }