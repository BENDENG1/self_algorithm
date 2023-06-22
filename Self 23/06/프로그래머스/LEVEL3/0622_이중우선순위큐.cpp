/*
이중우선순위큐

| 숫자 -> 큐에 숫자 삽입 // D 1 최댓값 삭제 D -1 최솟값 삭제

[최대,최소] 단 비어있으면 [0,0] return

*/
#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> down_pq; //내림차순 pq
    priority_queue<int,vector<int>, greater<int>> up_pq; //오름차순 pq
    int pqsize = 0;
    
    for(int i = 0; i < operations.size();i++){
        if(pqsize == 0){
            while(!up_pq.empty())
                up_pq.pop();
            while(!down_pq.empty())
                down_pq.pop();
        }
        if(operations[i][0] == 'I'){
            down_pq.push(stoi(operations[i].substr(2)));
            up_pq.push(stoi(operations[i].substr(2)));
            pqsize++;
        }else if (operations[i][0] == 'D' && pqsize > 0){ //삭제할때 들어온것에 대해서 처리해야함
            if(operations[i][2] == '-'){ //최솟값 삭제
                up_pq.pop();
            }else{ //최댓값삭제
                down_pq.pop();
            }
            pqsize--;
        }
    }
    
    //pqsize가 0보다 크다는 것은 존재하는것임
    if(pqsize > 0){
        answer.push_back(down_pq.top());
        answer.push_back(up_pq.top());
    }else{
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}