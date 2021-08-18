using namespace std;
bool chessBoardCellColor(string cell1, string cell2) {
  int a_1 = (int)cell1[0]-64;
  int n_1 = (int)cell1[1];
  int a_2 = (int)cell2[0]-64;
  int n_2 = (int)cell2[1];

  bool black_1, black_2, both_color;
  ( (a_1 % 2 == 0) && (n_1 % 2 == 0) || (a_1 % 2 != 0) && (n_1 % 2 != 0))? black_1 = true : black_1 = false;
  ((a_2 % 2 == 0) && (n_2 % 2 == 0) || (a_2 % 2 != 0) && (n_2 % 2 != 0))? black_2 = true : black_2 = false;
  (black_1 == true && black_2 == true) || (black_1 == false && black_2 == false) ? both_color = true : both_color = false;
  return both_color;
}
