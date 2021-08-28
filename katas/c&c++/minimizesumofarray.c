int minSum(int passed[], int passed_size) {
  int m, mj, ntr, ntr2, result = 0;
  for(unsigned int i=0;i<passed_size;i++) {
    m = passed[i], mj = i;
    for(unsigned int j=i;j<passed_size;j++) {
      if(passed[j]>m) {
        m = passed[j];
        mj = j;
      }
    }
    ntr = passed[mj], ntr2 = passed[i], passed[i] = ntr, passed[mj] = ntr2;
  }

  for(unsigned int i=0, j=passed_size-1;i<passed_size/2;i++, j--) {
    result+=(passed[i]*passed[j]);
  }
  return result;
}
