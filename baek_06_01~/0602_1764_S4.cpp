/*
어차피 중복은 없으니 만약 두개가 겹친다면 정렬을할때 지금이름과 다음이름이 같을때 추가를하고 갯수 카운팅하면 끝? ㅇㅇ
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, ans = 0;
string str;
vector<string> people;
vector<string> answer;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        people.push_back(str);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> str;
        people.push_back(str);
    }
    sort(people.begin(), people.end());
    // m개 n개이면 그러면 갯수가 m+n개이니깐 -1까지 해서 비교
    for (int i = 0; i < m + n - 1; i++)
    {
        if (people[i] == people[i + 1])
        {
            ans++;
            answer.push_back(people[i]);
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }
}