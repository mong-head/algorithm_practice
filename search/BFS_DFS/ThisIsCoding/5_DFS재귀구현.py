# DFS 구현: 재귀로 구현

def DFS(graph, visited, currentNode):
    # 방문한 노드라면 돌아가기
    if visited[currentNode] == True:
        return;
    
    # 노드 방문 처리
    visited[currentNode] = True
    print(currentNode, end=' ')
    
    # 연결된 노드 탐색
    for node in graph[currentNode]:
        DFS(graph, visited, node) 
    
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

# 방문
visited = [False]*9

DFS(graph, visited, 1) # result : 1 2 7 6 8 3 4 5 