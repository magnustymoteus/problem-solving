#include <math.h>
bool narcissistic(unsigned int value){
  unsigned int v1=0,c=0;
  for(unsigned int v2=value;v2;v2/=10,c++);
  for(unsigned int v2=value;v2;v1+=pow(v2%10,c),v2/=10);
  return (v1==value)?1:0;
}

int main() {
    narcissistic(321); //returns 0
    return 0;
}

