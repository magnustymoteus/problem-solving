let addPrev = (arr) => {
  let str = new String();
  for(let i=0;i<=arr[1]-arr[0];i++) {
    str+=`${arr[0]+i},`;
  }
  return str;
}
let solution = (list) => {
  let str = new String();
  let r, sR, eR, c;
  r = sR = eR = c = 0;
    for(let i=0;i<list.length;i++) {
    eR=(r && list[i+1]-list[i]!=1)?list[i]:eR;
    str+=(r>=2 && list[i+1]-list[i]!=1)?`${sR}-${eR},`:(list[i+1]-list[i]==1)?"":(r && list[i+1]-list[i]!=1)?addPrev([sR, eR]):`${list[i]},`;
    r=(list[i+1]-list[i]==1)?r+1:0;
    sR=(r==1)?list[i]:sR;
  }
  return str.substr(0,str.length-1);
}