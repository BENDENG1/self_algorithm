/*
입국 심사

n명이 입국심사

모든 사람이 받는데 걸리는 최소시간

입국심사를 기다리는 사람수 n / 시간 times

걍 이분탐색

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    
    long long start = 1;
    long long end =(long long) n * times.back();
    long long mid;
    long long search;
    
    while(start <= end){
        mid = (start + end) / 2;
        search = 0;
        
        for(int i = 0; i < times.size(); i++){
            search += (mid / (long long) times[i]);
        }
        
        if(search >= n){
            end = mid - 1;
            answer = mid;
        }
        else{
            start = mid + 1;
        }
    }
    return answer;
}