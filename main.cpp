#include<iostream>
#include "Logic.cpp"

int main() {
    Player player;
    Bank bank;
    while (true) {
        parseCommand(player, bank);
        if (player.months > 3 and player.credit > 0) {
            std::cout << "You have not repaid your credit in time. Game over." << std::endl;
            break;
        }
        if (player.money > 1000000.0) {
            std::cout << "Congratulations! You have reached your goal of 1 million. You win!" << std::endl;
            break;
        }
        if (player.credit > 1000000.0) {
            std::cout << "You have taken too much credit. Game over." << std::endl;
            break;
        }
    }
    return 0;
}
