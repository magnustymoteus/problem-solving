#include <list>
#include <math.h>
using namespace std;

/*
The last_digit() function initializes riz, rbt, rmod and j variables and subsequently iterates the list in the reverse order.
The iteration firstly checks if the list element equals to zero. If that's the case then riz, rbt become 0 and rmod becomes 1 again.
Otherwise rmod is calculated in accordance to the conditions in the ternary operator, along with riz and rbt variables.
The reverse iterator ignores the first list element because the parameters for the mod() function are different.
The mod() function returns the remainder of the list element divided by 4 or 10 multiplied by the same remainder to the power of remainder of the remainder of rmod + 3 divided by 4, divided by 4 or 10.
*/


unsigned short int mod(unsigned long a, unsigned int n, unsigned int m) {
    unsigned int c = pow((a%m), (n+3)%4);
    return ((a%m) * c%m);

}
unsigned short int last_digit(list<int> arr) {
    if(!arr.size()) return 1;
    bool riz=0, rbt=0;
    unsigned short int rmod = 1,j=0;
    for (list<int>::reverse_iterator i = arr.rbegin(); i != arr.rend(); i++,j++) {
        if(riz && j!=arr.size()-1) {
            rmod=1, riz=0, rbt=0;
        }
        else if(j!=arr.size()-1) {
            rmod=(rbt && (*i%4==2))?0:mod(*i,rmod,4), riz=!(*i), rbt=!riz && *i!=1;
        }
    }
    return (riz)?1:mod(arr.front(),rmod,10);
}

int main() {
    last_digit({937640,767456,981242}); //returns 0
    return 0;
}
