#include<iostream>
#include<string>

int main() {
    bool run{true};
    
    do {

        std::cout << "Want to play again yes= 1, no = 0";
        std::cin >> run;
    } while (run);

    return 0;
}
