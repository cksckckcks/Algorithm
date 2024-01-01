n = int(input())
list = [[0] * 10 for _ in range(n)]


for i in range(1, 10):
    list[0][i] = 1

for i in range(1, n):
    list[i][0] = list[i - 1][1]
    list[i][9] = list[i - 1][8]
    for j in range(1, 9):
        list[i][j] = list[i - 1][j - 1] + list[i - 1][j + 1]

print(sum(list[n - 1]) % 1000000000)