#include<iostream>
#include<string>

int roundOff(double count) {
    if (count <= 0) {
        std::cout << "Error Only +ve number are allowed\n"
                  << " Enter the number again\n";
        return -1; // To idnetify that the number is negatvie
    } 
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
