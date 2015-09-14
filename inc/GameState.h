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
     * Automatically constructs a deck [lower, upper) with 5% of the deck missing
     */
    GameState(int num_players, int num_coins, int deck_lower, int deck_upper);

    const std::vector<int> &getDeck() { return deck; }
    const int showTop() { return deck.back(); }
    void flip() { deck.pop_back(); }

    void takeTurn();

    void runGame();

    const auto getPlayers() { return this->players; }
private:
    std::vector<std::shared_ptr<Player>> players;
    std::vector<int> deck;
};



#endif //CLION_PRACTICE_GAMESTATE_H
