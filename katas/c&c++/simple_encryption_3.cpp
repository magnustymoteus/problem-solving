using namespace std;
string region = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .";

string itob(int n) {
    string bin;
    signed short n2 = n, cr = 64;
    for(unsigned short i=0;i<=6;i++) {
        if(n2-cr>=0) {
            bin += '1';
            n2-=cr;
        }
        else {
            bin += '0';
        }
        cr/=2;
    }
    bin.erase(bin.begin());
    return bin;
}
int btoi(string bin) {
    unsigned int n = 1, r = 0;
    for(int i = bin.size()-1;i>=0;i--) {
        if(bin[i] == '1') r+=n;
        n*=2;
    }
    return r;
}
unsigned short getRegion(char c) {
    for(unsigned short i=0;i<region.size();i++) {
        if(c==region[i]) {
            return i;
        }
    }
    throw exception();
}
void changeBit(unsigned short i, string &bin) {
    bin[i] = (bin[i] == '0')?'1':'0';
}
void swapBits(unsigned short i, unsigned short i2, string &bin) {
    char temp = bin[i];
    bin[i] = bin[i2], bin[i2] = temp;
}
string encrypt(string text)
{
    if(text != "") {
        string currB, nextB, newText = text, revbin;
        for(unsigned int i=0;i<text.size();i++) {
            currB = itob(getRegion(newText[i]));
            if(newText[i+1] != NULL) {
                nextB = itob(getRegion(newText[i+1]));
                if(currB[4] == '0' && nextB[0] == '1') currB[4] = '1', nextB[0] = '0';
                else if(currB[4] == '1' && nextB[0] == '0') currB[4] = '0', nextB[0] = '1';
                newText[i+1] = region[btoi(nextB)];
            }
            changeBit(1, currB), changeBit(3, currB);
            for(signed short i=0;i<3;i++) {
                swapBits(i, 3+i, currB);
            }
            for(unsigned short i=0;i<6;i+=2) {
                swapBits(i,i+1,currB);
            }
            for(signed short i=currB.size()-1;i>=0;i--) {
                revbin += currB[i];
            }
            currB = revbin, swapBits(0,2,currB), revbin.clear();
            newText[i] = region[btoi(currB)];

        }
        return newText;
    }
    return text;
}

string decrypt(string encryptedText)
{
    if(encryptedText != "") {
            string currB, nextB, newText = encryptedText, revbin;
        for(signed int i=encryptedText.size()-1;i>=0;i--) {
            currB = itob(getRegion(newText[i]));
            swapBits(0,2,currB);
            for(signed short i=currB.size()-1;i>=0;i--) {
                revbin += currB[i];
            }
            currB = revbin, revbin.clear();
            for(unsigned short i=1;i<6;i+=2) {
                swapBits(i,i-1,currB);
            }
            for(signed short i=0;i<3;i++) {
                swapBits(i, 3+i, currB);
            }
            changeBit(3, currB), changeBit(1, currB);
            newText[i] = region[btoi(currB)];

        }
        for(unsigned short i=0;i<encryptedText.size();i++) {
                currB = itob(getRegion(newText[i]));
                if(newText[i+1] != NULL) {
                nextB = itob(getRegion(newText[i+1]));
                if(currB[4] == '0' && nextB[0] == '1') currB[4] = '1', nextB[0] = '0';
                else if(currB[4] == '1' && nextB[0] == '0') currB[4] = '0', nextB[0] = '1';
                newText[i+1] = region[btoi(nextB)];
            }
            newText[i] = region[btoi(currB)];
        }
        return newText;
    }
    return encryptedText;
}
