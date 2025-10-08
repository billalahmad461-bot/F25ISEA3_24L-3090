#include<iostream>
#include<string>

int strToIntRoundOff(double count) {
    
}

int main() {
    bool run{true};
    do {
        std::cout << "How manu strings do you want to check: ";
        double count_double{};
        std::cin >> count_double;

        std::cout << "Want to check again yes= 1/no= 0 :";
        std::cin >> run;
    } while (run);

    return 0;
}
