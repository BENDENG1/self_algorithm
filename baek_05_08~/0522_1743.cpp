/*
int j인데 왜 i라고 써서 헤메고 그리고 왜 좌표 오아왼위인데 x좌표변경을 이상하게 하냐.
*/
#include <iostream>

using namespace std;
int n, m, k, r, c, ans = 0, tmp = 1;
int arr[101][101] = {
    0,
};
int visited[101][101] = {
    0,
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int y, int x);
int get_max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++)
    {
        cin >> r >> c;
        arr[r][c] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 1 && visited[i][j] == 0)
            {
                tmp = 1;
                dfs(i, j);
                ans = get_max(ans, tmp);
            }
        }
    }
    cout << ans;
}

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (1 <= ny && 1 <= nx && ny <= n && nx <= m)
        {
            if (arr[ny][nx] == 1 && visited[ny][nx] == 0)
            {
                dfs(ny, nx);
                tmp++;
            }
        }
    }
}