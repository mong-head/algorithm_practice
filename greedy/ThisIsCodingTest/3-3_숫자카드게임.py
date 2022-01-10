# 숫자 카드 게임
# 난이도 하

# 각 행 중 가장 작은 수를 1개 뽑는다고 가정했을때, 고를 수 있는 수 중 가장 큰 것 선택하기

# input
## N : 행 수
## M : 열 수
## array : N x M
N, M = map(int, input().split())
array = [list(map(int, input().split())) for num in range(N)]

# output
result = 0

# logic
# array 행 중 가장 작은 수 배열
array_column_min = [min(l) for l in array]

result = max(array_column_min)

print(result)