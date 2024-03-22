/*
벽 부수고 이동하기

벽을 한개까지 부수고 이동하는게 허용

bfs로 푸는데 벽 부수는걸 사용했는지 안했는지에 대해서 true, false사용

*/
#include <iostream>
#include <queue>

using namespace std;

struct board{
    int y;
    int x;
    int cnt;
    bool isBreak;
};

int arr[1001][1001] = {1,};
bool visitied[1001][1001][2] = {false,};
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    int n, m;
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    queue<board> q;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            arr[i][j] = s[j - 1] - '0';
        }
    }

    visitied[0][0][0] = true;
    q.push({1,1,1,false});

    while(!q.empty()){
        board b = q.front();
        q.pop();

        if(b.y == n && b.x == m){
            cout << b.cnt;
            return 0;
        }

        for(int i = 0 ; i < 4; i ++){
            int ny = b.y + dy[i];
            int nx = b.x + dx[i];

            if(ny < 1 || ny > n || nx < 1 || nx > m)
                continue;

            if(arr[ny][nx] == 1 && b.isBreak == false){
                visitied[ny][nx][!b.isBreak] = true;
                q.push({ny,nx,b.cnt + 1, true});
            }
            else if(arr[ny][nx] == 0 && visitied[ny][nx][b.isBreak] == false){
                visitied[ny][nx][b.isBreak] = true;
                q.push({ny,nx,b.cnt + 1,b.isBreak});
            }
        }
    }
    cout << -1;
}