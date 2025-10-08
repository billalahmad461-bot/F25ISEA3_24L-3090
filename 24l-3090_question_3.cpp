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

void cellToRowCol(int &row, int &col, int cell) {
    if (cell < 3) {
        row = 0;
        col = cell;
    } else if (cell < 6) {
        row = 1;
        col = cell % 3;
    } else {
        row = 2;
        col = cell % 3;
    }
}

bool isWin(char **grid) {
    for (int i{}; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][2] != '_') return true;
    }
    
    for (int i{}; i < 3; i++) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[2][i] != '_') return true;
    }

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] != '_') return true;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] != '_') return true;

    return false;
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

    int win_count[2]{};

    do {
        char **grid{makeGrid()};

        bool game_over{false};
        bool win{false};
        bool draw{false};
        int turn_count{};
        int cell{};
        bool **is_occupied = new bool *[3];
        for (int i{}; i < 3; i++) {
            is_occupied[i] = new bool[3];
            for (int j{}; j < 3; j++) {
                is_occupied[i][j] = false;
            }
        }

        do
        {
            displayGrid(grid);
            std::cout << "player " << names[turn_count % 2] << "'s turn: \n";
            std::cout << "Select the cell: ";
            std::cin >> cell;
            int row{};
            int col{};
            cellToRowCol(row, col, cell);
            if (cell < 0 || cell >= 9 || is_occupied[row][col]) {
                std::cout << "Invalid intput\n";
                continue;
            }

            if (names[turn_count % 2] == names[0]) {
                grid[row][col] = 'o';
                is_occupied[row][col] = true;
            } else {
                grid[row][col] = 'x';
                is_occupied[row][col] = true;
            }
            
            
            win = isWin(grid);
            
            if (win) {
                std::cout << "Congratulation player " << names[turn_count % 2] << '\n';
                displayGrid(grid);
                if (names[turn_count % 2] == names[0])
                win_count[0]++;
                else
                win_count[1]++;
                
                std::cout << "Player " << names[0] << ": " << win_count[0] << '\n';
                std::cout << "Player " << names[1] << ": " << win_count[1] << '\n';
            }
            
            turn_count++;
            
            if (win || draw) {
                game_over = true;
            }

        } while (!game_over);

        std::cout << "Want to play again yes= 1, no = 0: ";
        std::cin >> run;

        for (int i{}; i < 3; i++) {
            delete[] is_occupied[i];
        }
        delete[] is_occupied;

        for (int i{}; i < 3; i++) {
            delete[] grid[i];
        }
        delete[] grid;

    } while (run);

    return 0;
}
