def diamond(n):
    if(n%2==0 or n<0):
        return None;
    str = "";
    for i in range(1,n+1,2):
        str+=' '*(n//2-i//2)+'*'*i+'\n';
    for i in range(n-2,0,-2):
        str+=' '*(n//2-i//2)+'*'*i+'\n';
    return str;

num = int(input());
print(diamond(num));
