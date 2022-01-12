# 00:00:00 ~ N:59:59 까지 3이 포함되는 모든 시각 개수

# input
## N 
N = int(input())

# output
result = 0

# logic : 수학관련
## N자리에 3이 포함되는 것 개수 X 3600 + 포함안되는 것 개수 X 1575
## 3600 : 60 * 60
## 1575 : 2 * ( 15 * 45 ) ; 15 : 3 포함

include3set = {3,13,23}
allTimeSet = set(range(N+1))

include3count = len(include3set & allTimeSet)
notInclude3count = len(allTimeSet - include3set)

result = include3count * 3600 + notInclude3count * 1575

print(result)