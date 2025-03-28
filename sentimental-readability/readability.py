# TODO
import csv

def count_letters(text):
    letter_count = 0
    for char in text:
        if char.isalpha():
            letter_count += 1
    return letter_count

def count_words(text):
    word_count = 1  # initialize to 1, as the first word is usually not preceded by a space
    for char in text:
        if char.isspace():
            word_count += 1
    return word_count

def count_sentences(text):
    sentence_count = 0
    for i, char in enumerate(text):
        if char in {".", "?", "!"}:
            sentence_count += 1
    return sentence_count

def main():
    text = input("Text: ")
    letter_count = count_letters(text)
    word_count = count_words(text)
    sentence_count = count_sentences(text)

    L = (float(letter_count) / word_count) * 100.0
    S = (float(sentence_count) / word_count) * 100.0
    index = 0.0588 * L - 0.296 * S - 15.8
    grade = int(round(index))

    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

if __name__ == "__main__":
    main()