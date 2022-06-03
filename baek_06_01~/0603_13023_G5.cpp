/*
dfs
그때그때 한점을 갈때 초기화를 해주면서 cnt를 카운트한다 근데 만약에 ans = 1이라면
그것은 5개의 깊이를 충족하는거므로 이탈하면서 출력
*/
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, m, a, b, ans = 0;
vector<int> arr[2001];
int visited[2001];

void dfs(int spot, int cnt);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i, 1);
        if (ans == 1)
        {
            cout << 1;
            break;
        }
    }
    if (ans == 0)
        cout << 0;
}

void dfs(int spot, int cnt)
{
    if (cnt > 4)
    {
        ans = 1;
        return;
    }
    visited[spot] = 1;
    for (int i = 0; i < arr[spot].size(); i++)
    {
        int tmp = arr[spot][i];
        if (visited[tmp] == 1)
            continue;
        dfs(tmp, cnt + 1);
        if (ans == 1)
            return;
    }
    visited[spot] = 0;
}