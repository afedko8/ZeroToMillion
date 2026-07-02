#include<iostream>
#include<unordered_map>
#include "game_core.h"

StockMarket::StockMarket() {
    stockPrices = {
        {"Gold", {2500.0, 0.1, 2000.0, 0.0, {}, 100, 2, 0}},
        {"Silver", {30.0, 0.2, 25.0, 0.0, {}, 1000, 2, 0}},
        {"Copper", {4.5, 0.3, 3.5, 0.0, {}, 5000, 2, 0}},
        {"Iron", {0.15, 0.4, 0.1, 0.0, {}, 10000, 2, 0}},
        {"Lithium", {15.0, 0.5, 10.0, 0.0, {}, 2000, 2, 0}}
    };
}

void StockMarket::simulateStockPriceChanges(){
    
}