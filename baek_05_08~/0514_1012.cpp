#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int t, m, n, k, x, y;
bool visited[51][51];
int arr[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;
void dfs(int x, int y);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ans = 0;
        memset(visited, 0, sizeof visited);
        memset(arr, 0, sizeof arr);
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            arr[y][x] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    if (!visited[i][j])
                    {
                        ans++;
                        dfs(i, j);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}

void dfs(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && 0 <= ny && nx <= m - 1 && ny <= n - 1)
        {
            if (arr[ny][nx] == 1 && visited[ny][nx] == false)
                dfs(ny, nx);
        }
    }
}