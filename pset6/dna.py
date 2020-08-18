from csv import reader, DictReader
from sys import argv, exit

# checking for more than 3 arguments
if len(argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# reading the sequence text
with open(argv[2]) as f1:
    dna_source = reader(f1)  # getting reader object
    for row in dna_source:
        dna_list = row

# First string
dna = dna_list[0]

# declaring empty dictionary
sequences = {}

# opening csv file/database
with open(argv[1]) as f2:
    people = reader(f2)
    for row in people:
        dnaSequences = row
        # popping out column names
        dnaSequences.pop(0)
        break

# copy the list in a dictionary where the genes are the keys
for item in dnaSequences:
    sequences[item] = 1

# finding repetion of values in sequence
for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna)):       # here dna is storing a row of samples
        # after having counted a sequence it skips at the end of it to avoid counting again
        while temp > 0:
            temp -= 1
            continue

        # Checking for dna sequence and there is a repetition of it we start counting
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp += 1
                i += l

            # it compares the value to the previous longest sequence
            if temp > tempMax:
                tempMax = temp

    # store the longest sequences in the dictionary using the correspondent key
    sequences[key] += tempMax

# after storing all the values in dictionary, we are checking in the database and printing it
with open(argv[1], newline='') as f2:
    people = DictReader(f2)
    for person in people:
        match = 0
        # compares the sequences to every person and prints the name
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            # printing person name if there is a matcj
            print(person['name'])
            exit()

    print("No match")
