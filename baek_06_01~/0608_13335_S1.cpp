/*
트럭
n개의 트럭이 지나고 순서를 바꿀수 x 무게는 랜덤
다리의 길이는 w 단위시간에 하나의 단위길이만큼 이동
하중은 l보다 작아야함

for문 크게 n까지 돌면서
while문 안에서 처리를 진행한다. 초과한다면 아니라면 으로 진행을 함
계속 0을 푸쉬하면서 기다리는거지 그러면 무게가 다시 낮아지면 와일문을 이탈하고 다시 푸쉬한다.
*/
#include <iostream>
#include <queue>

using namespace std;
int n, w, l;
int tmp, cnt = 0;
int weight=0;
queue<int> q;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i =0;i<n;i++)
    {
        while(1)
        {
            if(q.size()==w)
            {
                weight-=q.front();
                q.pop();
            }
            if(weight+v[i] <=l)
            {
                break;
            }
            q.push(0);
            cnt++;
        }
        q.push(v[i]);
        weight+=v[i];
        cnt++;
    }
    cnt+=w;
    cout<<cnt;
}