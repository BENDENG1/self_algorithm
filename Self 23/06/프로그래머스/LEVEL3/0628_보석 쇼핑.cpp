#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> m;
    int start = 0; // 시작지점
    int end = 0; // 끝나는 지점
    int gemCount = 0; // 보석 현재 갯수
    int startAns, endAns; // 위치 임시 저장
    int len = 100000;

    // 보석 종류의 갯수 세기
    for (int i = 0; i < gems.size(); i++) {
        m[gems[i]] = 0;
    }
    int gemType = m.size(); // 보석의 종류 갯수

    while (1) {
        if (gemType == gemCount) {
            // 최소 길이인지 확인하고 갱신
            if (end - start < len) {
                startAns = start;
                endAns = end;
                len = end - start;
            }
            if (m[gems[start]] > 1) {
                m[gems[start]]--;
                start++;
            }
            else {
                m[gems[start]]--;
                start++;
                gemCount--;
            }
        }
        else {
            // 종류와 현재 갯수가 다를 때, end를 이동시키면서 현재 종류와 같아지도록 함
            if (end == gems.size())
                break;
            if (m[gems[end]] == 0)
                gemCount++;
            m[gems[end]]++;
            end++;
        }
    }

    answer.push_back(startAns + 1);
    answer.push_back(endAns);

    return answer;
}
