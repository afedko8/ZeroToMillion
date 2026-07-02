#include<iostream>

#include "game_core.h"
    
int main() {
    Player player;
    Bank bank;
    while (true) {
        parseCommand(player, bank);
        if (player.months > 3 && player.credit > 0) {
            std::cout << "You have not repaid your credit in time. Game over." << std::endl;
            break;
        }
        if (player.credit > 1000000.0) {
            std::cout << "You have taken too much credit. Game over." << std::endl;
            break;
        }
        else if (player.money > 1000000.0 && player.credit == 0) {
            std::cout << "Congratulations! You have reached your goal of 1 million. You win!" << std::endl;
            std::cout << player.money;
            break;
        }
    }
    return 0;
}
