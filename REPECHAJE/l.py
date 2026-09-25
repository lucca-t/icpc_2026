
n = int(input())
maxmax = 0
names = []
for _ in range(n):
    names.append(input())
names.sort()

for i in range(n-1):
    name1 = names[i]
    name2 = names[i+1]
    temp = 0
    shortlen = min(len(name1), len(name2))
    while (temp < shortlen and name1[temp] == name2[temp]):
        temp += 1
    maxmax = max(maxmax,temp)

print(maxmax)        