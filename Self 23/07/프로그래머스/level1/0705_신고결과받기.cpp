/*
신고 결과 받기

각 유저는 한번에 한명 신고 가능
k번이상 신고된 유저는 정지 메일 발송
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    map<string,int> m;
    vector<vector<int>> v(id_list.size(), vector<int>(id_list.size(),0)); //신고자
    
    for(int i = 0; i < id_list.size();i++){
        m[id_list[i]] = i;
    }
    
    for(int i = 0; i < report.size();i++){
        int active = 0; //신고자
        int passive = 0; //피신고자
        string activeUser = "";
        string passiveUser = "";
        int j = 0;
        int first = 1;
        while(j < report[i].length()){
            if(report[i][j] == ' '){
                first = 0;
                j++;
            }
            if(first)
                activeUser += report[i][j];
            else
                passiveUser += report[i][j];
            j++;
        }
        v[m[activeUser]][m[passiveUser]] = 1;
    }
    for(int i = 0; i < v.size();i++){
        int cnt = 0;
        for(int j = 0; j < v.size();j++){
            if(v[j][i] == 1){
                cnt++;
            }
        }
        if(cnt >= k){
            for(int j = 0; j < v.size();j++){
                if(v[j][i] == 1)
                    answer[j] ++;
            }
        }
    }
    return answer;
}