/*
n,m 지도 존재 지도의 좌표는 (r,c)

 0
123
 4
 5 

1235
0
2
4
5
*/
#include <iostream>
#include <queue>

using namespace std;
int dice[6] = {0,};

void moveDice(int d) {
	int tmp = dice[2];
	if (d == 0) { //오른쪽 회전 1235가 바뀜
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = tmp;
	}
	else if (d == 1) {
        dice[2] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
	}
	else if (d == 2) {
        dice[2] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[0];
        dice[0] = tmp;
	}
	else if (d == 3) {
        dice[2] = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[4];
        dice[4] = tmp;
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    queue<int> q;
    int n, m, x, y, k, dir;
    int dy[4] = {0,0,-1,1};
    int dx[4] = {1,-1,0,0};
    int arr[21][21];

    cin >> n >> m >> y >> x >> k;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < k;i++){
        cin >> dir;
        q.push(dir - 1);
    }

    while(!q.empty()){
        dir = q.front();
        q.pop();

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny < 0 || ny >= n || nx < 0 || nx >= m) 
            continue;

        moveDice(dir);
        if(arr[ny][nx] == 0){
            arr[ny][nx] = dice[5];
        }else{
            dice[5] = arr[ny][nx];
            arr[ny][nx] = 0;
        }
        cout << dice[2] <<"\n";
        y = ny;
        x = nx;
    }

}

