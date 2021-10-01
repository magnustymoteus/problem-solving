let moveTo_front = (arr, elem) => {
  let newArr = new Array();
  newArr=[elem];
  for(let i=0;i<arr.length;i++) {
    if(arr[i]!==elem) newArr.push(arr[i]);
  }
  return newArr;
}

let encode = (a, s) => {
  let arr = new Array();
  for(let i=0;i<s.length;i++) {
    for(let j=0;j<a.length;j++) {
      if(s[i]===a[j]) {
        arr.push(j);
        a = moveTo_front(a, a[j]);
      }
    }
  }
  return (!arr.length)?null:arr;
}

let decode = (s,a) => {
  let b = (typeof(s)==="object")?true:false;
  let r = (b)?new Array():'';
  for(let i=0;i<a.length;i++) {
    for(let j=0;j<s.length;j++) {
      if(a[i]===j) {
        if(b)r.push(s[j]);
        else r+=s[j];
        s = moveTo_front(s,s[j]);
      }
    }
  }
  return (!r.length)?null:r;
}