#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    int n, tmp, t;
    priority_queue<int> pq;
    cin>>n;
    for(int i= 0; i < n; i++)
    {
        cin>>tmp;
        if (tmp == 0)
        {
            if (pq.empty())
            {
                cout<<"-1" << "\n";
            }
            else
            {
                cout << pq.top()<<"\n";
                pq.pop();
            }
        }
        else
        {
            for(int j = 0; j < tmp; j++)
            {
                cin >> t;
                pq.push(t);
            }
        }
    }
}