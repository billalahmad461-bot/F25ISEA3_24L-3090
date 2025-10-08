#include<iostream>
#include<string>
#include<random>
#include<fstream>

int random_num() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int random_number{dist(gen)};

    return random_number;
}

int main() {
    std::ifstream file("100_words_list.txt");
    if (!file) {
        std::cerr << "Unable to open file\n";
        return 1;
    }


    bool run{true};
    
    do {
        std::cout << "Welcome to Hangman Game\n";

        int random_number{random_num()};

        std::string line;
        int current_line{};
        std::string random_word;

        file.clear();
        file.seekg(0, std::ios::beg);

        while (std::getline(file, line)) {
            current_line++;
            if (current_line == random_number) {
                random_word = line;
                break;
            }
        }

        std::cout << "Want to play again yes= 1, no = 0: ";
        std::cin >> run;

    } while (run);

    file.close();
    return 0;
}
