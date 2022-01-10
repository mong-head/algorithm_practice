# 거스름돈

## N원을 거슬러 주어야 할 때 최소의 동전 개수 (500,100,50,10원짜리 있음)

N = int(input())

coinType = [500,100,50,10]

coinNum = 0
for type in coinType:
    coinNum += N // type
    N %= type

print(coinNum)

## O(N)