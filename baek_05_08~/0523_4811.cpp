/*
알약 . dp문제?
알약 반개 n개 담긴 병 / 약을 하나 꺼낸다. 반조각이면 먹고 아니라면 쪼개서 반을 먹음
한조각을 꺼낸날엔 w 반조각을 꺼낸날에는 h 2n일이 지나면 길이가 2n인 문자열이 만들어짐
그럼 서로 가능한 문자열의 총개수?

점화식 arr[i][j] = arr[i-1][j] + arr[i][j-1];
*/

// #include <iostream>

// using namespace std;
// int t;
// long long arr[31] = {1, 1, 2, 5,14};

// int main()
// {
//     ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

//     for (int i = 5; i <= 30; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             arr[i] += arr[j] * arr[i - j - 1];
//         }
//     }

//     while (1)
//     {
//         cin >> t;
//         if (t == 0)
//             break;
//         else
//             cout << arr[t] << "\n";
//     }
// }

#include <iostream>

using namespace std;
int t;
long long arr[31][31];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    for(int i = 0; i<31;i++)
        arr[0][i] =1;
    for(int i = 1; i<31;i++)
    {
        for(int j = i;j<31;j++)
        {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    while (1)
    {
        cin>>t;
        if (t==0)
            break;
        cout<<arr[t][t]<<"\n";
    }
}