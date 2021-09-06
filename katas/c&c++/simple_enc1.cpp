#include <iostream>
using namespace std;

string encrypt(string text, int n)
{
    if(text!="" && n>0) {
    string r;
    for(signed int i=1;i<text.size();i+=2) {
        r+=text[i];

    }
    for(signed int i=0;i<text.size();i+=2) {
        r+=text[i];
    }
    if(!(n-1)) return r;
    return encrypt(r,n-1);
    }
    return text;
}

string decrypt(string encryptedText, int n)
{
    if(encryptedText!="" && n>0) {
    unsigned short int p=0;
    string r;
    for(signed int i=0,i1=encryptedText.size()/2,i2=0;i<encryptedText.size();i++) {
        if(!p) {
            r+=encryptedText[i1];
            p=1, i1++;
        }
        else {
            r+=encryptedText[i2];
            p=0, i2++;
        }
    }
    if(!(n-1)) return r;
    return decrypt(r,n-1);
    }
    return encryptedText;
}



int main() {
    cout << encrypt("12345",1) << endl;
    cout << decrypt("12345",1); //example
    return 0;
}
