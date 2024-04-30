/*
혼자 놀기의 달인

1~100 가지의 숫자 카드 / 무작위로 섞어 일렬로 나열 / 나열된 순서에 따라 번호를 붙힘

8 6 3 7 2 5 1 4
1 2 3 4 5 6 7 8

대체 이게 무슨말이지?

말이 처음에 이해하기가 어렵지 그냥 1부터 시작해서 자기 번호 나올때가지 해서 나오면 그냥 그게 한 그룹임

그것중에서 그룹이 가장 큰 두개를 해서 곱하면 되고 하나만 나오면 0return 하면 됨

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> visited(cards.size() + 1, false);
    vector<int> v;
    
    for(int i = 0; i < cards.size(); i++){
        int num = cards[i];
        int cnt = 0;
        while(!visited[num]){
            visited[num] = true;
            num = cards[num - 1];
            cnt++;
        }
        if(cnt > 0 )
            v.push_back(cnt);
    }
    if(v.size() > 1){
        sort(v.begin(), v.end());
        return v[v.size() - 1] * v[v.size() - 2];
    }else{
        return 0;
    }
}


