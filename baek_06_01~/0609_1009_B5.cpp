/*

*/
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    double a,b;
    double ans;

    cin>>a;
    cin>>b;
    ans = a/b;
    cout.precision(11);
    cout<<ans;
}