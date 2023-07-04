#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int> stones, int mid, int k){
    int cnt = 0;
    for(int i = 0; i < stones.size();i++){
        if(stones[i] < mid)
            cnt++;
        else
            cnt = 0;
        if(cnt >= k) return -1;
    }
    return 1;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int start = 0;
    int end = *max_element(stones.begin(),stones.end());
    
    while(start <= end){
        int mid = (start + end) / 2;
        if(search(stones,mid,k) == 1){
            start = mid + 1;
            if(answer < mid)
                answer = mid;
        }else
            end = mid -1;
    }
    return answer;
}