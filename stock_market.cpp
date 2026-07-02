#include<iostream>
#include<unordered_map>
#include "game_core.h"

void StockMarket::displayStockPrices(){
    std::cout << "Displaying stock prices..." << std::endl;
    for (const auto& stock : stockPrices) {
        std::cout << stock.first << ": " << stock.second << std::endl;
    }
}

StockMarket::StockMarket() {
    stockPrices = {
        {"Gold", 2500.0},
        {"Silver", 30.0},
        {"Copper", 4.5},
        {"Iron", 0.15},
        {"Lithium", 15.0}
    };
}

void StockMarket::simulateStockPriceChanges(){
    for(int i = 0;i<30;i++){
        for (auto& stock : stockPrices) {
            double change = ((rand() % 2001) - 1000) / 100.0; // Random change between -10.00 and +10.00
            stock.second += change;
            if (stock.second < 0) stock.second = 0; // Ensure price doesn't go negative
        }
    }
}