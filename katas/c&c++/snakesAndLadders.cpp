using namespace std;
class SnakesLadders
{
  public:
    SnakesLadders(){};
    unsigned short ladders[11][2] = {{2,38}, {7, 14}, {8, 31}, {15,26}, {21, 42}, {28,84}, {36,44}, {51, 67}, {71, 91}, {78, 98}, {87, 94}};
    unsigned short snakes[10][2] = {{16,6},{46,25}, {49,11}, {62,19}, {64,60}, {74,53}, {89,68}, {92,88}, {95,75}, {99,80}}; 
    unsigned short t = 0;
    string posCheck(unsigned short &p) {
      if(p == 100) {
        int tp;
        (t==0) ? tp = 1 : tp = 0;
        string r = "Player ", r2 = " Wins!";
        r+=to_string((tp+1));
        r+=r2;
        over = true;
        return r;
      }
      for(unsigned short i=0;i<sizeof(ladders)/sizeof(ladders[0]);i++) {
        if(p == ladders[i][0]) {
          p = ladders[i][1];
        }
      }
      for(unsigned short i=0;i<sizeof(snakes)/sizeof(snakes[0]);i++) {
        if(p == snakes[i][0]) {
          p = snakes[i][1];
        }
      }
      return "";
    }
    unsigned short p1=0, p2=0;
    bool over = false;
    string play(int die1, int die2)
    {
      if(over == true) {
        return "Game over!";
      }
      if(t==0) {
        if(p1+(die1+die2) > 100) {
          p1 = 100-(p1+(die1+die2)-100);
        }
        else {
        p1+=die1+die2;
        }
      if(die1!=die2) {
          t = 1;
      }
        if(posCheck(p1) != "") {
      return posCheck(p1);
     }
     else {
      string r = "Player 1 is on square ";
       r+=to_string(p1);
       return r;
     }
      }
      else {
          if(p2+(die1+die2) > 100) {
          p2 = 100-(p2+(die1+die2)-100);
        }
        else {
        p2+=die1+die2;
        }
            if(die1!=die2) {
          t = 0;
        }
        if(posCheck(p2) != "") {
      return posCheck(p2);
     }
     else {
      string r = "Player 2 is on square ";
       r+=to_string(p2);
       return r;
     }
      }
    }
};
