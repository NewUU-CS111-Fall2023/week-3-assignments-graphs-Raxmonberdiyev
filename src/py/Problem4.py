# * Author:Raximberdi
# * Date:
n = int(input())
s = ""
for i in range(n):
    t = input()
    s += t

c = sorted(set(s))
print("".join(c))