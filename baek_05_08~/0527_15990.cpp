/*
틀렸었다. 반례가 int 형 범위를 넘어갈때에 대해서 처리를 안해줘서 배열 자체를 long long으로 바꿈
근데 94퍼에서 틀렸다.
어처구니 없는 실수를 하네 배열을 123으로 받는데 왜 크기를 3으로 했지 4로해야지..?
*/
#include <iostream>

using namespace std;
int t, n;
long long dp[100001][4];
long long ans;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    dp[1][1]=dp[2][2]=1;
    dp[3][1]=dp[3][2]=dp[3][3]=1;
    for (int i = 4; i <= 100000; i++)
    {
        dp[i][1] = (dp[i-1][2]+dp[i-1][3]) % 1000000009;
        dp[i][2] = (dp[i-2][1]+dp[i-2][3]) % 1000000009;
        dp[i][3] = (dp[i-3][1]+dp[i-3][2]) % 1000000009;
    }

    cin >> t;
    for(int i = 0;i<t;i++)
    {
        cin>>n;
        ans = (dp[n][1]+dp[n][2]+dp[n][3]) %1000000009;
        cout<<ans<<"\n";
    }

}