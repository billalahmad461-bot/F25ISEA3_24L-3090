#include<iostream>
#include<string>

int main() {
    bool run{true};
    do {
        std::cout << "Enter the string to check: ";
        std::string str;
        std::getline(std::cin, str);

        std::cout << "Want to check again yes= 1/no= 0 :";
        std::cin >> run;
    } while (run);

    return 0;
}
