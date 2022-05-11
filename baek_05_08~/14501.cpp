#include <iostream>

using namespace std;
int n, max_ans = 0;
int t[16] = {0, };
int p[16] = {0, };
void dfs(int day, int sum);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];
    dfs(0, 0);
    cout<<max_ans<<"\n";
}

void dfs(int day, int sum)
{
    if (day > n)
        return;
    max_ans = max_ans >= sum ? max_ans : sum;
    
    for(int i = day;i<n;i++)
    {
        dfs(i + t[i], sum + p[i]);
    }
}