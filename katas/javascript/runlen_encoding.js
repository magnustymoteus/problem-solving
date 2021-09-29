var runLengthEncoding = function(str){
  let arr = new Array();
  let subArr = new Array();
  let n=1;
  for(let i=0;i<str.length;i++) {
    if(str[i]!==str[i+1]) {
 subArr = [n, str[i]];
arr.push(subArr);
      n=0;
}
    n++;
}
  return arr;
}
