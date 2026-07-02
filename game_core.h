#pragma once
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

const unsigned int kstartPlayerStamina = 4;
struct Player
{
    // Potential
    // int x=0,y=0;
    unsigned int stamina = kstartPlayerStamina;
    long double deposit = 0.0;
    long double money = 0.0;
    long double credit = 0.0;
    unsigned int level = 1;
    unsigned int grade = 0;
    unsigned int months = 0;
    unsigned int studyMonths = 0;
    bool isStudied = false;
};

struct Bank
{
    long double annualRate = 12.0;
    long double monthlyCoefficient = 1.0 + annualRate / 100.0 / 12.0;
};

struct Work
{
    std::string name;
    unsigned int staminaCost;
    std::vector<unsigned int> moneyGain;
};

struct Asset
{
    std::string name;
    long double price;
    unsigned int quantity;
    std::vector<long double> priceHistory;
};

class StockMarket
{
public:
    StockMarket();
    void displayStockPrices();
    void simulateStockPriceChanges();

private:
    std::unordered_map<std::string, double> stockPrices;
};

void blackjack(long double value, Player &gamer);
void parseCommand(Player &player, Bank &bank);
void getEvents(Player &player);
void levelUp(Player &player);