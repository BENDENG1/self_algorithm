#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = 2 * w + 1;
    int idx = 1;
    
    for(int i = 0; i < stations.size();i++){
        if(idx < stations[i] - w){
            while(idx < stations[i] - w){
                idx = idx + range;
                answer++;
            }
            idx = stations[i] + w + 1;
        }else{
            idx = stations[i] + w + 1;
        }
    }
    
    while(idx <= n){
        idx += range;
        answer++;
    }

    return answer;
}