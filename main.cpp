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
    }
    return 0;
}
