n=4
p=[0,3,3,1,1]
q=[2,3,1,1,1]
c=[[0 for i in range(n+1)] for j in range(n+1)] # cost array
w=[[0 for i in range(n+1)] for j in range(n+1)] # weight array
r=[[0 for i in range(n+1)] for j in range(n+1)] # root array
for i in range(n):
    #Initialization of w,c,and r
    w[i][i]=q[i]
    r[i][i]=0
    c[i][i]=0
    #consider one tree nodes
    w[i][i+1]=q[i]+p[i+1]+q[i+1]
    r[i][i+1]=i+1
    c[i][i+1]=q[i]+p[i+1]+q[i+1]
#consider the trees of size 2,3,4,... n nodes
for  m in range(2,n+1):
    for i in range(0,n-m+1):
        j=i+m
        w[i][j]=p[j]+q[j]+w[i][j-1]
        minimum=9999
        for l in range(i+1,j+1):
            if((c[i][l-1]+c[l][j])<minimum):
                minimum=c[i][l-1]+c[l][j]
                k=l
        c[i][j]=w[i][j]+c[i][k-1]+c[k][j]
        r[i][j]=k
#print c[0,n],w[0,n],r[0,n]
for i in range(n+1):
    for j in range(n-i+1):
        k=j+i
        print('w[%d][%d] = %2d'%(j,k,w[j][k]),end=' | ')
    print()
    for j in range(n-i+1):
        k=j+i
        print('c[%d][%d] = %2d'%(j,k,c[j][k]),end=' | ')
    print()
    for j in range(n-i+1):
        k=j+i
        print('r[%d][%d] = %2d'%(j,k,r[j][k]),end=' | ')
    print()
    print((n-i+1)*"---------------")
