import sys
sys.setrecursionlimit(300)

def chain(numb):
    if numb == 89:
        return 1
    elif numb == 1:
        return 0
    else:
        nextNumb = 0
        for char in str(numb):
            add = (int(char))**2
            nextNumb += (int(char))**2
        return chain(nextNumb)

out = 0
for i in range (1, 10000000):
    #print("i: ", i)
    out += chain(i)
print (out)
