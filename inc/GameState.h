//
// Created by Steven Holtzen on 9/13/15.
//

#ifndef CLION_PRACTICE_GAMESTATE_H
#define CLION_PRACTICE_GAMESTATE_H
#include <vector>
#include <memory>

class Player;

class GameState {
public:
    GameState(int num_players, int num_coins, std::vector<int> deck);
    /**
     * Automatically constructs a deck [lower, upper) with 10% of the deck missing
     */
    GameState(int num_players, int num_coins, int deck_lower, int deck_upper);
    const std::vector<int> &getDeck() { return deck; }
    const int showTop();
    const int numCoinsInPool();
    void addCoin() {num_coins_in_pool++;}
    void takeCard();
    void takeTurn();
    void runGame();
    unsigned long numCards() { return deck.size(); }
    const auto getPlayers() { return this->players; }

    /**
     * Default rate for removing cards from a complete deck
     */
    static constexpr double missing_rate = 0.1;
private:
    std::vector<std::shared_ptr<Player>> players;
    std::vector<int> deck;
    int num_coins_in_pool;
};



#endif //CLION_PRACTICE_GAMESTATE_H
