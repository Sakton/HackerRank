#include <iostream>
#include <string>
#include <numeric>

int camelcase(std::string s) {
    return std::accumulate(s.cbegin(), s.cend(), 1, [](int acc, char symbol){ return ( std::isupper(symbol)) ? ++acc : acc; });
}

int main()
{
    std::cout << camelcase("saveChangesInTheEditor") << std::endl;
}
