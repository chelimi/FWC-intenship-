number = float(input("Enter a number: "))
a = int(number)
b = number - a  
binary_whole_part = ""
while a > 0:
    c = a % 2
    a = a // 2
    binary_whole_part = str(c) + binary_whole_part
binary_fractional_part = ""
while b > 0:
    if len(binary_fractional_part) > 15:
        break
    b *= 2
    bit = int(b)
    binary_fractional_part += str(bit)
    b -= bit
print("Binary representation:", binary_whole_part + "." + binary_fractional_part)
