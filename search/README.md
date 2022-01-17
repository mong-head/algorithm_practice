# search (탐색)

## 자료구조
* 자료구조 : 자료를 표현하고, 관리하고, 처리하기 위한 구조
* search에서 중요한 자료구조: stack, queue
    * 공통 개념
        * pop(데이터 빼고), push(데이터 넣고)
    * stack (별도 lib 필요X)
        ```py
        stack = []

        stack.append(1) # [1]
        stack.append(2) # [1,2]
        stack.pop()     # [1]
        stack.append(3) # [1,3]

        print(stack)       # [1,3]
        print(stack[::-1]) # [3,1]
        ```
        * push : `stack.append(elem)`
        * pop : `stack.pop()`
    * queue(collections의 deque 활용 가능)
        ```py
        from collections import deque
        
        queue = deque()
        queue.append(1)  # [1]
        queue.append(2)  # [1,2]
        queue.popleft()  # [2]
        queue.append(3)  # [2,3]
        
        print(queue)     # [2,3] : 먼저 들어온 순으로 출력
        queue.reverse()
        print(queue)     # [3,2] : 나중에 들어온 순으로 출력
        ```
        * push : `apppend`
        * pop : `popleft` - 먼저 들어온 것을 뺌
        * deque : list 자료형보다 효율적, queue 라이브러리 있지만 그것보다도 효율적

## 재귀 함수
* 재귀 함수 : 자기 자신을 다시 호출하는 함수, 종료조건을 꼭 명시하기
* 내부적으로 스택구조 (연속적으로 호출되는 함수는 스택에 쌓임)
    * 스택으로 구현해야 하는 알고리즘은 그래서 거의 재귀로 구현 ex) DFS
* 사용 장점
    * 코드 간결
* 예시
    * factorial

## search (탐색)
### [brute force(완전 탐색)](./brute_force)
* 비효율적인 시간복잡도
* 탐색해야 하는 전체 데이터 수가 100만개 이하면 사용해볼 법 함

### 탐색 알고리즘 BFS, DFS

* 그래프
    * 요소
        * node : (=vertex;정점) 도시
        * edge : 연결 다리
    * 그래프 탐색?
        * 하나의 노드 시작으로 다수의 노드를 방문하는 것
        * 두 노드가 연결되어있는 경우 : '인접하다(adjacent)'
    * 그래프 표현 방식
        ```text
        []:node
        - : edge

        [0] -7- [1]
        [0] -5- [2]
        ```
        * 인접 행렬(adjacency matrix)
            * 공간 낭비 있지만, 접근 속도 빠름
            ```py
            INF = 999999999 # 무한 수 표현(987654321로도 함)

            graph = [
                [0,7,5],
                [7,0,INF],
                [5,INF,0]
            ]
            ```
        * 인접 리스트(adjacency list)
            * 공간 낭비는 적지만, 행렬보다 접근 속도 느림
            ```py
            # node 3개(0,1,2) 각각에 대해 연결 정보 저장하기 위해 초기화
            graph = [[] for _ in range(3)]

            # node 0 : (연결된 노드, 거리)
            graph[0].append([1,7])
            graph[0].append([2,5])

            # node 1
            graph[1].append([0,7])

            # node 2
            graph[2].append([0,5])
            ```

#### 1. DFS
* 깊이 우선 탐색
* stack 사용
* 방법
    * 스택에 시작 노드 넣고, 해당 노드를 방문처리
    * 스택의 최상단의 노드와 연결된 노드를 스택에 넣고 방문처리
    * 방문하지 않은 인접노드가 없다면 스택에서 내보내고 위의 과정 반복(가장 깊은 위치의 노드 까지)
* 시간복잡도: O(N)
* 구현
    * 구현시, 스택사용하지 않고, 재귀 활용해도 됨 ([5_DFS재귀구현](.\BFS_DFS\ThisIsCoding\5_DFS재귀구현.py))
#### 2. BFS
* 너비 우선 탐색
* Queue 사용
* 방법
    * 탐색 시작 노드를 큐에 넣고, 방문 처리
    * 큐에서 가장 먼저 들어온 노드를 꺼내고, 해당 노드와 연결된 노드를 큐에 차례로 넣고 방문 처리 (이 과정을 반복)
* 시간복잡도: O(N)이지만, DFS 보다는 좋음
* 구현
    * queue로 구현(deque 사용)([5_BFS 큐 구현](.\BFS_DFS\ThisIsCoding\5_BFS큐구현.py))
