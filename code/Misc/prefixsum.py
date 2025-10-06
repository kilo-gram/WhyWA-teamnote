import sys
N=int(sys.stdin.readline())
a=[0] + list(map(int,sys.stdin.readline().split()))
for i in range(2,N+1):
    a[i]+=a[i-1]