def descending_order(num):
    print(num)
    digit_l = []
    for x in str(num):
        if(int(x) >= 0):
            digit_l.append(int(x))
    print(digit_l)
    digits = sorted(digit_l, reverse=True)
    print(digits)
    result = ''.join(map(str, digits))
    result = int(result)
    return result
