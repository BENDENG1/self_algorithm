/*
비 내림차순으로 정렬된 수열 부분수열의 합은 k / 합이 k인 부분수열이 여러개인 경우 길이가 짧은 수열을 찾음
즉 비내림 차순이라는거는 뒤로 갈수록 점점 커진다는 뜻? 근데 같을 수도 있다는 의미인것 같음

합이 결국 커버리게 되면 하나씩 pos를 늘려주면서 계속 갱신을 한다. 
근데 길이가 더 짧아지게 된다면 -> 그래야 예시1,3번에 대한 해결 처리 가능
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int sum = 0,pos = 0;
    int length = 1000000;
    int start = 0,end = 0;
    
    for(int i =0;i<sequence.size();i++){
        sum += sequence[i];
        if(sum == k &&length > i - pos){
            start = pos;
            end = i;
            length = i - pos;
        }
        if(sum > k){
            while(sum > k){
                sum -= sequence[pos];
                pos++;
                if(sum == k && length > i - pos){
                    start = pos;
                    end = i;
                    length = i - pos;
                }
            }
        }
    }
    answer.push_back(start);
    answer.push_back(end);
    return answer;
}