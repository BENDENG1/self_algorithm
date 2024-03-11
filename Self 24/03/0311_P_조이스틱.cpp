/*
조이스틱

A로만 이루어졌는데
다음,이전,커서를 왼쪽 오른쪽

ABCDE FGHIJ KLMNO PQRST UVWXY Z
처음 중간은 N 13번걸림

26개에 대해서 ㅇㅇ

*/

#include <string>
#include <vector>

using namespace std;

int alphabet[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,
                    12,11,10,9,8,7,6,5,4,3,2,1,};

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int move = len - 1;
    
    for(int i = 0; i < len;i++){
        if(name[i] -'A' < 14)
            answer += name[i] - 'A';
        else
            answer += 'Z' - name[i] + 1;
        
        int idx = i + 1;
        while(idx < len && name[idx] == 'A')
            idx++;
        
        move = min(move, i + len - idx + min(i,len - idx));
    }
    answer += move;
    
    return answer;
}