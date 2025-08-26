#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> names = {"Zoe", "Alex", "Christina", "Bob", "Anna"};
    std::sort(names.begin(), names.end(), 
        [](const std::string& a, const std::string& b){ 
            if(a.size() == b.size()) {
                return a < b; 
            }
            return a.size() < b.size(); 
        });

    for(auto i : names) {
        std::cout << i << " "; 
    }

    return 0;
}
