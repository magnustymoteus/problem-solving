def diamond(n):
    if(n%2==0 or n<0):
        return None;
    str = "";
    rng = range(1,n+1,2);
    for i in rng:
        str+=' '*(n//2-i//2)+'*'*i+'\n';
    rng = range(n-2,0,-2);
    for i in rng:
        str+=' '*(n//2-i//2)+'*'*i+'\n';
    return str;

num = int(input());
print(diamond(num));
