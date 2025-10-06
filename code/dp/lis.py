import sys
N=int(sys.stdin.readline())
c=[0]*(N)
LIS=[c[0]]
for i in range(N):
    if c[i]>LIS[-1]:
        LIS.append(c[i])
    else:
        left,right=0,len(b)-1
        while(left<=right):
            mid=(left+right)//2
            if LIS[mid]<c[i]:
                left=mid+1
            else:
                right=mid-1
        LIS[left]=c[i]
print(len(c))