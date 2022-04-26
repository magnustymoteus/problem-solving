import re;
def is_valid_IP(strng):
    if(not strng.count('\n')):
        regex_part = r"(?:(0)|([1-9]{1})|([1-9]{1}\d{1})|(1\d{2})|(2[0-4]\d)|(25[0-5]))\.";
        regex = r"^("+(regex_part*4)[:-2]+")$";
        result = True if(re.match(regex, strng)) else False;
        return result;
    return False;
print(is_valid_IP('12.255.56.1')); #True
print(is_valid_IP('123.045.067.089')); #False
