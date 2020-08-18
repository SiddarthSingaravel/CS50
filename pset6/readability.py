from cs50 import get_string

# main function


def main():
    txt = get_string("Text: ")
    lc = float(count_chars(txt))
    wc = float(count_words(txt))
    sc = float(count_sentences(txt))

    l = 100 * (lc / wc)
    s = 100 * (sc / wc)

    # calculating using Coleman-Liau formula
    index = int(round(0.0588 * l - 0.296 * s - 15.8))

    # checking of index
    if index >= 16:
        print("Grade 16+\n")
    elif index < 1:
        print("Before Grade 1\n")
    else:
        print(f"Grade {index}\n")

# defining function for letter count


def count_chars(txt):
    result = 0
    for char in txt:
        if char.isalpha():
            result += 1
    return result

# defining function for word count


def count_words(txt):
    result = 0
    for char in txt:
        if char == " ":
            result += 1
    return result+1

# defining function for sentence count


def count_sentences(txt):
    result = 0
    for char in txt:
        if char == "." or char == "!" or char == "?":
            result += 1
    return result


main()