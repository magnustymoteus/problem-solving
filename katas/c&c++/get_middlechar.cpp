#include <string.h>
using namespace std;
string get_middle(string input)
{
    if(input.length()%2 != 0) {
        string str = input.substr((input.length()-1)/2, 1);
        return str;
    }
    else {
        string str = input.substr((input.length()/2)-1, 2);
        return str;
    }
}
