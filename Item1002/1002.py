poly_1 = [float(v) for v in input().split()[1:]]
poly_2 = [float(v) for v in input().split()[1:]]


items = {}

i = 0
while(i < len(poly_1)):
    items[poly_1[i]] = poly_1[i + 1]
    i += 2
i = 0
while(i < len(poly_2)):
    if poly_2[i] in items.keys():
        items[poly_2[i]] += poly_2[i + 1]
    else:
        items[poly_2[i]] = poly_2[i + 1]
    i += 2

cnt = 0
for v in items.values():
    if v != 0.0:
        cnt += 1
if (cnt == 0):
    print(0)
else:
    print(cnt,end='')
    for item in [(exp,items[exp]) for exp in sorted(items.keys(),reverse = True)]:
        if item[1] != 0.0:
            print('',int(item[0]),round(item[1],1),end='')
    
