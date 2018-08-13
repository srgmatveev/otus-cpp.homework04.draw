#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

size_t find_at_box(const std::string &str) {

    std::vector<std::vector<std::string>> boxes = {{"Alice", "Ariel", "Aurora",
                                                           "Phil",  "Peter",  "Olaf",
                                                           "Phoebus", "Ralph", "Robin"
                                                   },
                                                   {"Bambi", "Belle", "Bolt",
                                                           "Mulan", "Mowgli", "Mickey",
                                                           "Silver",  "Simba", "Stitch"
                                                   },
                                                   {"Dumbo", "Genie", "Jiminy",
                                                           "Kuzko", "Kida",   "Kenai",
                                                           "Tarzan",  "Tiana", "Winnie"
                                                   }};
    size_t ii{0};
    for ( auto &i: boxes ) {
        ++ii;
        auto it = std::find(i.cbegin(), i.cend(), str);
        if (it != i.cend()) return ii;
    }

    return 0;
}

int main() {


    std::vector<std::string> input_vector{};

    int n{0};
    std::cin >> n;
    std::string input{};
    std::cin.get();
    while (std::getline(std::cin, input)) input_vector.emplace_back(input);
    int steps{0};
    int prev_box{1};
    int cur_box{1};

    for ( auto &i:input_vector ) {
        prev_box = cur_box;
        cur_box = find_at_box(i);
        if (cur_box) {
            steps += static_cast<int>(std::abs(cur_box - prev_box));
        }
    }

    std::cout << steps << std::endl;
    return 0;
}