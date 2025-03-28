# TODO
from cs50 import get_int
def main():
    card_number = get_int("Number: ")

    size = 0
    first_figure = 0
    second_figure = 0
    checksum = 0
    remain_figures = card_number

    while remain_figures > 0:
        figure = remain_figures % 10
        remain_figures = remain_figures // 10
        if size > 0:
            second_figure = first_figure
        first_figure = figure
        if size % 2 == 0:
            checksum += figure
        else:
            checksum += (figure * 2 % 10 + figure * 2 // 10)
        size += 1

    if checksum % 10 != 0:
        print("INVALID")
        return

    if size == 15 and first_figure == 3 and (second_figure == 4 or second_figure == 7):
        print("AMEX")
        return

    if size == 16 and first_figure == 5 and (second_figure >= 1 and second_figure <= 5):
        print("MASTERCARD")
        return

    if (size == 13 or size == 16) and first_figure == 4:
        print("VISA")
        return

    print("INVALID")

if __name__ == "__main__":
    main()