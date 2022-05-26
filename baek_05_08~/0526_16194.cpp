/*
최솟값을 갱신하면서
갱신될때마다 arr[i~~]에 다가 저장을 하면서 dp를 늘려간다
그리고 나서 arr[i]를 찾을 때에는 모든 값들의 합에 대해서 처리를 하면된다.

ex) arr[4] 
4 / 3,1 / 2,2 / 2,1,1 / 1,1,1,1 
부분에 대해서 2,1,1은 1,1과 2의 최솟값을 2에서 측정했기 때문에 pass
3,1과 1,1,1,1도 3과 1,1,1이 3에서 측정이 되기 때문에 pass
다 이런식이다.
2= 2,1+1
3= 3, 2+1
4= 4, 3+1 2+2
5= 5, 4+1, 3+2
6= 6, 5+1, 4+2, 3+3 중 최솟값을 찾아 갱신
*/
#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[1001]={0,};

int getmin(int a, int b) {return a<b? a:b;}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    cin>>n;
    for(int i =1;i<=n;i++)
        cin>>arr[i];
    
    for(int i = 1; i<= n ;i++)
    {
        for( int j = 1; j <= i;j++)
        {
            arr[i] = getmin(arr[i],(arr[i-j]+arr[j]));
        }
    }
    cout<<arr[n];
}