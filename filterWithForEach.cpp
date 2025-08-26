#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::string> names = {"Bob", "Alex", "Christina", "Zoe", "Anna"};

    std::for_each(names.begin(), names.end(), 
            [](std::string name) {
                if(name.size()%2==0){
                    std::cout << name << " ";
                }
            });

    return 0;
}
