#include<iostream>
using namespace std;

void traceback(int **k, int p[], int w[], int n, int m)
{
    int x[n] = {0};

    int j=m,i=n;

    while(i>0)
    {
        if(k[i][j] == k[i-1][j])
            x[i-1]=0;
        else
        {
            x[i-1]=1;
            j=j-w[i-1]; //*****
        }
        i=i-1;
    }

    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int n,m;
    cout<<"Enter the number of items : ";
    cin>>n;

    cout<<"Enter the maximum capacity : ";
    cin>>m;
    cout<<endl;

    int p[n],w[n];
    int **k = new int *[n+1];

    for(int i=0;i<m;i++)
        k[i] = new int[m+1];



    cout<<"Enter the profit values : "<<endl;
    for(int i=0;i<n;i++)
    {
            cin>>p[i];
    }
    cout<<endl;

    cout<<"Enter the weight values : "<<endl;
    for(int i=0;i<n;i++)
    {
            cin>>w[i];
    }
    cout<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if (i==0 || j==0)
                k[i][j] = 0;
            else if(w[i-1]>j)
                k[i][j] = k[i-1][j];
            else
                k[i][j] = max(k[i-1][j] , k[i-1][j-w[i-1]] + p[i-1]);

        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<k[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Solution Vector is : ";
    traceback(k,p,w,n,m);

    return 0;



}
