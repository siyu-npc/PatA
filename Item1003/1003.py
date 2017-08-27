n,m,begin,end = [int(num) for num in input().split()]
teams = [int(n) for n in input().split()]


Map = []
i = 0
while i < n:
    row = [-1 for i in range(0,n)]
    Map.append(row)
    i += 1

i = 0
while i < m:
    row,col,dis = [int(num) for num in input().split()]
    Map[row][col] = Map[col][row] = dis
    i += 1

inf = 1 << 31
length = [0 if i == begin else (inf) for i in range(n)]
visited = [False if i != begin else True for i in range(n)]

minDis = inf
helpTeams = 0
cnt = 0
length = [0 if i == begin else inf for i in range(n)]

def dfs(start,dst,dis,helper):
    global minDis,cnt,helpTeams,n
    if (dis > minDis) : return
    else :
        if start == dst:
            if (dis < minDis):
                cnt = 1
                minDis = dis
                helpTeams = helper
            elif dis == minDis:
                cnt += 1
                if helpTeams < helper:
                    helpTeams = helper
        else:
            for i in range(n):
                if ((not visited[i]) and (Map[start][i] != -1)):
                    if length[start] + Map[start][i] <= length[i] :
                        length[i] = length[start] + Map[start][i]
                        visited[i] = True
                        dfs(i,dst,length[i],helper + teams[i])
                        visited[i] = False

dfs(begin,end,0,teams[begin])
print(cnt,helpTeams)
