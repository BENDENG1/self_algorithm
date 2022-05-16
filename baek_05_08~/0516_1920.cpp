#include <iostream>
#include <algorithm>

using namespace std;
int n,m,tmp,ans;
int arr[100001];

int b_search(int arr[],int start, int end, int find)
{
    int mid = (start + end) / 2;
    if (start <= end)
    {
        if (arr[mid] == find)
            return 1;
        else if (arr[mid] > find)
            return b_search(arr, start,mid-1,find);
        else
            return b_search(arr,mid+1,end, find);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr,arr+n);

    cin>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>tmp;
        ans = b_search(arr,0,n-1,tmp);
        cout<<ans<<"\n";
    }
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, m,tmp, *p;
    int arr[100001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    
    cin>>m;
    for(int i = 0; i <m ;i++)
    {
        cin>>tmp;
        p = find (arr,arr+n,tmp);
        if (p != arr+n)
            cout<<"1\n";
        else
            cout<<"0\n";
    }
}
*/

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, tmp, flag;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (tmp == arr[j])
            {
                cout << "1\n";
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "0\n";
    }
}
*/