# * Author:
# * Date:
a, b = map(int, input().split())

v = []

v.append(b)
while a < b:
    if b % 2 == 0:
        b //= 2
        v.append(b)
    elif b % 10 == 1:
        b //= 10
        v.append(b)
    else:
        break

if a == b:
    print("YES", end=" ")
    for i in range(len(v) - 1, -1, -1):
        print(v[i], end=" ")
else:
    print("NO")