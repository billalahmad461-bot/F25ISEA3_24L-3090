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

void swap(char &a, char &b) {
    char temp{a};
    a = b;
    b = temp;
}

std::string reverseString(std::string str) {
    for (int i{}; i < str.length() / 2; i++) {
        swap(str[i], str[str.length() - 1 - i]);
    }

    return str;
}

bool isPalindrome(std::string str) {
    std::string reverse{reverseString(str)};

    return str == reverse;
}

int main() {
    bool run{true};
    do {
        std::cout << "How many strings do you want to check: ";
        double count_double{};
        std::cin >> count_double;
        std::cin.ignore();

        int count_int{roundOff(count_double)}; // To handle invalid inputs

        std::string *strings = new std::string[count_int];

        for (int i{}; i < count_int; i++) {
            std::cout << "Enter the string " << i + 1 << " to check: ";
            std::getline(std::cin, strings[i]);
            bool is_p{isPalindrome(strings[i])};
            if (is_p) {
                std::cout << "Palindrome\n";
            } else {
                std::cout << "Not Palindrome\n";
            }
        }
        
        delete[] strings; // Memory cleanup

        std::cout << "Want to check again yes= 1/no= 0 :";
        std::cin >> run;
    } while (run);

    return 0;
}
