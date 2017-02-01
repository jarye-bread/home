#Jarye Murphy 1/31/2017
#fizzbuzz in python
for i in range(100):
    i = i+1
    if i%15 == 0: #check for divisiblity of 3 and 5 with modulus of 15 works instead
        print("Fizzbuzz")
    else:
        if i%3 == 0:
            print("Fizz")
        elif i%5 == 0:
            print("Buzz")
        else:
            print(i)
