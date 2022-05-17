/*
이분탐색을 진행
동물의 입력값 기준으로 정렬된 벡터에 들어간 사로들을 하나씩 이분탐색하면서 범위내에 있으면 ans++을 진행하였다.
다풀고 생각해보니 그냥 절댓값 함수 들고와서 해도 됬을듯..?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m, n, l,tmp, a_x, a_y;
int start, finish, l_left, l_right,mid, ans = 0;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> m >> n >> l;

    for (int i = 0; i < m; i++)
    {
        cin>>tmp;
        v.push_back(tmp);
    }
        
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cin >> a_x >> a_y;

        if (a_y > l)
            continue;
        start = 0;
        finish = m - 1;
        l_left = a_x + a_y - l;
        l_right = a_x - a_y + l;
        while (start <= finish)
        {
            mid = (start + finish) / 2;

            if(l_left <= v[mid] && v[mid] <= l_right)
            {
                ans++;
                break;
            }
            if (v[mid] < l_left)
                start = mid + 1;
            if (l_right < v[mid])
                finish = mid - 1;
        }
    }
    cout<<ans;
}