bool is_square(int n)
{
  if(n == 0) {
    return true;
  }
  for(int i=1;i<=n;i++) {
    if(n/i == i && i * i == n) {
      return true;
    }
  }
  return false;
}
