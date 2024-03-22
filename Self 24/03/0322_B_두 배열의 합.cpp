/*
두 배열의 합

숫자를 만들면됨 합해가지고 
일단 int 를 넘지는 않고

각각을 최소 하나씩 써야함   

음.. 그냥 모든 합을 first,second에 넣고 합을 구하는거는?

그냥 합을 다 저장했을 때는 {n(n-1) / 2} ^ 2 의 계산시간이라는 문제가 야기 됨

그럼 둘다 정렬을 하고 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t,n,m,tmp;
    long long answer = 0;
    
    vector<int> first;
    vector<int> second;

    cin>> t;
    
    cin>> n;
    for(int i = 0; i < n;i++){
        cin >> tmp;
        first.push_back(tmp);
    }

    cin>> m;
    for(int i = 0 ; i < m;i++){
        cin >> tmp;
        second.push_back(tmp);
    }

    for(int i = 0 ; i < n;i++){
        int sum = first[i];
        for(int j = i + 1; j < n ; j++){
            sum += first[j];
            first.push_back(sum);
        }
    }

    for(int i = 0 ; i < m;i++){
        int sum = second[i];
        for(int j = i + 1; j < m ; j++){
            sum += second[j];
            second.push_back(sum);
        }
    }

    // for(int i = 0 ; i < first.size();i++){
    //     for(int j = 0; j < second.size();j++){
    //         if(first[i] + second[j] == t)
    //             answer++;
    //     }
    // }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    for(int i = 0 ; i < first.size(); i++){
        int cnt = upper_bound(second.begin(),second.end(), t- first[i]) - lower_bound(second.begin(), second.end(), t- first[i]);
        answer += cnt;
    }

    cout<<answer;
}