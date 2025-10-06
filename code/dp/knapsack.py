import sys
N,K=map(int,sys.stdin.readline().split())
goods=[[0,0]]
dp=[[0]*(K+1) for i in range(N+1)]
for i in range(N):
    goods.append(list(map(int,sys.stdin.readline().split())))
for i in range(1,N+1):
    for j in range(1,K+1):
        we=goods[i][0]
        vl=goods[i][1]
        if j<we:
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-we]+vl)
            
print(dp[N][K])
