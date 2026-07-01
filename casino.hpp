#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int player = (rand() % 10 + 2) + (rand() % 10 + 2);
    int dealer = (rand() % 10 + 2) + (rand() % 10 + 2);
    char choice;
    while (true) {
        std::cout << "Your score: " << player << endl;
        if (player > 21) {
            std::cout << "Overscore. You lose." << endl;
            return 0;
        }
        std::cout << "More (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            player += rand()%9 + 2; 
        }
        else {
            break; 
        }
    }
    


    std::cout << "Deallers score" << dealer << endl;
    while (dealer < 18) {
        dealer += rand() % 10 + 2;
        std::cout << "Dealer makes his hod" << dealer << endl;
    } 
    if (dealer > 21) {
        std::cout << "Dealers owerscore. You win" << endl;
    }
    else if (player > dealer) {
        std::cout << "You win" << endl;
    }
    else if (player < dealer) {
        std::cout << "You lose." << endl;
    }
    else {
        std::cout << "Nichya." << endl;
    }
    return 0;
}
