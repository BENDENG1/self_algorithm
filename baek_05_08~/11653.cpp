#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, i = 2;
    cin >> n;
    if (n == 1)
        return (0);
    while (i <= n)
    {
        if (n % i == 0)
        {
            n /= i;
            cout << i << "\n";
            i = 1;
        }
        i++;
    }
    return (0);
}