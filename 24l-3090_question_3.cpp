#include<iostream>
#include<string>

char **makeGrid() {
    char **grid = new char *[3];
    for (int i{}; i < 3; i++) {
        grid[i] = new char[3];
        for (int j{}; j < 3; j++) {
            grid[i][j] = '_';
        }
    }

    return grid;
}

void displayGrid(char **grid) {
    for (int i{}; i < 3; i++) {
        for (int j{}; j < 3; j++) {
            std::cout << grid[i][j] << "  ";
        }
        std::cout << "\n\n";
    }
}

int main() {
    bool run{true};
    
    std::cout << "Enter the name of first player: ";
    std::string name1{};
    std::getline(std::cin, name1);

    std::cout << "Enter the name of the second player: ";
    std::string name2{};
    std::getline(std::cin, name2);

    int games_played{};

    do {
        char **grid{makeGrid()};
        displayGrid(grid);

        bool game_over{false};
        bool win{false};
        bool draw{false};

        if (games_played == 0) {
            
            do {


                if (win || draw) {
                    game_over = true;
                }
            } while (!game_over)
        }

        std::cout << "Want to play again yes= 1, no = 0";
        std::cin >> run;
    } while (run);

    return 0;
}
