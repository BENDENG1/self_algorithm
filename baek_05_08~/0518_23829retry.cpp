/*
이분 탐색..
근데 생각해보니 그냥 절댓값때려서 더하면 안되나? -> 응 시간초과~
그러면
왼쪽에 있는 나무들의 위치들의 점수의 합은 -> 사진가의 위치 * 나무의 갯수 - 모든 나무의 거리의 합
오론쪽에 있는 나무들의 위치들의 점수의 합 -> 모든 나무거리의 합 - 사진가의 위치 * 나무의 갯수
로 계산할수 있다.

그러면 우리는 어떤숫자를 찾는것이 아닌 그 숫자 보다 낮은값들과 그 숫자보다 높은값들에 대해서 진행하면 될듯
구현하고 보니 algorithm라이브러리에 lower_bound있는데 그거 쓸걸
ans = tmp*(mid- 1) -sum[mid - 1] + sum[n] - sum[mid-1] -tmp*(n-mid + 1); 이렇게만 했더니 나무가 가장 클때에 대해서는 26이 출력이됨
이 케이스 다시 추가
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
long long n, q, tmp;
long long l, r, mid, l_pos, r_pos, ans;
long long arr[10000001]={0,};
long long sum[10000001]={0,};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for (int j = 1; j <= n; j++)
        sum[j] = sum[j - 1] + arr[j];

    for (int i = 0; i < q; i++)
    {
        cin >> tmp;
        ans = 0;
        l = 0;
        r = n;
        while (l <= r)
        {
            mid = (r + l) / 2;
            if (tmp < arr[mid])
                r = mid - 1;
            else if (arr[mid] < tmp)
                l = mid + 1;
            else
                break;
        }
        // 인간디버깅
        // cout<< mid<<" ->mid\n" << sum[n] <<" ->sum[n]\n"<< sum[mid-1]<< " ->sum[mid-1]\n"<<n<<" ->n\n";
        if (arr[mid]<=tmp)
            ans = tmp*mid - sum[mid] +sum[n] - sum[mid] - tmp * (n-mid);
        else
            ans = tmp*(mid- 1) -sum[mid - 1] + sum[n] - sum[mid-1] -tmp*(n-mid + 1);
        cout << ans << "\n";
    }
}

/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n, q, tmp, j, ans;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> tmp;
        j = 0;
        ans = 0;
        while (j < n)
        {
            ans += abs(tmp - arr[j]);
            j++;
        }
        cout << ans << "\n";
    }
}
*/