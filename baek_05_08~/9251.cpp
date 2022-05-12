#include <iostream>
#include <cstring>

using namespace std;
int dp[1001][1001] ={0, };

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    string str1, str2;
    int str1_len, str2_len;
    cin>>str1;
    cin>>str2;
    str1_len = str1.length();
    str2_len = str2.length();

    for (int i = 1; i <=str1_len;i++)
    {
        for(int j = 1; j <= str2_len;j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j-1]+1;
            else
            {
                dp[i][j] = dp[i-1][j] >= dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]; 
            }
        }
    }
    cout<<dp[str1_len][str2_len]<<"\n";

}