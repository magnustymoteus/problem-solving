using namespace std;

bool checkSet(unsigned int nums[9]) {
    unsigned int numSet[9] = {1,2,3,4,5,6,7,8,9};
    unsigned short z = 0;
    for(unsigned int i=0;i<9;i++) {
        if(!nums[i]) {
            z++;
        }
        for(unsigned int j=0;j<9;j++) {
            if(nums[i] == numSet[j]) {
                numSet[j] = 0;
            }
        }
    }
    for(unsigned int i=0;i<9;i++) {
        if(numSet[i] != 0 && !z) {
            return false;
        }
        else if(numSet[i] != 0 && z) {
            z--;
        }
    }
    return true;
}

bool validSolution(unsigned int board[9][9]) {
    unsigned int numSet[9];
    unsigned short startX = 0, startY = 0, x = 0, y=0, c=0, c2=1;
    for(unsigned short i=0;i<9;i++) {
        for(unsigned short j=0;j<9;j++) {
           numSet[j] = board[i][j];
        }
        if(!checkSet(numSet)) {
            return false;
        }
    }
    for(unsigned short i=0;i<9;i++) {
        for(unsigned short j=0;j<9;j++) {
            numSet[j] = board[j][i];
        }
        if(!checkSet(numSet)) {
            return false;
        }
    }
   while(c2!=82) {
    numSet[c] = board[y][x];
    if(c == 8) {
        if(!checkSet(numSet)) {
            return false;
        }
        c = -1;
    }
    if(x==startX+2) {
        if(y==startY+2) {
            startY+=3;
            if(startY == 9) {
                startX+=3, startY=0, y=-1;
            }
        }
        x=startX-1,y++;
    }
    x++, c++, c2++;
   }
   return true;
}

int main() {
    unsigned int example1[9][9] =
                            {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                             {6, 7, 2,  1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}};

unsigned int example2[9][9] =
                             {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                              {6, 7, 2, 1, 9, 0, 3, 4, 8},
                              {1, 0, 0, 3, 4, 2, 5, 6, 0},
                              {8, 5, 9, 7, 6, 1, 0, 2, 0},
                              {4, 2, 6, 8, 5, 3, 7, 9, 1},
                              {7, 1, 3, 9, 2, 4, 8, 5, 6},
                              {9, 0, 1, 5, 3, 7, 2, 1, 4},
                              {2, 8, 7, 4, 1, 9, 6, 3, 5},
                              {3, 0, 0, 4, 8, 1, 1, 7, 9}};

    bool validE1 = validSolution(example1); //returns true because sudoku is valid
    bool validE2 = validSolution(example2); //returns false because sudoku is invalid
    return 0;
}
