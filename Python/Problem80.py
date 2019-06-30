#!/usr/bin/env python3
from decimal import *
total = 0
#sets the number of decimal places for floats to 100
getcontext().prec = 103

for i in range(1, 101):
    numb = str(Decimal(i).sqrt())
    temp = 0
    # print("last 2: ", numb[-2:])
    numb = numb[:-3]
    if len(numb) != 1:
        for char in numb:
            if char != '.':
                temp += int(char)
        total += temp
    print(i, "\tadding: ", temp, "\ttotes: ", total)
print("Total: ", total)
