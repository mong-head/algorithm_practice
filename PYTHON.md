# Python

## 입력

```py
# 개별 입력
N, M = map(int, input().split()) # 3, 5
N, M, K = [int(num) for num in input().split(' ')] # 3, 4, 5
# 리스트 입력
array = [list(map(int, input().split())) for num in range(N)] # [[1,2,3],[4,5,6]]
```

## 최대, 최소
```max(list)```, ```min(list)```