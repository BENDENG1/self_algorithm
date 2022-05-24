/*
왼쪽 아래의 꼭지점을 알려줌 그러면 우리는 그걸 조합해서 둘레를 측정
(25 - 3)  * 2 + (24 - 2) * 2 = 88 에다가 안에있는 둘레 +8 = 96이다.
-> 이 방식 너무 구림

arr[101][101]로 해서 0이면 방문하지 x 1이면 변의 꼭지점 2이면 로 설정
0이라면 바꿈 근데 기존의 1들은 어떻게 처리?
-> 그냥 범위 안에 들어오는것을은 모두 2로 처리.
로 생각했는데 생각해보니 너무 번거로움이 발생.. 그럴바에는 그냥 모두 1로 초기화하고 ny,nx에 대해서 만약에 0이라면 cnt++로 하는게 나을듯?
*/

#include <iostream>

using namespace std;
int t, x, y, nx, ny,cnt = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int arr[102][102] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        for (int j = y + 1; j <= y + 10; j++)
        {
            for (int k = x + 1; k <= x + 10; k++)
            {
                arr[j][k] = 1;
            }
        }
    }

    // // 디버깅용
    // for (int j = 0; j < 30; j++)
    // {
    //     for (int k = 0; k < 30; k++)
    //     {
    //         cout << arr[j][k] << ' ';
    //     }
    //     cout << "\n";
    // }


    for (int i = 0; i <= 101; i++)
    {
        for (int j = 0; j <= 101; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                ny = i + dy[k];
                nx = j + dx[k];
                if (arr[ny][nx]==0 && arr[i][j]==1)
                    cnt++;
            }
        }
    }
    cout<<cnt;
}

/*
#include <iostream>

using namespace std;
int t, x, y, cnt = 0;
int arr[102][102] = {0,};
void check(int cy, int cx, int y, int x);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        for (int j = y; j <= y + 10; j++)
        {
            for (int k = x; k <= x + 10; k++)
            {
                check(j, k, y, x);
            }
        }
    }

    // 디버깅용
    for (int j = 0; j < 30; j++)
    {
        for (int k = 0; k < 30; k++)
        {
            cout << arr[j][k] << ' ';
        }
        cout << "\n";
    }

    for (int j = 0; j <= 100; j++)
    {
        for (int k = 0; k <= 100; k++)
        {
            if (arr[j][k] == 1)
                cnt++;
        }
    }
    cout << cnt;
}

void check(int cy, int cx, int y, int x)
{
    int nx[4]={1,0,-1,0};
    int ny[4]={0,1,0,-1};
    //변이 딱 맞을때도 조건 추가
    if (arr[cy][cx] == 1)
    {
        if (cy == y || cx == x || cy == y + 10 || cx == x + 10)
            arr[cy][cx] = 2;
    }
    if (arr[cy][cx] == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (arr[cy + ny[i]][cx + nx[i]] == 1)
            {
                arr[cy][cx] = 2;
                arr[cy + ny[i]][cx + nx[i]] == 2;
            }
        }
    }

    if (arr[cy][cx] == 0)
    {
        if (cy == y || cx == x || cy == y + 10 || cx == x + 10)
            arr[cy][cx] = 1;
        else
            arr[cy][cx] = 2;
    }
    //무조건 내부이면 2로 수정
    if (cy > y && cx > x && cy < y + 10 && cx < x + 10)
        arr[cy][cx] = 2;
}
*/