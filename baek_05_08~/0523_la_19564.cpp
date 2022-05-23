/*
예시 처럼 polymath이면
abcdefghijklmno(p)qrstuvwxyzabcdefghijklmn(o)pqrstuvwxyzabcdefghijk(l)mnopqrstuvwx(y)zabcdefghijkl(m)nopqrstuvwxyz(a)bcdefghijklmnopqrs(t)uvwxyzabcdefg(h)ijklmnopqrstuvwxyz
로 되는거라서 그냥 a~z일때 다음 문자가 앞에 문자면 하나 추가 뒤에꺼면 하나 아끼는것
*/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    string str;
    int cnt = 1;
    cin>>str;

    for(int i = 0;i<str.size() -1;i++)
    {
        if (str[i] < str[i+1])
            continue;
        cnt++;
    }
    cout<<cnt;
}