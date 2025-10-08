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

        bool game_over{false};

        size_t length{random_word.length()};
        std::string guessed_word(length, '_');
        int remaining_attempts{7};
        char guess{};
        bool correct_guess{false};
        
        do
        {
            correct_guess = false;

            std::cout << guessed_word << '\n';
            std::cout << "Remaining Attempts: " << remaining_attempts << '\n';
            std::cout << "Guess your character: ";
            std::cin >> guess;
            for (int i{}; i < length; i++) {
                if (guess == random_word[i]) {
                    guessed_word[i] = guess;
                    correct_guess = true;
                }
            }

            if (!correct_guess) {
                remaining_attempts--;
            }

            std::cout << guessed_word << '\n';

            if (remaining_attempts == 0 ) {
                std::cout << "Attemps = 0. Game Over!!!!!!!!!\n"
                          << "The word was " << random_word << "\n\n";
                game_over = true;
            }
            if (guessed_word == random_word) {
                std::cout << "Congratulations You guessed the word!!\n\n";
            }

        } while (!game_over);

        std::cout << "Want to play again yes= 1, no = 0: ";
        std::cin >> run;

    } while (run);

    file.close();
    return 0;
}
