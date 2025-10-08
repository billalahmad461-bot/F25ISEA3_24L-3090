#include<iostream>
#include<string>
#include<cmath>

int roundOff(double count) {
    if (count <= 0) {
        std::cout << "Error Only +ve number are allowed\n"
                  << " Enter the number again\n";
        return -1; // To idnetify that the number is negatvie
    }

    return static_cast<int>(std::round(count)); // Round to the nearest integer and return
}

int main() {
    bool run{true};
    do {
        std::cout << "How manu strings do you want to check: ";
        double count_double{};
        std::cin >> count_double;

        int count_int{roundOff(count_double)};

        std::string *strings = new std::string[count_int];

        delete[] strings; // Memory cleanup

        std::cout << "Want to check again yes= 1/no= 0 :";
        std::cin >> run;
    } while (run);

    return 0;
}
