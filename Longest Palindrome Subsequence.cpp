#include <iostream>
#include <vector>
using namespace std;
int main()
{
 string sequence = "ABABA";//ACGTGTCAAAATCG
 int n=sequence.length();

 int table[n][n],max=0,source,destination;

 for(int i=0;i<n;i++)
    {
        //table[i][i]=1;
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                table[i][j]=1;
            }
            else
            {
                table[i][j]=0;
            }

        }
    }

    /*for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<table[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl;*/


 for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            //cout<<"i = "<<i<<" j = "<<j<<endl;
            int k=j-i;
            //cout<<"k = "<<k<<endl;
            if(j-k == 1)
            {
                //cout<<"if"<<endl;
                if(sequence[k]==sequence[j]){
                    table[k][j]=1;
                    max=j-k+1;
                    source=k;
                    destination=j;
                }
            }
            else{
                    //cout<<"else"<<endl;
                if(sequence[k]==sequence[j] && table[k+1][j-1]){
                    table[k][j]=1;
                    max=j-k+1;
                    source=k;
                    destination=j;
                    }
                }
        }
    }
   /*for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<table[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl;*/

// cout<<" 0 1 2 3 4 5 6 7"<<endl;
// cout<<" ---------------"<<endl;
// for(int i=0;i<n;i++){
// cout<<i<<"|";
// for(int j=0;j<n;j++){
// if(j<i){
// cout<<"-"<<" ";
// }else{
// cout<<table[i][j]<<" ";
// }
//
// }
// cout<<endl;
// }
 cout << "Length of the longest palindromic subsequence : " << max <<" from index "<<source <<" to "<<
destination<< endl;
 return 0;
}
