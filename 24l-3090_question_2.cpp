#include<iostream>
#include<string>
#include<random>

int random_num() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int random_number{dist(gen)};

    return random_number;
}

int main() {
    bool run{true};
    
    do {
        std::cout << "Welcome to Hangman Game\n";
        

    } while (run);

    return 0;
}
