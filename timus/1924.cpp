#include <iostream>

int main() {
    size_t n{0};
    std::cin >> n;
    bool is_black{true};

    switch (n % 4) {
        case 1:
            is_black = false;
            break;
        case 2:
            is_black = false;
            break;
        default:
            break;
    }
    is_black ? std::cout << "black" << std::endl :
    std::cout << "grimy" << std::endl;
    return 0;
}

