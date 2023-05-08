#include<iostream>
using namespace std;
int main()
{
    int n; //number of edges
    cout<<"Enter the number of vertices : "<<endl;
    cin>>n;
    int arr[n][n]; //cost matrix of size n*n
    int a = INT_MAX;

    cout<<"\nEnter the cost of edges for the corresponding vertices : "<<endl;
    cout<<"\nEnter 999 if there is no path between the edges!"<<endl;

    for (int i=0;i<n;i++){ //reading the edges of the corresponding graph
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"\nCost Matrix is : "<<endl;

    for (int i=0;i<n;i++){ //displaying the cost matrix
        for(int j=0;j<n;j++){
                if(arr[i][j]==999)
                arr[i][j]=a;

            cout<<arr[i][j]<<"   ";
        }
        cout<<endl;
    }

    for(int k=0;k<n;k++){ //implementing the Floyd-Warshall Algorithm where arr[i][j]=arr[i][k]+arr[k][j]
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j) // as path from a vertex to the same vertex is not necessary (zero otherwise)
                 if((arr[i][j] > (arr[i][k]+arr[k][j])) && (arr[i][k]!=a) && arr[k][j]!=a ) //main logic
                 arr[i][j]=arr[i][k]+arr[k][j];


            }
        }
    }
    cout<<"\nThe Final All Pairs shortest Matrix is : "<<endl;

    for (int i=0;i<n;i++){ //displaying the cost matrix
        for(int j=0;j<n;j++){
                if(arr[i][j]==a)
                cout<<"INF"<<" ";
                else
        cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
