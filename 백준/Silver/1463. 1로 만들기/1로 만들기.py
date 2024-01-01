n = int(input())
list = [0] * (n + 1)

for i in range(2, n + 1):
    list[i] = list[i - 1] + 1
    if i % 3 == 0:
        list[i] = min(list[i], list[i // 3] + 1)	
    if i % 2 == 0:
        list[i] = min(list[i], list[i // 2] + 1)

print(list[n])