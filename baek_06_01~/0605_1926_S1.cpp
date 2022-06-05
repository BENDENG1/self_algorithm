/*
dfs로 해서 가장 큰값 구하고 그리고 한번 dfs진입할때마다 cnt++해서 카운팅해주면 끝
*/
#include <iostream>

using namespace std;
int n, m; // n : 세로 크기 m : 가로크기
int arr[501][501];
int visited[501][501]={0,};
int cnt = 0, max_a = 0,ans=0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int y, int x);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(visited[i][j]==0 &&arr[i][j]==1)
            {
                max_a = 0;
                dfs(i, j);
                if (max_a>ans)
                    ans = max_a;
                cnt++;
            }
        }
    }
    cout << cnt << "\n" << ans;
}

void dfs(int y, int x)
{
    max_a++;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < n && 0 <= nx && nx < m)
        {
            if (visited[ny][nx] == 0 && arr[ny][nx] == 1)
            {
                dfs(ny,nx);
            }
        }
    }
}