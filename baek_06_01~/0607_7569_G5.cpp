/*
그냥 bfs로 푼다 근데 기존 문제들과 다른점은 6각에 대해서 생각을 하면 된다.
그리고 좌표가 세가지라서 위,아래,상하좌우 이렇게 여섯개에 대해서 bfs를 진행하면서 cnt를 진행하면 된다.
*/
#include <iostream>
#include <queue>

using namespace std;
int m, n, h,none =0,cnt=0;
int arr[101][101][101];
int visited[101][101][101];
queue<pair<pair<int,int>,int>>q;

int bfs();
int dz[6]={1,-1,0,0,0,0};
int dy[6]={0,0,0,1,0,-1};
int dx[6]={0,0,1,0,-1,0};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> arr[i][j][k];
                if(arr[i][j][k]==1)
                    q.push(make_pair(make_pair(j,k),i));
                else if(arr[i][j][k] == -1)
                    none++;
            }
        }
    }
    cout<<bfs();
}

int bfs()
{
    if (q.empty())
        return -1;
    
    while(!q.empty())
    {
        int size = q.size();

        for(int i =0;i<size;i++)
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int z = q.front().second;
            q.pop();

            for(int j = 0;j<6;j++)
            {
                int ny = y+dy[j];
                int nx = x+dx[j];
                int nz = z+dz[j];

                if(0<=ny&& ny<n&&0<=nx&&nx<m&&0<=nz&&nz<h)
                {
                    if(arr[nz][ny][nx] ==0)
                    {
                        arr[nz][ny][nx]=1;
                        q.push(make_pair(make_pair(ny,nx),nz));
                    }    

                }
            }

            if (q.size() == 0)
            {
                int finish = 1;
                for (int i = 0; i < h; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        for (int k = 0; k < m; k++)
                        {
                            if(arr[i][j][k] == 0)
                                finish=0;
                        }
                    }
                }
                if(finish==1)
                    return cnt;
                else
                    return -1;
            }
        }
            cnt++;
    } 
}