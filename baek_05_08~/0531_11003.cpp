/*
dq에서 pop되는 원소가 있을때 그 원소가 만약 pq의 최솟값이라면 pop을 진행하고 아니면
그대로 집어넣고 계속 출력출력 하면 될듯ㅇㅇ
시간초과 fuck..그러면 그냥 그 계속 pop을 하다가ㅇㅇ
두개를 pair로 해서 받으면 되는데 그걸왜 생각을 못했지..?
*/

#include <iostream>
#include <deque>

using namespace std;
int n,l;
int arr[5000001];
deque<pair<int,int>> dq;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    cin>>n>>l;
    for(int i =1;i<=n;i++)
        cin>>arr[i];
    for(int i =1;i<=n;i++)
    {
        if(!dq.empty())
            if(dq.front().second<i-l+1)
                dq.pop_front();
        while (!dq.empty()&&dq.back().first >arr[i])
            dq.pop_back();
        dq.push_back(make_pair(arr[i],i));
        cout<<dq.front().first<<" ";
    }
}


/*
#include <iostream>
#include <queue>
#include <deque>
#include <vector>

using namespace std;
int n,l,index,tmp,first;
deque<int> dq;
//priority_queue<int> pq;
//pirority queeu reverse order c++
priority_queue<int,vector<int>,greater<int>>pq;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    cin>>n>>l;
    for(int i = 0;i<n;i++)
    {
        cin>>index;
        dq.push_back(index);
        pq.push(index);
        if(dq.size()>l)
        {
            tmp = dq.front();
            dq.pop_front();
            if(tmp==pq.top())
            {
                while(!pq.empty())
                {
                    pq.pop();
                }
                for(int i = 0;i<l;i++)
                {
                    first = dq.front();
                    dq.pop_front();
                    pq.push(first);
                    dq.push_back(first);
                }
            }    
            // cout<<" |checkpoint| ";
        }
        cout<<pq.top()<<" ";
    }
}
*/
