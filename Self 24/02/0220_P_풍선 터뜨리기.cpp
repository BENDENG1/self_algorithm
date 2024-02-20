/*
풍선 터트리기

n개의 풍선 
1. 인접 두개중 하나 터트림
2. 공간이 생기면 밀착 시킴

번호가 더 작은 풍선 터트리기 최대 1번

최후까지 남기는 것이 가능한 풍선들의 개수를 return

음.. 어떻게 해야할까

1. 해당하는 숫자가 인접하는 것중에 살아 남으려면 -> 일단은 중간 혹은 가장 작아야함
2. 중간인 경우 이제 앞으로 다 터트렸을 때 가장 낮은 숫자가 해당 숫자보다 커야함 (즉, 남은 벡터 중에서 가장 작아야함)
3. 작은 경우 가장 작은 숫자가 터트려서 남았다고 전제하에

음 그냥 결국 가장 작은 숫자 두개를 자기 기준 오른쪽 왼쪽에 남겨두고 가장 크면 안되는거고 되면 되는거 아닌가
-> 시간 초과

그치 결국 1000000 * 1000000 이니깐 시간초과가 무조건 나지

dp로 값들중에 최소값을 계속 갱신해 나가는것은?
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> left;
    vector<int> right;
    
    if(a.size() <= 2){
        return a.size();
    }
    
    left = a;
    right = a;
    
    for(int i = 1 ; i < a.size(); i++){
        if(left[i] >= left[i-1]){
            left[i] = left[i-1];
        }
    }
    
    for(int i = a.size() - 2; i >= 0; i--){
        if(right[i] >= right[i+1]){
            right[i] = right[i+1];
        }
    }
    
    //양옆 끝은 어떤 숫자라도 다 터트려버리고 크든 작으던 상관없음 그래서 걍 answer +=2 하면 됨
    answer +=2;
    for(int i = 1 ; i < a.size() - 1;i++){
        if(max({a[i],left[i-1],right[i+1]}) != a[i]){
            answer++;
        }
    }
    
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MAX = 1000000000;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> v(0,a.size());
    
    for(int i = 0 ; i < a.size(); i ++){
        int leftMin = MAX;
        int rightMin = MAX;
        for(int j = 0; j < i;j++){
            if(a[j] < leftMin)
                leftMin = a[j];
        }
        for(int j = i + 1; j<a.size(); j++){
            if(a[j] < rightMin)
                rightMin = a[j];
        }
        if(max({a[i], leftMin, rightMin}) != a[i])
            answer++;
    }
    
    
    return answer;
}
*/