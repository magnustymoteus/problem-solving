def is_isogram(string):
    isogram_check = []
    if string == "":
        return True
    else:
        for x in string:
            x = x.lower()
            if x in isogram_check:
                return False
                break
            elif not(x in isogram_check):
                isogram_check.append(x)
                if len(isogram_check) == len(string):
                    return True
                    break
