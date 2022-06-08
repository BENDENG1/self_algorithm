/*
Ʈ��
n���� Ʈ���� ������ ������ �ٲܼ� x ���Դ� ����
�ٸ��� ���̴� w �����ð��� �ϳ��� �������̸�ŭ �̵�
������ l���� �۾ƾ���

for�� ũ�� n���� ���鼭
while�� �ȿ��� ó���� �����Ѵ�. �ʰ��Ѵٸ� �ƴ϶�� ���� ������ ��
��� 0�� Ǫ���ϸ鼭 ��ٸ��°��� �׷��� ���԰� �ٽ� �������� ���Ϲ��� ��Ż�ϰ� �ٽ� Ǫ���Ѵ�.
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