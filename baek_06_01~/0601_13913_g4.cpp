/*
너비탐색으로 가자
하는데 n-1,n+1,2n 세가지를 계속 너비-너비-너비 진행하면 될듯 ㅇ
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int ans, n, k, pos;
bool visited[100001];
vector<int> road;
int before[100001];
int solve(int n, int k, int ans);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> k;
	cout<<solve(n, k, 0)<<"\n";
    while(!road.empty())
    {
        cout<< road.back()<<" ";
        road.pop_back();
    }
	return 0;
}

int solve(int n, int k,int ans) {
	queue<pair<int, int>>q;
	q.push({ n,ans });
    visited[n]=true;

	while (!q.empty()) {
		pos = q.front().first;
		ans = q.front().second;
		q.pop();

		if (pos == k)
        {
            int tmp  = pos;
            while (tmp!=n)
            {
                road.push_back(tmp);
                tmp = before[tmp];
            }
            road.push_back(n);
            return ans;
        }
			
		if (2 * pos <= 100000 && visited[2 * pos] == false) {
			q.push({ 2 * pos,ans + 1 });
			visited[2 * pos] = true;
            before[2*pos] = pos;
		}
		if (pos < k && visited[pos + 1] == false) {
			q.push({ pos + 1,ans + 1 });
			visited[pos + 1] = true;
            before[pos+1] = pos;
		}
		if (pos > 0 && visited[pos - 1] == false) {
			q.push({ pos - 1,ans + 1 });
			visited[pos - 1] = true;
            before[pos-1] = pos;
		}
	}
}
