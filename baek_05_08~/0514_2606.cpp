#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
bool visited[101] = {false};
vector<int> v[101];

void dfs(int start)
{
    visited[start] = true;
    for (int i = 0; i < v[start].size(); i++)
    {
        int num = v[start][i];
        if (visited[num] == false)
        {
            dfs(num);
            ans++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int c, n, tmp1, tmp2;
    cin >> c >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    dfs(1);
    cout << ans;
}