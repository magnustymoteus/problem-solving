import math
def find_next_square(sq):
    if (math.sqrt(sq) % 1) == 0:
        root = math.sqrt(sq)
        nextroot = root+1
        return nextroot*nextroot
        
    else:
        return -1
