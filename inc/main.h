//
// Created by Steven Holtzen on 9/13/15.
//

#ifndef CLION_PRACTICE_MAIN_H
#define CLION_PRACTICE_MAIN_H
#include<vector>
#include<memory>
#include<algorithm>

using namespace std;

class Player {
private:
    int num_coins;
    /**
     * A sorted list of cards
     */
    vector<int> cards;
public:
    Player(int num_coins) : num_coins(num_coins) {}
    int getNumCoins() {return num_coins; }
    void takeTurn(const GameState* g) {

    }
    /**
     * Calculates the current score of a given hand
     * Sequences count for the lowest value (3 4 5 == 3)
     */
    int calculateScore() {
        if (cards.empty()) {
            return -num_coins;
        }
        return scoreCards(cards) - num_coins;
    }
    /**
     * Returns the score of a vector of cards
     */
    static int scoreCards(vector<int> c) {
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

    /** Modifiers **/
    void setCards(const vector<int> c) {
        cards = c;
    }
    vector<int> const &getCards() {
        return cards;
    }
    void addCard(int c) {
        cards.push_back(c);
        sort(cards.begin(), cards.end());
    }
};

class GameState {
public:
    GameState(int num_players, int num_coins, vector<int> deck) : players(), deck() {
        // init players
        for(int i = 0; i < num_players; i++) {
            players.push_back(make_shared<Player>(num_coins));
        }
        this->deck = deck;
    }
    /**
     * Automatically constructs a deck [lower, upper) with 5% of the deck missing
     */
    GameState(int num_players, int num_coins, int deck_lower, int deck_upper) {
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

    const vector<int> &getDeck() { return deck; }
    const int showTop() { return deck.back(); }
    void flip() { deck.pop_back(); }

    void takeTurn() {
        for(shared_ptr<Player> p : players) {
            p->takeTurn(this);
        }
    }

    void runGame() {
        while(!deck.empty()) {
            takeTurn();
        }
    }

    const auto getPlayers() { return this->players; }
private:
    vector<shared_ptr<Player>> players;
    vector<int> deck;
};


#endif //CLION_PRACTICE_MAIN_H
