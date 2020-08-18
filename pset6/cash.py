from cs50 import get_float

while True:
    change = get_float("Change Owed: ")
    if change > 0:
        break

# converting change:dollars to cents
value = change * 100
count = 0

# counting of 25 cents
while value >= 25:
    count += 1
    value -= 25

# counting of 10 cents
while value >= 10:
    count += 1
    value -= 10

# counting of 5 cents
while value >= 5:
    count += 1
    value -= 5

# counting of 1 cents
while value >= 1:
    count += 1
    value -= 1

# printing the number of coins
print(count)