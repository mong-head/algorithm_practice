# 00:00:00 ~ N:59:59 까지 3이 포함되는 모든 시각 개수

# input
## N 
N = int(input())

# output
result = 0

# logic : 완전탐색
## 문자열로 만들어서 3 포함하는지 탐색
for h in range(N+1):
    for m in range(60):
        for s in range(60):
            result += 1 if '3' in str(h)+str(m)+str(s) else 0

print(result)
