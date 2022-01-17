# Python

## 입력

```py
# 개별 입력
N, M = map(int, input().split()) # 3, 5
N, M, K = [int(num) for num in input().split(' ')] # 3, 4, 5
# 리스트 입력
array = [list(map(int, input().split())) for num in range(N)] # [[1,2,3],[4,5,6]]
# 하나의 문장을 하나하나의 요소들로 쪼개어야 하는 경우
array = list(input()) # a1 입력시 : ['a','1']
```

## 초기화
```py
visited = [[False]*M for _ in range(N)]
```
* [이중 리스트 초기화 시 복사관련 문제](https://velog.io/@mong-head/mistakepython-%EC%9D%B4%EC%A4%91-%EB%A6%AC%EC%8A%A4%ED%8A%B8-%EC%B4%88%EA%B8%B0%ED%99%94-%EC%8B%9C-%EB%B3%B5%EC%82%AC%EA%B4%80%EB%A0%A8-%EB%AC%B8%EC%A0%9C) : `visited = [[False]*3]*4` 식으로 사용하지 말자
## 최대, 최소
```max(list)```, ```min(list)```
