def disemvowel(string):
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    for x in string:
        if x in vowels:
            string = string.replace(x, "")
    return string
