#include <iostream>
#include <vector>
#include <memory>
#include <string>

std::string likes(const std::vector<std::string> &names)
{
    std::string resStr;
    switch(names.size()) {
    case 0:
        resStr = "no one likes this";
        break;
    case 1:
        resStr = names[0] + " likes this";
        break;
    case 2:
        resStr = names[0] + " and " + names[1] + " like this";
        break;
    case 3:
        resStr = names[0] + ", " + names[1] + " and " + names[2] + " like this";
        break;
    default:
        resStr = names[0] + ", " + names[1] + " and " + std::to_string(names.size()-2) + " others like this";
    }
    return resStr;
}
int main() {
    std::vector<std::string> names = {"Paul", "James"}; //example
    std::cout << likes(names);
    return 0;
}
