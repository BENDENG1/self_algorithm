#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<string,int>&a, pair<string,int>&b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int len = genres.size();
    
    map<string,int> m; //장르이름, 합 저장
    vector<pair<string,int>> v;
    map<string,pair<int,int>> first; // plays[인덱스]와 인덱스
    map<string,pair<int,int>> second; // 동일
    
    
    for(int i = 0; i < len;i++){
        if(first[genres[i]].first == 0) // 처음일때
            first[genres[i]] = {plays[i],i};
        else if(second[genres[i]].first == 0){ //두번째일때
            if(plays[i] >first[genres[i]].first){
                second[genres[i]] = first[genres[i]];
                first[genres[i]] = {plays[i],i};
            }
            else{
                second[genres[i]] = {plays[i],i};
            }
        }else{
            if(plays[i] > first[genres[i]].first){
                second[genres[i]] = first[genres[i]];
                first[genres[i]] = {plays[i], i};
            }else if(second[genres[i]].first < plays[i] &&plays[i]<=first[genres[i]].first){
                second[genres[i]] = {plays[i],i};
            }
            //작은 경우 무시
        }
        m[genres[i]] += plays[i];
    }
    
    for(const auto& pair : m){
        v.push_back(pair);
    }
    
    sort(v.begin(),v.end(),compare);
    
    for(int i = 0; i < v.size();i++){
        answer.push_back(first[v[i].first].second);
        if(second[v[i].first].first != 0){
            answer.push_back(second[v[i].first].second);
        }
    }
    
    return answer;
}