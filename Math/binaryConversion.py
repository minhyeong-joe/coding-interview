
def convert(strRep):
    # "constant" flags
    DECIMAL = "0x"
    BINARY = "0b"
    flag = strRep[:2]
    value = strRep[2:]
    if flag == DECIMAL:
        return decToBin(value)
    elif flag == BINARY:
        return binToDec(value)
    else:
        raise ValueError("The argument has invalid flag (use '0x' for decimal, and '0b' for binary)")
    
    
def binToDec(bin):
    dec = 0
    for i in range(len(bin)):
        # iterate each digit from right-end (reverse range)
        fromRightIndex = len(bin) - 1 - i
        if bin[fromRightIndex] != "0" and bin[fromRightIndex] != "1":
            raise ValueError("Binary representation is invalid (Must only contain 0 and 1)")
        dec += 2**i * int(bin[fromRightIndex])
    return "0x" + str(dec)


def decToBin(dec):
    if not dec.isdecimal:
        raise ValueError("Decimal representation is invalid (Must be a positive integer)")
    binStr = ""
    dec = int(dec)
    while dec > 0:
        digit = str(dec % 2)
        binStr = digit + binStr
        dec = dec // 2
    return "0b" + binStr


# Test Driver
decimalRep = "0x17"
binaryRep = "0b10110"

binary = convert(decimalRep)
decimal = convert(binaryRep)

print(binary)
print(decimal)