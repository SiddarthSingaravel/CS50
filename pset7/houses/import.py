# TODO
from cs50 import SQL
from csv import reader
from sys import argv, exit

# If incorrect number of command-line arguments are provided,prints an error and exit.
if len(argv) < 2:
    print("usage error, import.py characters.csv")
    exit(1)

# opening that file for SQLite
db = SQL("sqlite:///students.db")

# opening characters.csv
with open(argv[1], "r") as rows:

    # Row objects
    reader = reader(rows)

    for row in reader:
        if row[0] == 'name':
            continue
        fullName = row[0].split()

        # inserting the names in database
        if len(fullName) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], None, fullName[1], row[1], row[2])
        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], fullName[1], fullName[2], row[1], row[2])

