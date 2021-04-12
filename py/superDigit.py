def superDigit(n, k):
    number = ''
    for i in range(k):
        number += n
    number = int(number)
    if (number//10==0):
        print(number)
        return
    rem, sum = 0, 0
    while(number):
        rem = number % 10
        sum += rem
        number//=10
    superDigit(str(sum), 0)

superDigit('148', 3)

# x = 9875 * 4 % 9
# print(x if x else 9)