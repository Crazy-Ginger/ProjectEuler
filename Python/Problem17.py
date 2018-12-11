def unit(single):
    if single == "1":
        return "one"
    elif single == "2":
        return "two"
    elif single == "3":
        return "three"
    elif single == "4":
        return "four"
    elif single == "5":
        return "five"
    elif single == "6":
        return "six"
    elif single == "7":
        return "seven"
    elif single == "8":
        return "eight"
    elif single == "9":
        return "nine"
    elif single == "0":
        return ""

    
def teens(unit):
    if unit == "1":
        return "eleven"
    elif unit == "2":
        return "twelve"
    elif unit == "3":
        return "thirteen"
    elif unit == "4":
        return "fourteen"
    elif unit == "5":
        return "fifteen"
    elif unit == "6":
        return "sixteen"
    elif unit == "7":
        return "seventeen"
    elif unit == "8":
        return "eighteen"
    elif unit == "9":
        return "nineteen"


def tens(ten):
    if ten == "2":
        return "twenty"
    elif ten == "3":
        return "thirty"
    elif ten == "4":
        return "fourty"
    elif ten == "5":
        return "fifty"
    elif ten == "6":
        return "sixty"
    elif ten == "7":
        return "seventy"
    elif ten == "8":
        return "eighty"
    elif ten == "9":
        return "ninety"

size = 0
List = list("one")
List.append("two")
List.append("three")
List.append("four")
List.append("five")
List.append("six")
List.append("seven")
List.append("eight")
List.append("nine")
List.append("ten")
for i in range (11, 1000):
    temp = str(i)
    toadd =""
    if len(temp) == 2:
        char0 = temp[0]
        char1 = temp[1]
        if char0 == "1":
            toadd+= teens(char1)
        else:
            toadd += tens(char0)
            toadd += unit(char1)

    elif len(temp) == 3:
        char0 = temp[0]
        char1 = temp[1]
        char2 = temp[2]
        toadd += unit(char0)+"hundredand"
        if char2 == "1":
            toadd += teens(char2)
        else:
            toadd += tens(char1)
            toadd += unit(char2)
    print(len(List))
List.append("onethousand")

for i in range (0,len(List)-1):
    size += len(List[i])
print (size)



        
