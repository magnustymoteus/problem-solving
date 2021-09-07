#include <iostream>
using namespace std;
class Kata
{
private:
public:
     string region = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,:;-?! '()$%&\"";
    int getIndex(char c) {
        for(unsigned short i=0;i<region.size();i++) {
            if(c == region[i]) {
                return i;
            }
        }
      throw exception();
    }
    string encrypt(string text)
    {
        if(text != "") {
            string newText = text;
            for(unsigned int i=1;i<text.size();i+=2) {
                newText[i] = (islower(newText[i])) ? toupper(text[i]) : tolower(text[i]);
            }
            string newText2 = newText;
            for(unsigned int i=1;i<text.size();i++) {
                newText2[i] = (getIndex(newText[i-1])-getIndex(newText[i]) < 0)? region[(getIndex(newText[i-1])-getIndex(newText[i]))+77] : region[(getIndex(newText[i-1])-getIndex(newText[i]))];
            }
            newText2[0] =  region[76-getIndex(newText2[0])];
            return newText2;
        }
        return text;
    }

    string decrypt(string encryptedText)
    {
        if(encryptedText != "") {
            string newText = encryptedText;
             newText[0] = region[76-getIndex(encryptedText[0])];
                for(unsigned int i=1;i<encryptedText.size();i++) {
                        newText[i] = (getIndex(newText[i]) > getIndex(newText[i-1]))? region[getIndex(newText[i-1]) + 77-getIndex(newText[i])] : region[getIndex(newText[i-1]) - getIndex(newText[i])];
                }
                string newText2 = newText;
                for(unsigned int i=1;i<newText.size();i+=2) {
                    newText2[i] = (islower(newText[i])) ? toupper(newText[i]) : tolower(newText[i]);
                }
            return newText2;
        }
        return encryptedText;
    }
};
int main()
 {
     Kata k;
     string enc = k.encrypt("My encrypted message.");
     cout << enc << endl << k.decrypt(enc);
     return 0;
 }
