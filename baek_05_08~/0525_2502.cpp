/*
그러면 브루트포스 처럼 그냥 모든것을 다 돌리면서 진행?
했을때 맞으면 숫자 아니면 0을 출력해서 맞으면 브레이크?
*/
#include <iostream>

using namespace std;
int d, k,a,b,tmp,flag=0;
int arr[30];

int ft_find(int a, int b);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> d >> k;
    for (int i = 1; i < k; i++)
    {
        for (int j = 1; j < k; j++)
        {
            tmp = ft_find(i, j);
            if (tmp >0)
            {
                a = i;
                b = j;
                flag =1;
                break; 
            }
        }
        if (flag ==1)
            break;
    }
    cout<<a<<"\n"<<b;
}

int ft_find(int day1, int day2)
{
    arr[1]=day1;
    arr[2]=day2;
    for(int i = 3;i <= d;i++)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
    if (arr[d] == k)
        return k;
    else return 0;
}