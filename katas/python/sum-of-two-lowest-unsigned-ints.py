def sum_two_smallest_numbers(numbers):
    list = []
    for num in numbers:
        num = str(num)
        if not(num in numbers):
            num = int(num)
            list.append(num)
    list = sorted(list)
    if list[0] + list[1] >= 0:
        return list[0]+list[1]
