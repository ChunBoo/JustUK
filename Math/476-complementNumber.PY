def complementNumber(num):
    mask=~0
    while mask&num:
        mask<<=1
    return ~num^mask


print(complementNumber(5))