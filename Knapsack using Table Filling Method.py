#knapsack table-fill method
def traceback(k,p,w,n,m):
    x=[0 for i in range(n)]
    j=m
    i=n
    while i>0:
        if(k[i][j]==k[i-1][j]):
            x[i-1]=0       
        else:
            x[i-1]=1
            j=j-w[i]
        i=i-1
    return x

n=3 # number of objects
m=6 # knapsack capacity
p=[0,11,15,12]
w=[0,2,3,4]
k=[[0 for i in range(m+1)] for i in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        if w[i]>j:
            k[i][j]=k[i-1][j]
        else:
            k[i][j]=max(k[i-1][j],k[i-1][j-w[i]]+p[i])

for i in k:
    print(i)
print("solution vector x is ",traceback(k,p,w,n,m))
