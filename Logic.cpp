#pragma once
#include <algorithm>
#include <iostream>
struct  Player
{
    int money=0;
    long double credit=0;
    unsigned int level=1;
    unsigned int months=0;
};

struct Bank
{
    long double annualRate=12.0;
    long double monthlyCoefficient=1.0+annualRate/100.0/12.0;
};

void ClearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

void parseCommand(Player& player, Bank& bank)
{
    std::string command;
    std::cout << "Enter command: ";
    std::cin >> command;
    command.erase(std::remove_if(command.begin(), command.end(), isspace), command.end());
    if (command == "bank"){
        std::string command2;
        std::cout << "Enter command: ";
        std::cin >> command2;
        command2.erase(std::remove_if(command2.begin(), command2.end(), isspace), command2.end());
        if (command2 == "take"){
            std::cout << "Enter amount to take: ";
            int amount;
            std::cin >> amount;
            player.credit += amount;
            player.money += amount;
            std::cout << "You took " << amount << " from the bank." << std::endl;
        }else if (command2 == "repay"){
            std::cout << "Enter amount to repay: ";
            int amount;
            std::cin >> amount;
            player.credit -= amount;
            player.money -= amount;
            std::cout << "You repaid " << amount << " to the bank." << std::endl;
        }else if (command2 == "exit"){
            std::cout << "Exiting bank." << std::endl;
        }else{
            std::cout << "Invalid command." << std::endl;
        }
    } else if (command == "nm"){
        ClearScreen();
        player.months++;
        player.credit *= bank.monthlyCoefficient;
    }
}
