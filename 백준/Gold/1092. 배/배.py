N = int(input())
boat = list(map(int, input().split()))
M = int(input())
box = list(map(int, input().split()))

boat.sort(reverse = True)
box.sort(reverse = True)

cnt = 0

if(boat[0] < box[0]):
    print(-1)
else:
    while(len(box) > 0):
        cnt += 1
        for i in range(N):
            for j in range(len(box)):
                if(boat[i] >= box[j]):
                    del box[j]
                    break

    print(cnt)