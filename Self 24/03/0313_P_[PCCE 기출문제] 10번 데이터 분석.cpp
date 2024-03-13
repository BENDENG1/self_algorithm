#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int sortNum;

bool cmp(const vector<int> &a, const vector<int> &b){
    return a[sortNum] < b[sortNum];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string,int> m = {{"code",0}, {"date",1},{"maximum",2},{"remain",3}};
    
    for(int i = 0 ; i < data.size() ; i++){
        if(data[i][m[ext]] < val_ext){
            answer.push_back(data[i]);
        }
    }
    
    sortNum = m[sort_by];
    sort(answer.begin(),answer.end(),cmp);
    
    return answer;
} 