/*
2573번 빙산

동서남북 기준으로 진행을 함 그리고 만약에 이제 빙산이 두개이상으로 나눠지면 횟수를 출력
만약에 다 갈라지지 않는다면 0을 출력하는 문제


*/
#include <iostream>
#include <cstring>
#include <algorithm> //equal함수 사용하기 위해 사용
#include <array>	 // all_of를 사용하려면 array로 클래스 해줘야함 -> 그냥 가능? ㅇㅇ

using namespace std;

int n, m;
int arr[300][300];
int visited[300][300];
int start_y, start_x;
int all_visited = 0;
int ice_twice = 0;
bool twice = false;
int twice_visited[300][300];
// array<int,4> twice_check;
int cnt = 0;
int dy[4] = {0, 0, 1, -1}; // 동서남북 기준
int dx[4] = {-1, 1, 0, 0};

void dfs(int y, int x);
void twice_ice(int y, int x);
int check_sea();

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(0,0);

	cout << cnt << "\n";
}

void dfs(int y, int x)
{
	visited[y][x] = 1; // 방문을 했음

	all_visited = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0)
			{
				all_visited = 0;
			}
		}
	}
	if (all_visited)
	{
		cout<<"\n\n\n";
		for(int i = 0 ; i < n; i++){
			for(int j = 0;j<m;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
		cnt += 1;
		ice_twice = 0; // 항상 매번 체크를 할때 초기화 해줘야함
		memset(twice_visited,0,sizeof(twice_visited)); // 시작하기 전에 초기화
		twice_ice(0,0); //빙산이 두개이상인지 체크하는 함수
		if (ice_twice >= 2)
		{
			cout << cnt << "\n";
			exit(0);
		}
		if(check_sea()){
			cout<<"0\n";
			exit(0);
		}
		memset(visited, 0, sizeof(visited));
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (visited[ny][nx] == 0 && ny >= 0 && nx >= 0 && ny < n && nx < m)
		{

			if (arr[ny][nx] >= 1 && !visited[ny][nx])
			{
				dfs(ny, nx);
				arr[ny][nx] -= 1;
			}
		}
	}
}

void twice_ice(int y, int x)
{
	//twice_visited배열 0이라면 아직 방문x 2라면 빙산 1이라면? 방문 o?


	twice_visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 4각이 모두 바다라면 그것이 바로 고립된 것?
		// 결국 4면이 다 바다라면 그 빙산은 고립된것을 표현한것. 그리고 따로 초기화 할 필요가 없이 항상 다 좌표를 체크해서 상관없을듯
		// 아 틀렸다 생각해보니 두개씩 두개 붙혀 있다고 생각하면 또 다르다..
		// 첫번째,마지막 행과 열에는 항상 0 이므로 따로 ny,nx에 대해 조건을 걸 필요가 없는듯 싶음
		if (!twice_visited[ny][nx] && ny >= 0 && nx >= 0 && ny < n && nx < m)
		{
			twice_ice(ny,nx);
		}

		//2면에 바다, 3면이 바다,
	}
}

int check_sea(){
	for(int i = 0;i<n;i++){
		for(int j = 0; j < m ;j++){
			if(arr[i][j] >= 1)
				return 0;
		}
	}
	return 1;
}
