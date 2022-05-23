/*
v높이 감
a올라갈수 있고 b내려옴
*/

#include <iostream>

using namespace std;
int a,b,v,h = 0,cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    cin>>a>>b>>v;

    
    if (a ==v)
    {
        cout<<1;
    }
    else
    {
        h = v-b;
        cnt=h/(a-b);
        if (h % (a-b)!=0)
            cnt++;
        cout<<cnt;
    }

}

/*
#include <iostream>

using namespace std;
int a,b,v,h = 0,cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    cin>>a>>b>>v;

    while (1)
    {
        h+=a;
        cnt++;
        if (h>=v)
            break;
        h-=b;       
    }
    cout<<cnt;
}
*/