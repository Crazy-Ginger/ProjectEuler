#!/usr/bin/env python3
def getPeriod(n):
    rem = 1
    for i in range (1, n+2):
        rem = (10*rem) % n

    d = rem
    count = 0

    rem = (10*rem)%n
    count += 1
    while rem != d:
        rem = (10*rem )%n
        count += 1
    return count

longestP = 0
longestI = 0
for i in range (1, 1000):
    tmp = getPeriod(i)
    if tmp > longestP:
        longestP = tmp
        longestI = i
print (longestI, ": ", longestP)
