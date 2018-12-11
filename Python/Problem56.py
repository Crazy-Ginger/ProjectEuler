biggest = 0
for i in range (1, 100):
    for a in range (1, 100):
        current_int = 0
        current_str = str(i**a)
        for char in current_str:
            current_int += int(char)
        if (current_int > biggest):
            biggest = current_int

    
print(biggest)
