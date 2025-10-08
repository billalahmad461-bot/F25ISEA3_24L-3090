#include<iostream>
#include<string>

int main() {
    bool run{true};
    
    do {
        std::cout << "Enter the name of first player: ";
        std::string name1{};
        std::getline(std::cin, name1);

        std::cout << "Enter the name of the second player: ";
        std::string name2{};
        std::getline(std::cin, name2);

        std::cout << "Want to play again yes= 1, no = 0";
        std::cin >> run;
    } while (run);

    return 0;
}
