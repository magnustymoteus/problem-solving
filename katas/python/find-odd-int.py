def find_it(seq):
    list = []
    seq.sort()
    count = 0 
    for x in seq:
        x = str(x)
    print(seq)
    index = 0
    for num in seq:
        index += 1
        print(num)
        if num in list:
            count += 1
            print(f"count of {num}:{count}")
        else:
            if count != 0 and count % 2 != 0:
                print(f'count of {num}:{count} and is odd')
                print(f'returning {seq[index-2]}')
                return seq[index-2]
            else:
                count = 1
                list.append(num)
                print(f'appended {num}')
    return seq[-1]
