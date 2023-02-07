/*


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int arr[51][51];
int visited[51][51];

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int bfs(int y,int x);
int ans = 0;
int cnt = 0;
int n,m;
int bfs(int y, int x);

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    
    cin>>n>>m;

    for(int i =0;i<n;i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i =0;i<n;i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0)
            {
                ans = max(ans, bfs(i,j));
            }
        }
    }
    cout<<ans<<"\n";
}

int bfs(int y, int x){
    memset(visited, 0,sizeof(visited));
    queue<pair<pair<int,int>,int>>q;
    cnt = 0;
    visited[y][x] = true;
    q.push(make_pair(make_pair(y,x),cnt));

    while(!q.empty()){
        int py = q.front().first.first;
        int px = q.front().first.second;
        int pcnt = q.front().second;

        q.pop();

        if(arr[py][px] == 1){
            return pcnt;
        }
        for(int i = 0;i<8;i++){
            int ny = py + dy[i];
            int nx = px + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx <= m && !visited[ny][nx]){
                visited[ny][nx] = true;
                q.push(make_pair(make_pair(ny,nx),pcnt + 1));
            }
        }
    }

}