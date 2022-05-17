/*
2467과 같은 맥락의 문제이다 근데 정렬이 안되어 있는 문제 그러므로 정렬을 해서 똑같이 진행하면 되지 않을까 싶다.
*/

#include <iostream>
#include <algorithm>

using namespace std;
int ft_abs(int num);
int sum_ans = 2000000000;
int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, l, r, l_ans, r_ans, sum;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    l = 0;
    r = n - 1;
    while (l < r)
    {
        sum = arr[l] + arr[r];
        if (ft_abs(sum) < ft_abs(sum_ans))
        {
            sum_ans = sum;
            l_ans = arr[l];
            r_ans = arr[r];
        }
        if (sum == 0)
            break;
        else if (sum > 0)
            r--;
        else if (sum < 0)
            l++;
    }
    cout << l_ans << ' ' << r_ans;
}

int ft_abs(int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}