#include <iostream>

using namespace std;
int arr[7];
int tf = 0,odd_min = 100,sum = 0;;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    for(int i = 0; i < 7; i++)
    {
        cin>>arr[i];
        if (arr[i] % 2 == 1)
        {
            tf = 1;
            if (arr[i] < odd_min)
                odd_min = arr[i];
            sum += arr[i];
        }
    }
    if (tf ==0)
        cout<<-1;
    else
    {
        cout<<sum<<"\n"<<odd_min;
    }
}