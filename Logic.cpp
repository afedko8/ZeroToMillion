#pragma once
#include <algorithm>
#include <iostream>
#include <cstdlib>


struct  Player
{
    //Potential
    //int x=0,y=0;
    long double money=0.0;
    long double credit=0.0;
    unsigned int level=1;
    unsigned int months=0;
};

struct Bank
{
    long double annualRate=12.0;
    long double monthlyCoefficient=1.0+annualRate/100.0/12.0;
};

void clearScreen()
{
#if defined(_WIN32) || defined(_WIN64)
    std::system("cls");
#else
    std::system("clear");
#endif
}

void parseCommand(Player& player, Bank& bank)
{
    std::string command;
    std::cout << "Enter command(bank,nm): ";
    std::cin >> command;
    command.erase(std::remove_if(command.begin(), command.end(), isspace), command.end());
    if (command == "bank"){
        std::string command2;
        std::cout << "Enter bank`s command(take,repay,exit): ";
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
        //clearScreen();
        player.months++;
        player.credit *= bank.monthlyCoefficient;
        std::cout << "Month " << player.months << " has passed. Your credit is now " << player.credit << "." << std::endl;
    }
}
