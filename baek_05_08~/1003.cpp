#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t, n;
    cin >> t;
    int arr[41][2];
    arr[0][0] = 1, arr[0][1] = 0;
    arr[1][1] = 1, arr[1][0] = 0;
    for (int i = 2; i <= 40; i++)
    {
        arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
        arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
    }
    for (int i = 0; i < t; i++)
    {
        cin>>n;
        cout<< arr[n][0]<< ' '<< arr[n][1]<<"\n";
    }
}

/*
int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
*/
