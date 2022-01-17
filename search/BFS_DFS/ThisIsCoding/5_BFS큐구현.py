# BFS 구현

# queue로 구현(collections의 deque 사용)
from collections import deque

def BFS(graph, visited, startNode):
    queue = deque([startNode])
    
    visited[startNode] = True # 첫 노드 방문 처리
    
    while True:
        if len(queue) <= 0:
            return;
        node = queue.popleft()
        print(node, end=' ')
        for linkedNode in graph[node]:
            if visited[linkedNode] == False:   
                queue.append(linkedNode)
                visited[linkedNode] = True # 방문 처리
    

# 인접리스트
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

visited = [False]*9

BFS(graph, visited, 1) # result : 1 2 3 8 7 4 5 6 