/*
우박수열 정적분

짝수라면 2로 나눔 홀수라면 3곱하고 1더함

정적분 [a,b]
x = a, x=b, y= 0 / x=a, x=n-b, y=0
5라고 치면 0,5/1,16../5,1에 점이 찍히는 그래프 
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> v;
    int n;
    
    v.push_back(k);
    while(k != 1){
        if(k % 2 == 0){
            k /= 2;
            v.push_back(k);
        }else{
            k = (3 * k) + 1;
            v.push_back(k);
        }
        
    }
    n = v.size() - 1;
    for(int i = 0 ; i < ranges.size();i++){
        int start = ranges[i][0];
        int end = n + ranges[i][1];
        
        if(start < 0 || start > end)
            answer.push_back(-1.0);
        else if(start == end)
                answer.push_back(0.0);
        else{
            double sum = 0;
            for(int j = start; j <= end;j++){
                if(j == start || j == end){
                    sum += v[j];
                }else{
                    sum += (v[j] * 2);
                }
            }
            answer.push_back(sum / 2.0);
        }
    }
    return answer;
}