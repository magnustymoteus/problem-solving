function LCS(x, y) {
  var z = "";
  console.log("x:"+x+" y:"+y);
    for(let i=0;i<y.length;i++) {
    for(let j=0;j<x.length;j++) {
      if(x[j] == y[i]) {
        z+=y[i];
        y = y.replace(y[i], '');
        console.log(z);
      }
    }
  }
  return z;
}