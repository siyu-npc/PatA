num = input()
sum = 0
digit = ("zero","one","two","three","four","five","six","seven","eight","nine")
for c in num:
    sum += int(c)
i = 0
if sum < 10:
    print(digit[sum])
else:
    for i in range(len(str(sum)) - 1):
        n = int(str(sum)[i])
        print(digit[n],end=' ')
    print(digit[int(str(sum)[i + 1])])
