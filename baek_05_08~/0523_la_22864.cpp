/*
1시간 피로도 a 일은 b만큼
1시간 휴식 c만큼 줄음
피로도 음수 -> 0
피로도 m을 넘지 않게
*/
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int a, b, c, m;
    int p = 0, s = 0;

    cin >> a >> b >> c >> m;
    for (int i = 0; i < 24; i++)
    {
        if (a > m)
            break;
        if (p + a <= m)
        {
            p += a;
            s++;
        }
        else
        {
            p -= c;
            if (p < 0)
                p = 0;
        }
    }
    cout << b * s;
}