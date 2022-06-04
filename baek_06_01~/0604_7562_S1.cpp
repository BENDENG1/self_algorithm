/*
한변의 길이,시작 좌표,도착 좌표
도착할수있으면 최소칸 출력
그러면 너비탐색으로 가장 먼저 도착한다면 종료를하고 cnt를 출력하면 되지 않을까
dy,dx를 8칸씩 설정하고 원하는 범위내에 들어온다면 진행하는걸로.

cnt로 안하고 그냥 int visited[y][x]로 해서 여기에 방문하지 않았으면 전값에 +1해서 저장
근데 애초에 처음에 좌표를 시작할때 1로 시작하니 마지막에 -1하자
*/
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int t, l, ans;
int s_x, s_y, e_x, e_y;
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int visited[301][301];
int arr[301][301];

void bfs(int a, int b);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> l;
        cin >> s_x >> s_y;
        cin >> e_x >> e_y;
        //배열, 방문여부, cnt는 항상 초기화
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        bfs(s_y, s_x);
        cout << visited[e_y][e_x] - 1 << "\n";
    }
}

void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        if (y == e_y && x == e_x)
        {
            break;
        }
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            if (0 <= y + dy[i] && y + dy[i] < l && 0 <= x + dx[i] && x + dx[i] < l)
            {
                if (visited[y + dy[i]][x + dx[i]] == 0)
                {
                    q.push({y + dy[i], x + dx[i]});
                    visited[y + dy[i]][x + dx[i]] += visited[y][x] + 1;
                }
            }
        }
    }
}