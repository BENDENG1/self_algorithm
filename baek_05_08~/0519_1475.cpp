#include <iostream>

using namespace std;
int n,tmp, sixnine = 0, num_max = 0;
int num[10] = {0,};

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin>>n;
    while (n != 0)
    {
        tmp = n %10;
        num[tmp]++;
        n /=10;
    }
    for(int i = 0; i < 10; i ++)
    {
        if (i != 6 && i != 9)
        {
            if (num_max < num[i])
                num_max = num[i];
        }
        else if(i == 6 || i == 9)
            sixnine+=num[i];
    }
    if(sixnine >= num_max *2)
        num_max = (sixnine / 2) + (sixnine %2);
    cout<<num_max;
}