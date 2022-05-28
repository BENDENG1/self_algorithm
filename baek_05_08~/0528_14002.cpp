/*
기존의 11053의 문제 dp를 통해 최대 길이 갱신에 했다면 원소들을 갱신하는 방법을 한다
그런다면 배열에 벡터를 선언해서 갱신을 한다면?
풀이의 약간 막힘이 있어 다른분글을 보고 앞에 미리 push_back(arr[i])를 해야하는것을 깨달았다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int i_max=0;
int n;
int arr[1001],dp[1001];
vector<int> v,ans[1001];


int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    
    cin>>n;
    for(int i = 1;i<=n;i++)
        cin>>arr[i];
    for(int i =1;i<=n;i++)
    {
        dp[i] = 1;
        ans[i].push_back(arr[i]);
        for(int j = 1;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                if(dp[i] < dp[j] +1)
                {
                    dp[i] = dp[j]+1;
                    ans[i].clear();
                    ans[i] = ans[j];
                    ans[i].push_back(arr[i]);
                }
            }
        }
        if(v.size()<ans[i].size())
        {
            v.clear();
            v=ans[i];
        }
    }

    cout<<v.size()<<"\n";
    for(int i =0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}