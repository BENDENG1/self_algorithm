#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m, p, e; // n : 끊어진 줄 , m : 갯수
    int package = 1000, each = 1000;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> e;
        package = min(package, p);
        each = min(each, e);
    }
    if ((n % 6) * each >= package)
        cout << package * (n / 6) + package;
    else if (each * 6 < package)
        cout << n * each;
    else
        cout << (n / 6) * package + (n % 6) * each;
}