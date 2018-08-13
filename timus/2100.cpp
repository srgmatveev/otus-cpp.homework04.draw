#include <iostream>
#include <vector>
#include <string>
#include <regex>

int main() {
    int n{0};
    std::vector<std::string> names{};

    std::cin>>n;
    std::cin.get();
    std::string input{};
    while(std::getline(std::cin, input)) names.emplace_back(input);
    int count{2};
    int price = 100;

    for(auto& item: names) {

        if(std::regex_search(item, std::regex ("\\+one$"))) count+=2;
        else ++count;
    }

    if(count == 13) ++count;
    std::cout << count*price << std::endl;
    return 0;
}