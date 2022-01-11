# 1이 될 때까지

# 2가지 스탭이 있을 때, 가장 적은 스탭 수로 N(입력수)을 1로 만들기
# 1. 1 빼기 (항상 가능)
# 2. K로 나누기 (K로 나누어질 수 있을 때만 가능)
import time

# 입력
## N : 1로 만들어야 하는 수
## K : 나눌 수
N, K = map(int, input().split())

start_time = time.time() # 측정 시작
# 출력
result = 0

# logic 1 : 복잡도 쪼금 높은 편
# while N != 1:
#     N = N//K if (N/K)%1 == 0 else N-1
#     result += 1
 
# logic 2 : 1씩 빼는거를 반복문 돌리지 말자
while N>=K:
    result += N - (N//K)*K + 1
    N //= K
result += N-1

print(result)

end_time = time.time() # 측정 종료
print("time:", end_time - start_time) # 수행 시간 출력