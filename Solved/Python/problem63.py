#!/usr/bin/env python3

total = 0

for i in range (1, 10000):
    for j in range (1, 50):
        if (j== len(str(i**j))):
            total +=1
            print (i , "^", j, "\t", i**j)

print("total: " , total)
