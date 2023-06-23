/*
단어 변환

한번에 한개의 알파벳만 words에 있는 단어로만 변환 o

최소 몇단계를 과정을 거쳐서 변환할 수 있는지에 대해서 하는 것이니 bfs를 사용해보자.
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<int,string>> q; //횟수, word
    
    int visited[50]={0,};
    q.push({0,begin});
    
    while(!q.empty()){
        int cnt = q.front().first;
        string name = q.front().second;
        
        q.pop();
        
        if(name == target)
            return cnt;
        
        for(int i = 0; i < words.size();i++){
            int diff = 0;
            for(int j = 0; j < name.length();j++){
                if(name[j] != words[i][j])
                    diff++;
            }
            if(diff == 1 && visited[i] == 0){
                visited[i] = 1;
                q.push({cnt + 1,words[i]});
            }
        }
    }
    return answer;
}