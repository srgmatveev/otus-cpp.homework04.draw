#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>

bool isOne(long long n) {
    double intPart{0};
    double para = (1 + sqrt(8 * n - 7)) / 2;
    double fractPart = modf(para, &intPart);

    if (fractPart == 0) return true;

    return false;
}

int main() {
    long long value{0};
    long long num, i = 0;
    std::vector<int> vector{};
    std::cin >> num;
    while (std::cin >> value) {
        if (isOne(value))
            vector.emplace_back(1);
        else
            vector.emplace_back(0);
    }

    std::copy(vector.cbegin(), vector.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    return 0;
}
