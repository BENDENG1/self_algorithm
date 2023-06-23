/*
남은 일의 작업량을 제곱하여 더함 -> 피로도

제곱의 합을 더하는 건데 결국 가장 평균에 가깝게 숫자들을 빼면 되는것.
*/
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a>b;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int workSum = 0;
    
    
    for(int i = 0; i < works.size();i++)
        workSum += works[i];
    if(workSum <= n)
        return 0;
    
    sort(works.begin(),works.end(),compare); // 역순 정렬
    // 9 9 9 8 8 7 6 2 2 1
    int idx = 0;
    while(n > 0){
        if(works[idx] <= works[idx + 1]){
            idx++;
        }else{
            for(int i = 0; i <= idx; i ++){
                if(n >0){
                    works[i]--;
                    n--;
                }
            }
        }
    }
    
    for(int i = 0; i < works.size();i++)
        answer += pow(works[i], 2);
    return answer;
}