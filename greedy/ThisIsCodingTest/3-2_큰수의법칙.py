# 큰 수의 법칙
 
# 입력 : N,M,K, array
## N : 배열의 크기
## M : 숫자가 더해지는 횟수
## K : 같은 수를 연속해서 더할 수 있는 수
## array : 배열

# 예시
## 5 8 3
## 2 4 5 4 6

# input
N, M, K = [int(num) for num in input().split(' ')]
array = [int(num) for num in input().split(' ')] # N개만큼 입력제한해야 하지만, 안함

# output
result = 0

# logic
array.sort(reverse=True)

result = array[0] * K * (M//K) + array[1] * (M % K)

print(result)



