#include<iostream>
#include "game_core.h"
#include <unordered_map>

struct Event {
    std::string description;
    long double moneyChange;
    int staminaChange;
    int gradeChange;
};

std::vector<Event> Events = {
    {"You found a wallet on the street. You gain $100.", 100, 0, 0},
    {"You helped an old lady cross the street. You gain $50.", 50, 0, 0},
    {"You found a rare collectible item. You gain $500.", 500, 0, 0},
    {"You got a promotion at work. You gain $1000.", 1000, 0, 0},
    {"You won a small lottery prize. You gain $200.", 200, 0, 0},
    {"You were fined for jaywalking. You lose $50.", -50, 0, 0},
    {"You were caught speeding. You lose $100.", -100, 0, 0},
    {"Your car broke down and needs repairs. You lose $300.", -300, 0, 0},
    {"You lost your wallet. You lose $200.", -200, 0, 0},
    {"You were scammed online. You lose $400.", -400, 0, 0},
    {"You've been promoted at work! Your grade increases by 1.", 0, 0, 1},
    {"You've been promoted at work! Your grade increases by 2.", 0, 0, 2},
    {"You found a health potion. You gain 1 stamina.", 0, 1, 0},
    {"You got sick and lost stamina. You lose 1 stamina.", 0, -1, 0},
};

void getEvents(Player& player){
    int eventIndex = rand() % Events.size();
    Event event = Events[eventIndex];
    player.money += event.moneyChange;
    player.stamina += event.staminaChange;
    if (player.grade+event.gradeChange<3){
        player.grade += event.gradeChange;
    }
    else{
        player.grade = 2;
    }
    std::cout << event.description << std::endl;
}
void levelUp(Player& player){
    if (player.studyMonths == 3){
        player.level += 1;
        player.studyMonths = 0;
        std::cout << "Congratulations! You have leveled up to level " << player.level << "!" << std::endl;
    }
    else{
        std::cout << "You need to study for " << 3 - player.studyMonths << " more months to level up." << std::endl;
    }
}