# 0,1로 된 그래프가 주어졌을 때, 0끼리 연결되어있으면 한덩어리일때, 0 덩어리가 몇 갠지 구해라

# input
## N,M : 가로,세로
## graph
N,M = map(int,input().split())
graph = [list(map(int,input().split())) for _ in range(N)]

# logic
def DFS(graph,visited,currentLocation,graphList):
    xList, yList = graphList
    x,y = currentLocation
    visited[x][y] = True
    for dir in [[0,1],[1,0],[0,-1],[-1,0]]:
        dx,dy = dir
        nextX,nextY = x+dx,y+dy
        if (nextX not in xList) or (nextY not in yList):
            continue
        if graph[nextX][nextY] == 0 and visited[nextX][nextY] == False:
            DFS(graph,visited,[nextX,nextY],graphList)
    return;
    
xList = list(range(N))
yList = list(range(M))
visited = [[False]*M for _ in range(N)]
result = 0
for x in xList:
    for y in yList:
        if graph[x][y] == 0 and visited[x][y] == False:
            DFS(graph,visited,[x,y],[xList,yList])
            result += 1

# output
print(result)

# ---------------------------------
# input example
## 1
'''
4 5
0 0 1 1 0
0 0 0 1 1
1 1 1 1 1
0 0 0 0 0
'''
## 2
'''
15 14
0 0 0 0 0 1 1 1 1 0 0 0 0 0
1 1 1 1 1 1 0 1 1 1 1 1 1 0
1 1 0 1 1 1 0 1 1 0 1 1 1 0
1 1 0 1 1 1 0 1 1 0 0 0 0 0
1 1 0 1 1 1 1 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1 1 1 0 0
1 1 0 0 0 0 0 0 0 1 1 1 1 1
0 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 1 1 1 1 1
0 1 1 1 1 1 1 1 1 1 1 0 0 0
0 0 0 1 1 1 1 1 1 1 1 0 0 0 
0 0 0 0 0 0 0 1 1 1 1 0 0 0 
1 1 1 1 1 1 1 1 1 1 0 0 1 1 
1 1 1 0 0 0 1 1 1 1 1 1 1 1
1 1 1 0 0 0 1 1 1 1 1 1 1 1
'''