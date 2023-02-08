/*
14503번 로봇청소기

1순위 자기 자리는 무조건 청소

2순위 왼쪽을 틀고 전진이 메인

1. 일단 왼쪽으로 회전 후 전진
2. 왼쪽이 없다면 왼쪽 두번 후 전진
3. 네 방향 모두 청소 되어있거나 벽인경우, 후진 진행 후 다시 2순위로 복귀
4. 네 방향 모두 청소 되어있거나 벽인데, 후진도 불가능이면 작동 스탑

조건에서 그러면 잘못 놓는 경우는? x -> 그냥 그건 상관 안해도 됨

근데 북동남서 이거 3에서 0으로 가는거 귀찮은데 더 추가하는거는? -> +3 하고 빼고 나머지하면?
*/

#include <iostream>
#include <string.h>

using namespace std;

int n, m;	 // 가로 세로
int r, c, d; // 로봇청소기 좌표(r,c), 바라보는 방향 d (0123/북동남서)
int arr[50][50];
int visited[50][50]; // 방문해서 닦은 경우

int cnt = 1;			   // 처음 자기 자리 닦고 시작함(필연적임)
int dy[4] = {-1, 0, 1, 0}; // 북동남서로 진행
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int direction);

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	cin >> n >> m;
	cin >> r >> c >> d;
	visited[r][c] = 1; //바로 정해진 좌표는 방문 o

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	dfs(r, c, d);

	cout << cnt << "\n";
}

void dfs(int y, int x, int direction)
{
	//cout<<y<<" y    "<<x<<" x   "<<"\n";
	for (int i = 0; i < 4; i++)
	{
		int ndirection = (direction + 3 - i) % 4;
		int ny = y + dy[ndirection];
		int nx = x + dx[ndirection];

		if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] == 0)
		{
			if (visited[ny][nx] == 0)
			{
				cout<<"newdirection : "<<ndirection<<"  cnt : "<<cnt<<"   ";
				cout<<ny<<" " <<nx<<" "<<"\n";
				visited[ny][nx] = 1;
				cnt++;
				dfs(ny, nx, ndirection);
			}
		}

	}

	//0123 북동남서
	//방향 0 -> 2, 1 -> 3 , 2 -> 0, 3 -> 1
	int direction_back;
	if(direction >= 2)
		direction_back = direction - 2;
	else
		direction_back = direction + 2;

	int y_back = y + dy[direction_back];
	int x_back = x + dx[direction_back];

	if(0 < y_back && 0 < x_back && y_back < n && x_back < m){
		if(arr[y_back][x_back] == 0){
			dfs(y_back,x_back,direction);
		}
		else
			return;
	}
}
