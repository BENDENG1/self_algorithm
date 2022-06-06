/*
지들끼리 교환을 할수 있음, 앞부분 혹은 뒷부분에 넣음 -> 그러면 암호화된 문자가 어떤순서든 연속적으로 있으면 o
결국 원본이 떨어지면 문제가 생기는거임 ㅇㅇ

앞에만 붙을때 , 뒤에만 붙을때 , 앞뒤에 붙을때와 안붙을때 네가지 케이스고려.
0 0 0 0 0 1 1 1 1 1 1 0 0 0 0
시간초과다 그러면 엄청길때를 고려해야하기 때문에 배열을 alphabet[26]을 선언해서 처리할까?
*/
#include <iostream>
#include <cstring>

using namespace std;
int t, tmp,tf;
string password, original;
int arr[26][100001];
int alphabet[26];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> password;
        cin >> original;
        memset(arr, 0, sizeof(arr));
        memset(alphabet,0,sizeof(alphabet));
        for(int k=1;k<=password.size();k++)
        {
            for (int j = 0; j < 26; j++)
            {
                arr[j][k] = arr[j][k-1];
            }
            tmp = password[k-1] - 'a';
            arr[tmp][k] += 1;
        }

        for(int j = 0;j<original.size();j++)
        {
            tmp = original[j] - 'a';
            alphabet[tmp]+=1;
        }

        for(int j = 0;j<=password.size()-original.size();j++)
        {
            tf = 1;
            for(int k =0;tf==1&&k<26;k++)
            {
                if(arr[k][j+original.size()] - arr[k][j] != alphabet[k])
                {
                    tf=0;
                }    
            }
            if(tf==1)
            {
                cout<<"YES\n";
                break;
            }
        }
        if(tf==0)
            cout<<"NO\n";

        // for(int j =0;j<original.size();j++)
        // {
        //     tmp = original[j] -'a';
        //     alphabet[tmp] +=1;
        // }
        // for (int j = 0; j < original.size(); j++)
        // {
        //     for (int k = 0; k < password.size(); k++)
        //     {
        //         if (password[k] == original[j])
        //             arr[k] = 1;
        //     }
        // }
        // for (int j = 0; j < password.size() - 1; j++)
        // {
        //     if (arr[j] == 0 && arr[j + 1] == 1)
        //         front += 1;
        //     if (arr[j] == 1 && arr[j + 1] == 0)
        //         back += 1;
        // }
        // if (front <= 1 && back <= 1)
        //     cout << "YES"<< "\n";
        // else
        //     cout << "NO"<< "\n";
    }
}