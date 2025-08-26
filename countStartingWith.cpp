#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::string> fruits = {"apple", "banana", "apricot", "cherry"};
    char letterMain='a';
    
    std::for_each(fruits.begin(), fruits.end(), 
            [letterMain](std::string fruit) {
                if(fruit[0] == letterMain){
                    std::cout << fruit << " ";
                }
            });
    return 0;
}
