#pragma once
#include <iostream>
#include "structs.hpp"
void blackjack(long double value, Player& gamer) {
    srand(time(0));
    int player = (rand() % 10 + 2) + (rand() % 10 + 2);
    int dealer = (rand() % 10 + 2) + (rand() % 10 + 2);
    char choice;
    while (true) {
        std::cout << "Your score: " << player << std::endl;
        if (player > 21) {
            std::cout << "Overscore. You lose." << std::endl;
            gamer.money -= value;
            return;
        }
        std::cout << "More (y/n): ";
        std::cin >> choice;
        if (choice == 'y') {
            player += rand()%10 + 2; 
        }
        else {
            break; 
        }
    }
    
    std::cout << "Deallers score" << dealer << std::endl;
    while (dealer < 18) {
        dealer += rand() % 10 + 2;
        std::cout << "Dealer makes his hod" << dealer << std::endl;
    } 
    if (dealer > 21) {
        std::cout << "Dealers overscore. You win" << std::endl;
        gamer.money += value;
    }
    else if (player > dealer) {
        std::cout << "You win" << std::endl;
        gamer.money += value;
    }
    else if (player < dealer) {
        std::cout << "You lose." << std::endl;
        gamer.money -= value;
    }
    else {
        std::cout << "Nichya." << std::endl;
    }
    return;
}