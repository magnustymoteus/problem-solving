#include <stddef.h>

int solve(size_t n, const int array[n]) {
   int sn=0, ts = array[sn];
   for(int i = 0;i<n;i++) {
   if(array[i]==~array[sn]+1) {
   sn++, ts = array[sn], i=-1;
}
     else if(i==n-1 && array[i]!=~array[sn]+1) {
     return ts;
}
}

}
