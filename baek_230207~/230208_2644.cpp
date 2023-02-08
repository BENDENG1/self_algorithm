/*
부모와 자식은 1촌

1 : 전체사람의 수 n 이 주어지고
2 : 촌수를 계산해야하는 서로 다른 두 사람
3 : 부모 자식들 간의 관계의 개수 m
4 ~ : 부모 자식간의 관계를 두 번호 x,y가 각줄에 나옴 부모,자식

첫번째 예제를 기준으로 하면
1

2         3
7,8,9

관련없는 4가 존재
4
5,6
이렇게 정리가 되는 것이다.

전형적인 dfs문제로 개념이 잡히면 바로 풀듯?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, a, b, m; // 전체사람, 두관계 , 촌수 관계 갯수
int tmp1, tmp2; // 두 부모 자식 관계 임의 변수
int ans = 0;
int arr[101][101];
int visited[101];

void dfs(int cnt, int rel1, int rel2);

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	cin >> a >> b;
	cin >> m;

	memset(visited, 0, sizeof(visited));
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < m; i++)
	{
		cin >> tmp1 >> tmp2;
		arr[tmp1][tmp2] = 1;
		arr[tmp2][tmp1] = 1;
	}

	dfs(0, a, b);

	if(ans == 0)
		cout<<"-1"<<"\n";
	else
		cout << ans << "\n";
}

void dfs(int cnt, int rel1, int rel2)
{
	visited[rel1] = 1;

	if (rel1 == rel2)
	{
		ans = cnt;
	}
	for (int i = 1; i <= n; i++)
	{
		int next = arr[rel1][i];
		if (next == 1 && !visited[i]) //방문하지도 하지도 않았고 관계가 존재하는거라면
		{
			dfs(cnt + 1,i,rel2);
		}
	}
}
