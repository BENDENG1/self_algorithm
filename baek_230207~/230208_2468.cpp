/*
2468번

비가 올 수 있는곳은 1이상 100이하
일단 시간 낭비를 절약하기 위해 높이가 가장 높은 지역을 입력 받을때 추출

dfs로 문제를 푸는게 낫지 않을까 생각.
dfs로 이제 더이상 갈곳이 없다면 이제 cnt++로 진행해서 하면 되지 않을까 생각


*/

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int arr[101][101];
int sink_visited[101][101];
int visited[101][101];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int max_rain = 0;
int ans = 0;
int cnt = 0;

void dfs(int max_h, int rain_h, int y, int x);

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	memset(arr, 0, sizeof(arr));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			max_rain = max(arr[i][j], max_rain);
		}
	}

	for (int i = 0; i <= max_rain; i++)
	{
		memset(sink_visited, 0, sizeof(sink_visited)); // 높이마다 계속 추출을 해야하기 때문에 계속 진행
		cnt = 0;
		for(int j = 0; j < n ; j++){
			for(int k = 0; k < n; k++){
				if(arr[j][k] <= i){
					sink_visited[j][k] = 1;
				}
			}
		}
		for(int j = 0; j < n ; j++){
			for(int k = 0; k < n; k++){
				if(!sink_visited[j][k]){
					cnt++;
					dfs(max_rain,i,j,k);
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout<<ans<<"\n";
}

void dfs(int max_h, int rain_h, int y, int x)
{
	sink_visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && nx >= 0 && ny < n && nx < n && !sink_visited[ny][nx])
		{
			dfs(max_h,rain_h,ny,nx);
		}
	}
}
