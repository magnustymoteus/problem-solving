function LCS(x, y) {
  var z = "";
    for(let i=0;i<y.length;i++) {
    for(let j=0;j<x.length;j++) {
      if(x[j] == y[i]) {
        z+=y[i];
        y = y.replace(y[i], '');
      }
    }
  }
  return z;
}