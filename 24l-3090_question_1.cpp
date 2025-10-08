#include<iostream>
#include<string>

int main() {
    bool run{true};
    do {
        std::cout << "How manu strings do you want to check: ";
        std::string str_count{};
        std::getline(std::cin, str_count);

        std::cout << "Want to check again yes= 1/no= 0 :";
        std::cin >> run;
    } while (run);

    return 0;
}
