#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

int calc(std::vector<int> &v, const int &pos, const int &doors) {
    int sum{0};
    for ( int i = 0; i < doors; ++i ) {
        sum += v.at(pos + i);
    }

    return sum;
}

int main() {
    int n{0};
    int doors{3};
    std::map<int, int> m{};
    using pair_type = decltype(m)::value_type;
    std::vector<int> doors_power{};

      std::cin>>n;
      int input{0};
       while (std::cin >> input)
           doors_power.emplace_back(input);

    for ( int i = 0; i < doors_power.size() - (doors - 1); ++i ) {

        m.insert({i + 1, calc(doors_power, i, doors)});
    }

    auto pr = std::max_element
            (
                    std::begin(m), std::end(m),
                    [] (const pair_type & p1, const pair_type & p2) {
                        return p1.second < p2.second;
                    }
            );

        std::cout << pr->second <<" "<< pr->first + std::ceil(doors/2)<<std::endl;

    return 0;
}