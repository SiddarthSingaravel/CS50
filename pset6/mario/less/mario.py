from cs50 import get_int
# getting correct user input
while True:
    h = get_int("Height: ")
    if h > 0 and h < 9:
        break

# initalizing i and j to 0
i = 0
j = 0

# running two loops for printing blocks
for i in range(h):
    for j in range(h):
        if i + j < h - 1:
            print(" ", end="")
        else:
            print("#", end="")
    print()