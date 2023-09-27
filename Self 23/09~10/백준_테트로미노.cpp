/*
테트로미노

겹치지x,모두 연결, 변끼리 연결 (꼭지점은 x)

n*m -> 놓인칸에 쓰여있는 수들의 합을 최대로 하는 프로그램

회전이나 대칭이 가능하고 
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, tmp;

    cin >> n >> m;

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>tmp;
            v[i].push_back(tmp);
            visited[i].push_back(false);
        }
    }

    for(int i = 0 ; i < n;i++){
        for(int j = 0;j<m;j++){

        }
    }
}