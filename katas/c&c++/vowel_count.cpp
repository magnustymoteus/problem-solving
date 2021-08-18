#include <string>

using namespace std;

int getCount(const string& inputStr){
  int num_vowels = 0;
  string vowels = "aeiou";
  for(unsigned long i=0;i<=inputStr.length();i++) {
    for(unsigned long j=0;j<=vowels.length()-1;j++) {
        if(inputStr[i] == vowels[j]) {
            num_vowels++;
        }
    }
  }
  return num_vowels;
}
