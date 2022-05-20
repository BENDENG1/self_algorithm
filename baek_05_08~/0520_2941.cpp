/*
크로아티아 알파벳
알파벳 으로 이루어져 있음
c일때, d일때 l일때 n일때 s 일때 z일때
*/

#include <iostream>
#include <cstring>

using namespace std;
string arr[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
char str[101];
int i = 0;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> str;
    int len = strlen(str);
    int ans = strlen(str);
    for (int i = 0; i < len; i++)
    {
        // cout<<"i = "<<i<<"   ans = "<<ans<<"\n";
        if (str[i] == 'c' || str[i] == 's' || str[i] == 'z')
        {
            if (str[i + 1] == '=' || str[i+1] =='-')
                ans--;
        }
        else if (str[i] == 'd')
        {
            if (str[i + 1] == 'z' && str[i + 2] == '=')
            {
                ans--;
            }
            else if (str[i + 1] == '-')
            {
                ans--;
            }
        }
        else if (str[i] == 'l' || str[i] == 'n')
        {
            if (str[i + 1] == 'j')
            {
                ans--;
            }
        }
    }
    cout << ans;
}