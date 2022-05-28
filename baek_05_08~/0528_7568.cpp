/*
arr[a][0] ->키
arr[a][0] ->몸무게
*/
#include <iostream>
#include <cstring>

using namespace std;
int arr[51][2];
int ans[51];
int n,x,y;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        ans[i]=1;
    }
    for(int i =1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
               if(arr[i][0]<arr[j][0] && arr[i][1]<arr[j][1])
               {
                   ans[i]++;
               } 
            }
        }
    }

    for(int i =1;i<=n;i++)
        cout<<ans[i]<<" ";
}