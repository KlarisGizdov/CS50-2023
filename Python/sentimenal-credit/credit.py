from cs50 import get_int

# Make sure user enters a number

while True:
    card = get_int("Card: ")
    if card > 0:
        break

# Algorithm for card validation


def luhn_checksum(card):

    # Get the cards as a list of numebers with digits_of

    def digits_of(n):
        return [int(d) for d in str(n)]
    digits = digits_of(card)

    # Get a list of even and odd numbers starting from the last digit
    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]

    
    checksum = 0
    checksum += sum(odd_digits)
    for d in even_digits:
        checksum += sum(digits_of(d * 2))
    return checksum % 10


length = 0
visa = card
master = card
amex = card

# Is it a VISA, AMEX or MASTER?
length = len(str(card))

# VISA
while visa >= 10:
    visa = int(visa / 10)

# AMEX
while amex >= 10**13:
    amex = int(amex / 10**13)

# MASTER
while master >= 10**14:
    master = int(master / 10**14)

# Print outcome
if luhn_checksum(card) == 0:
    if visa == 4 and (length == 13 or length == 16):
        print("VISA")
    elif length == 15 and (amex == 34 or amex == 37):
        print("AMEX")
    elif length == 16 and (51 <= master <= 55):
        print("MASTERCARD")
    else:
        print("INVALID")

else:
    print("INVALID")
