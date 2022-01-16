from itertools import permutations, product

# input
currentLocation = tuple( int(i) if i.isdigit() else ord(i) - 96 for i in list(input()) )

# logic
## 이동할 수 있는 경우의 수 : 2C1 * 4 = 8

# 중복 순열 : product
directions = list(product(*[[-1,1]]*2)) # * : unpacking , *[[-1,1]]*2 : [-1, 1] [-1, 1]

# 순열 : permutations
goTos = list(permutations([1,2]))

# 갈 수 있는 방향
canGos = []
for dir in directions:
    for goTo in goTos:
        canGos.append(tuple(d*g for d,g in zip(dir, goTo)))

# 갈 위치
result = 0
canGoLocation = [1,2,3,4,5,6,7,8]
for canGo in canGos:
    x,y = tuple(sum(elem) for elem in zip(canGo, currentLocation))
    if x in canGoLocation and y in canGoLocation:
        result += 1
    
print(result)