function findOutlier(integers){
  for(var i=0,i2=0,o,o2;i<integers.length;i++) {
    if(integers[i]%2===0) {
      o=integers[i];
      i2++;
    }
    else o2=integers[i];
  }
  return (i2>1)?o2:o;
}