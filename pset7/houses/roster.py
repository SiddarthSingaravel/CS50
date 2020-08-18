# TODO
from cs50 import SQL
from csv import reader
from sys import argv, exit

# If Incorrect number of command-line arguments are provided, it prints an error and exit.
if len(argv) < 2:
    print("usage error, roster.py house")
    exit(1)

# executing db query
db = SQL("sqlite:///students.db")
students = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last", argv[1])

# Printing each student value
for person in students:
    if person['middle'] != None:
        print(f"{person['first']} {person['middle']} {person['last']}, born {person['birth']}")
    else:
        print(f"{person['first']} {person['last']}, born {person['birth']}")