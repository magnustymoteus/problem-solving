let replace = (str, x, c) => {
  var newStr = new String();
  for(let i=0;i<str.length;i++) {
    if(i===x)newStr+=c;
    else newStr+=str[i];
  }
  return newStr;
}
let check = (str) => {
  for(let i=0;i<str.length;i++) {
    if(str[i] !== '1' && str[i] !== '0') {
      return false;
    }
  }
  return true;
}
let xPlusY = (n) => {
  if(!check(n)) return 0;
  let t=0;
  for(let i=0;i<n.length;i++) {
    if(n[i]==='1') {
      if(i+1<=n.length) {
      n = (n[i+1]==="1")? replace(n,i+1, "0") : replace(n,i+1, "1");
      }
      n = replace(n,i,"0");
      t++;
    }
  }
  return t;
}