def filter_list(l):
    new_list = []
    for x in l:
        if(type(x) == int):
            new_list.append(x)
    return new_list
