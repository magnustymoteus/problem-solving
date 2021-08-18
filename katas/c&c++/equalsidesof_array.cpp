#include <vector>
using namespace std;

int find_even_index (const vector <int> numbers) {
  int m = 0, l = 0, r = numbers.size()-1, sl=0, sr=0;
  for(unsigned long i=0;i<=numbers.size()-1;i++) {
    for(int i=0;i<l;i++) {
        sl+=numbers[i];
    }
    for(int i=numbers.size()-1;i>m;i--) {
      sr+=numbers[i];
    }
    if(sl==sr) {
      return m;
    }
    else {
    sl=0, sr=0;
      m++;
      l++;
    }
  }
  return -1;
}
