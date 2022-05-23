/*
n장의 공유카드 n장의 팀숫자카드
상대는 우리에게 팀 숫자카드 k장을 견제, 견제된 카드는 낼수 x
두카드의 곱이 점수 높을경우 win

그럼 벡터로 그냥 두개 받고 정렬하고 그다음에 만약에 모든 경우를 돌렸을때 최댓값인 경우에 대해서 team원소 하나 지우고
다시 돌리고 또 지우고... 그래서 마지막에 하나 받아오면 ㅇㅇ
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k, tmp, m_max = -100000000, erase_index;
vector<int> share;
vector<int> team;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        share.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        team.push_back(tmp);
    }
    sort(share.begin(), share.end());
    sort(team.begin(), team.end());
    for (int l = 0; l <= k; l++)
    {
        m_max = -100000000;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-l; j++)
            {
                if (m_max < share[i] * team[j])
                {
                    m_max = share[i] * team[j];
                    erase_index = j;
                }
            }
        }
        if (l != k)
            team.erase(team.begin() + erase_index);
    }
    cout << m_max;
}