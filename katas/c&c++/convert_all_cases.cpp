using namespace std;

bool check(bool l[]) {
    unsigned short int c=0;
    for(unsigned short int i=0;i<3;i++) {
        if(l[i] == true) {
            c++;
        }
    }
    if(c>1) {
        return false;
    }
    return true;
}

string changeCase(const string &identifier, const string &targetCase)
{
    string ncIdentifier = identifier;
    bool l[3] = {false, false, false};
    if(targetCase == "snake") {
        unsigned int n;
        for(unsigned int i=0;i<ncIdentifier.size();i++) {
            if(ncIdentifier[i] =='_') {
                l[1] = true;
            }
            else if(ncIdentifier[i] == '-') {
                l[2] = true;
                ncIdentifier[i] = '_';
            }
        }
        for(unsigned int i=0;i<ncIdentifier.size();i++) {
            if((int) ncIdentifier[i] >= 65 && (int) ncIdentifier[i] <= 90 ) {
                l[0] = true;
                n = i;
                ncIdentifier += ncIdentifier[ncIdentifier.size()-1];
                for(unsigned int j=ncIdentifier.size()-1;j!=n;j--) {
                    ncIdentifier[j] = ncIdentifier[j-1];
                }
                ncIdentifier[n] = '_';
                ncIdentifier[n+1] = (char) (97 +(int)ncIdentifier[n+1]-65);
           }
        }
    }
    else if(targetCase == "camel") {
        unsigned int n;
        string ncIdentifier_cp;
        for(unsigned int i=0;i<ncIdentifier.size();i++) {
            if(ncIdentifier[i] == '-' || ncIdentifier[i] == '_') {
                l[0] = true;
                n = i;
                ncIdentifier_cp = ncIdentifier;
                for(unsigned int j=ncIdentifier.size()-1;j!=n;j--) {
                    ncIdentifier[j-1] = ncIdentifier_cp[j];
                }
                ncIdentifier.pop_back();
                ncIdentifier[n] = (char) (65 +(int)ncIdentifier[n]-97);
            }
        }
    }
    else if(targetCase == "kebab") {
        unsigned int n;
                for(unsigned int i=0;i<ncIdentifier.size();i++) {
            if(ncIdentifier[i] =='_') {
                l[1] = true;
                ncIdentifier[i] = '-';
            }
            else if(ncIdentifier[i] == '-') {
                l[2] = true;
            }
        }
        for(unsigned int i=0;i<ncIdentifier.size();i++) {
            if((int) ncIdentifier[i] >= 65 && (int) ncIdentifier[i] <= 90 ) {
                l[0] = true;
                n = i;
                ncIdentifier += ncIdentifier[ncIdentifier.size()-1];
                for(unsigned int j=ncIdentifier.size()-1;j!=n;j--) {
                    ncIdentifier[j] = ncIdentifier[j-1];
                }
                ncIdentifier[n] = '-';
                ncIdentifier[n+1] = (char) (97 +(int)ncIdentifier[n+1]-65);
           }
        }
    }
    else {
        return "";
    }
    if(check(l) == false || identifier == "") {
        return "";
    }
    return ncIdentifier;
}
