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
    long double deposit = 0.0;
    long double money = 0.0;
    long double credit = 0.0;
    unsigned int stamina = kstartPlayerStamina;
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
    std::vector<unsigned int> moneyGain;
    unsigned int staminaCost;
    Work(std::string n, unsigned int s, std::vector<unsigned int> mg) : name(n), staminaCost(s), moneyGain(mg) {}
};
// 0 - kBull (Рост), 1 - kBear (Падение), 2 - kFlat (Боковик)
enum {kBull,kBear,kFlat};

struct Asset
{
    long double price;              // Текущая стоимость одной единицы актива (акции/товара)
    long double baseVolatility;     // Базовая волатильность: определяет склонность актива к резким скачкам (рискованность)
    long double minPrice;           // Экономический предохранитель: минимально возможная цена, ниже которой актив не может упасть
    long double eventModifier;      // Модификатор тренда от новости: искусственный плюс или минус к росту цены (например, +0.05)
    std::vector<long double> priceHistory;
    unsigned int count;             // Количество единиц актива (сколько на рынке)
    unsigned int marketState;       // Текущая фаза рынка (0 - BULL/Рост, 1 - BEAR/Падение, 2 - FLAT/Боковик)
    unsigned int eventDuration;     // Счетчик ходов: сколько месяцев ('nm') еще будет активно случайное событие
};


class StockMarket
{
public:
    StockMarket();
    void displayStockPrices();
    void simulateStockPriceChanges();

private:
    std::unordered_map<std::string,Asset> stockPrices;
};

void blackjack(long double value, Player &gamer);
void parseCommand(Player &player, Bank &bank);
void getEvents(Player &player);
void levelUp(Player &player);