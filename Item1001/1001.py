def formatInt(num):
    numStr = str(num)
    if num < 0:
        print('-',end = '')
        numStr = numStr[1:]
    result = ''
    i = len(numStr) - 1
    while (i >= 3):
        result += numStr[i:i - 3:-1]
        result += ','
        i -= 3
    result += numStr[i::-1]
    print(result[::-1])

left,right = [int(num) for num in input().split()]
result = left + right
formatInt(result)
