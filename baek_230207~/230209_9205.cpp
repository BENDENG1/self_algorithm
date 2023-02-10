/*
9205번

맥주 한박스 -> 20병  / 50미터에 한병씩 마심 / 박스의 맥주는 최대 20병을 넘을 수 없음

편의즘, 집, 페스티벌 좌표가 주어지는데 상근&친구들 페스티벌 도착할 수 있는지 테스트
도착 가능 -> happy , 도착 불가 -> sad

두 좌표의 사이의 거리는 x좌표 차이 + y좌표 차이

*/

#include <iostream>
#include <vector>
#include <stdlib.h> //절댓값 사용(abs)
#include <cstring>

using namespace std;

int t; // 테스트 케이스 갯수
int n; // 편의점 갯수
vector<pair<pair<int,int>,int> >v;
int ans = 0;
int y,x;
int goal_y,goal_x;

void dfs(int y, int x);

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		v.clear();
		ans = 0;

		cin >> n;
		for (int j = 0; j < n + 2; j++)
		{
			cin>>y>>x;
			v.push_back(make_pair(make_pair(y,x),0));
		}


		goal_y = v.back().first.first;
		goal_x = v.back().first.second;
		dfs(v.front().first.first, v.front().first.second);
		if(ans == 1){
			cout<<"happy\n";
		}
		else{
			cout<<"sad\n";
		}

	}


}

void dfs(int y, int x){
	for(int i = 0; i < v.size(); i++){
		int ny = v[i].first.first;
		int nx = v[i].first.second;
		int distance = abs(ny - y) + abs(nx - x);

		if (distance <= 1000 && v[i].second == 0){
			if(ny == goal_y && nx == goal_x)
			{
				ans = 1;
				return;
			}

			v[i].second = 1;
			//v.erase(remove(v.begin(),v.end(),pair(ny,nx)), v.end());
			dfs(ny,nx);
		}
	}
}

