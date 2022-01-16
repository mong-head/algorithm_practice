# simulation

# input
## sizeX, sizeY : map_ size 입력받음
## x,y,userDir : 현재 유저가 위치한 자리 및 방향
## map_ : map_ size만큼 바다면 1, 육지면 0 지도 그림
sizeX, sizeY = map(int,input().split())
x,y,userDir = map(int, input().split())
map_ = [list(map(int,input().split())) for l in range(sizeY)]

# 필요한 변수
## 방향 : 북, 동, 남, 서
dir = [[-1,0],[0,1],[1,0],[0,-1]]
## 결과 : 총 방문한 칸 수
result = 1
## 가본 칸은 map_요소를 2로 변경

# logic
## 1. 방향 순서 : 북 -> 서 -> 남 -> 동 -> 북: 0 -> 3 -> 2 -> 1 -> 0
## 2. 안가본 칸이라면 전진! 아니면 방향 계속 돌리기
## 3. 본래 방향과 같다면 전칸으로 이동, 바다면 움직이 멈추기

while True: 
    originDir = userDir
    for i in range(4):
        # 방향 변경
        userDir = userDir -1 if userDir != 0 else 3
        dx,dy = dir[userDir]
        nextX, nextY = x+dx, y+dy
        # 가보지 않은 육지인 경우
        if map_[nextX][nextY] == 0:
            x,y = nextX,nextY
            map_[x][y] = 2 # 가본 곳으로 변경
            result += 1
            break
    # 본래 방향으로 되돌아왔다면
    if originDir == userDir:
        #  뒷 칸이 바다가 아닌 경우 돌아간다
        if map_[nextX][nextY] != 1:
            dx,dy = dir[userDir]
            x, y = x-dx, y-dy
            map_[x][y] = 2 # 가본 곳으로 변경
            result += 1
        # 뒷 칸이 바다라면 움직임 멈춤
        else:
            break

print(result)