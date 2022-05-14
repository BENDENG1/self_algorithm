#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int m, n, i, num;
    cin >> m >> n;
    while (m <= n)
    {
        num = 0;
        for (i = 2; i <= sqrt(m); i++)
        {
            if (m % i == 0)
            {
                num = 1;
                break;
            }
        }
        if (num == 0 && m != 1)
            cout << m << "\n";
        m++;
    }
}