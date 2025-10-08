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

    std::string names[2];

    std::cout << "Enter the name of first player: ";
    std::getline(std::cin, names[0]);
    std::cout << "Welcome player: " << names[0] << " mark: o\n";
    
    std::cout << "Enter the name of the second player: ";
    std::getline(std::cin, names[1]);
    std::cout << "Welcome player: " << names[1] << " mark: x\n";

    int games_played{};

    do {
        char **grid{makeGrid()};
        
        bool game_over{false};
        bool win{false};
        bool draw{false};
        int turn_count{};
        int cell{};
        bool is_occupied{};

        if (games_played == 0) {
            
            do {
                displayGrid(grid);
                std::cout << "player " << names[turn_count % 2] << "'s turn: \n";
                std::cout << "Select the cell: ";
                std::cin >> cell;
                if (cell < 0 || cell > 9 || is_occupied) {
                    std::cout << "Invalid intput\n";
                } 
                

                win = true;
                if (win || draw) {
                    game_over = true;
                }
            } while (!game_over);
        }

        std::cout << "Want to play again yes= 1, no = 0: ";
        std::cin >> run;
    } while (run);

    return 0;
}
