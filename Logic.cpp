#pragma once
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "casino.hpp"
#include <vector>
#include "structs.hpp"
#include "events.hpp"


std::vector<Work> works ={
    {"Loader", 1, {100, 200, 300}},
    {"Programmer", 2, {500, 1000, 1500}},
    {"Manager", 3, {1000, 2000, 3000}},
    {"CEO", 4, {5000, 10000, 15000}}
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
    std::cout << "Enter command(bank,nm,status,work, casino): ";
    std::cin >> command;
    command.erase(std::remove_if(command.begin(), command.end(), isspace), command.end());
    if (command == "bank"){
        std::string command2;
        std::cout << "Enter bank`s command(take,repay,deposit,exit): ";
        std::cin >> command2;
        command2.erase(std::remove_if(command2.begin(), command2.end(), isspace), command2.end());
        if (command2 == "take"){
            std::cout << "Enter amount to take: ";
            int amount;
            std::cin >> amount;
            player.credit += amount;
            player.money += amount;
            std::cout << "You took " << amount << " from the bank." << std::endl;
            player.stamina -= 1;
        }
        else if (command2 == "deposit") {
            std::cout << "Withdraw or put money? (1/2)  ";
            int command2_1;
            std::cin >> command2_1;
            if (command2_1 == 2) {
                std::cout << "Enter deposit value: ";
                int depositValue;
                std::cin >> depositValue;
                if (depositValue > player.money) { std::cout << "insufficient funds, operation denied" << std::endl; }
                else { player.deposit += depositValue; player.money -= depositValue; player.stamina -= 1; }
            }
            else if (command2_1 == 1) {
                std::cout << "Enter sum to withdraw: ";
                int withsum;
                std::cin >> withsum;
                if (withsum <= player.deposit) {
                    player.deposit -= withsum;
                    player.money += withsum;
                    player.stamina -= 1;
                }
                else { std::cout << "Insufficient funds" << std::endl; }
            }
            else {
            
            }
        }else if (command2 == "repay"){
            std::cout << "Enter amount to repay: ";
            int amount;
            std::cin >> amount;
            player.credit -= amount;
            player.money -= amount;
            std::cout << "You repaid " << amount << " to the bank." << std::endl;
            player.stamina -= 1;
        }else if (command2 == "exit"){
            std::cout << "Exiting bank." << std::endl;
        }else{
            std::cout << "Invalid command." << std::endl;
        }
    } else if (command == "work"){
        if (player.stamina < works[player.level - 1].staminaCost) {
            std::cout << "You do not have enough stamina to work." << std::endl;
        }else{
            std::cout << "You worked as a " << works[player.level - 1].name << " and earned " << works[player.level - 1].moneyGain[player.grade] << "." << std::endl;
            player.stamina -= works[player.level - 1].staminaCost;
            player.money += works[player.level - 1].moneyGain[player.grade];
        }
    }else if (command == "nm"){
        //clearScreen();
        player.months++;
        player.stamina = playerStamina;
        // in future make some events
        getEvents(player);
        player.credit *= (bank.monthlyCoefficient * 1.1);
        player.deposit *= (bank.monthlyCoefficient);
        std::cout << "Month " << player.months << " has passed. Your credit is now " << player.credit << "." << std::endl;
        
    }else if (command == "status"){
        std::cout << "Player status:" << std::endl;
        std::cout << "Money: " << player.money << std::endl;
        std::cout << "Credit: " << player.credit << std::endl;
        std::cout << "Stamina: " << player.stamina << std::endl;
        std::cout << "Level: " << player.level << std::endl;
        std::cout << "Grade: " << player.grade << std::endl;
        std::cout << "Months: " << player.months << std::endl;
        std::cout << "Deposit: " << player.deposit << std::endl;
    }
    else if (command == "casino") {
        long double value;
        std::cout << "Enter value: " << std::endl;
        std::cin >> value;
        if (value > player.money) {
            std::cout << "Insufficient funds to place a bet" << std::endl;
        }
        else {      
            blackjack(value, player);
        }
    }
    
}