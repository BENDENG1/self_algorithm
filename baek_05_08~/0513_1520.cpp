#include <iostream>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[501][501] = {0,};
int dp[501][501] = {0,};
int n, m;

int dfs(int y, int x)
{
    if (x == n - 1 && y == m - 1)
        return 1;
    else if (dp[y][x] == -1)
    {
        dp[y][x] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && 0 <= ny && nx < n && ny < m && arr[y][x] > arr[ny][nx])
                dp[y][x] += dfs(ny, nx);
        }
    }
    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0);
}