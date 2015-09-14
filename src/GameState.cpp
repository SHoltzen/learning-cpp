//
// Created by Steven Holtzen on 9/13/15.
//

#include "GameState.h"
#include "Player.h"

using namespace std;

GameState::GameState(int num_players, int num_coins, vector<int> deck) {
    // init players
    for(int i = 0; i < num_players; i++) {
        players.push_back(make_shared<Player>(num_coins));
    }
    this->deck = deck;
}

GameState::GameState(int num_players, int num_coins, int deck_lower, int deck_upper) {
    vector<int> deck;
    for(int i = deck_lower; i < deck_upper; i++) {
        deck.push_back(i);
    }
    // init deck
    random_shuffle(deck.begin(), deck.end());
    // remove float_pct% of the deck
    for(int i = 0; i < (int)(deck.size() - (deck.size() * 0.05)); i++){
        deck.pop_back();
    }
    GameState(num_players, num_coins, deck);
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
