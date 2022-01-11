
# input
## N : board size (N*N)
## dirList : direction list
N = int(input())
planToGoList = input().split()

# logic
dir = {
    'L' : [0,-1],
    'R' : [0,1],
    'U' : [-1,0],
    'D' : [1,0]
}
current = [1,1]

for go in planToGoList:
    plan= [current[i] + dir[go][i] for i in [0,1]]
    canGo = [plan[i] > 0 and plan[i] < N + 1 for i in [0,1]] in [[True, True]]
    current = plan if canGo else current

print(current[0],' ',current[1])