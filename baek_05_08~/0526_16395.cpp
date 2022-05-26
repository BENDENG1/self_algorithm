/*
1~30인거임
*/

#include <iostream>

using namespace std;
int arr[31][31];
int n,k;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i <= 30; i++)
    {
        arr[i][1] =1;
        arr[i][i] =1; 
        for(int j =1;j<i;j++)
        {
            if (1<j &&j<i)
            {
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }
    }

    cin >> n >> k;
    cout<<arr[n][k];
}