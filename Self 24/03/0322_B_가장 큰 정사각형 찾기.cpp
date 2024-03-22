/*
가장 큰 정사각형 찾기
*/
#include <iostream>
#include <algorithm>

using namespace std;

int v[1001][1001];
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL);

    int n,m;
    int v[1001][1001] = {0,};
    int answer = 0;

    cin >> n >> m;

    for(int i = 0 ; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            v[i][j] = s[j] - '0';
            if(v[i][j] == 1)
                answer = 1;
        }
    }

    
    for(int i = 1 ; i < n; i++){
        for(int j = 1; j < m;j++){
            if(v[i][j] != 0){
                v[i][j] = min({v[i - 1][j] , v[i][j - 1], v[i - 1][j - 1]}) + 1;
                answer = answer > v[i][j] ? answer : v[i][j];
            }
        }
    }

    cout << answer * answer;
    return 0;
}