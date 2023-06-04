/*
A-> B 문제

A를 B롤 바꾸려 하는데
2를 곱하거나 1을 추가하거나 둘중 하나임
이걸 과정을 하는데 연산의 최솟값에 대해 오른쪽에 1을 더한 값을 출력

자 어떻게 하냐? 
1) 2를 곱한다.
2) 오른쪽에 1을 더한다. 
이 두과정에 대해서 bfs로 하면서 도달했을때 바로 멈춘다

안되면 -1리턴

짝수이거나 무조건 홀수는 1이 아니면 -1 return 즉 -> 3,5,7,9는 애초에 안됨
*/

#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    long a,b;

    cin>>a>>b;

    //3,5,7,9에 대한 처리
    if(b % 10 != 1 && b % 2 !=0){
        cout<<"-1";
        return 0;
    }

    queue<pair<long,int>> q;
    q.push(make_pair(a,1));

    while(!q.empty()){
        long num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        long twoMulti = num * 2;
        long plusOne = num*10 + 1;

        if(twoMulti == b || plusOne == b){
            cout<<cnt+1;
            return 0;
        }
        if(twoMulti < b)
            q.push(make_pair(twoMulti,cnt+1));
        if(plusOne < b)
            q.push(make_pair(plusOne,cnt+1));
    }

    cout<<"-1";

}
