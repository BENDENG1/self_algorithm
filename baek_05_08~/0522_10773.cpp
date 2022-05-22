#include <iostream>
#include <vector>

using namespace std;
int k, tmp,ans = 0 ;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin>>k;
    for(int i = 0; i < k; i ++)
    {
        cin>>tmp;
        if (tmp !=0)
            v.push_back(tmp);
        else
            v.pop_back();
    }
    for(int i = 0;i<v.size();i++)
    {
        ans += v[i];
    }
    cout<<ans;
}