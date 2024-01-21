/*
행렬 테두리 회전하기

시계 방향으로 회전 하려함

회전에 의해 한칸씩 회전을 함 -> 가장 작은 숫자들을 순서대로 배열

이동한 숫자 중 가장 최솟값을 구하면 됨
그냥 숫자만 이동하면 되는거 아닌가?

그냥 이걸 이차원으로 생각하지말고 2차원을 1차원으로 만들고 회전시킨다면?
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> v;
int minNumber;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    
    //행렬에 따른 행렬 생성
    for(int i = 0 ; i < rows;i++){
        vector<int> tmpVector;
        for(int j = 0; j < columns; j++){
            tmpVector.push_back((i * columns)+ 1+ j);
        }
        v.push_back(tmpVector);
    }
    
    //queries에 대한 최솟값 찾기
    for(int i =0;i < queries.size(); i++){
        int startY = queries[i][0] - 1;
        int startX = queries[i][1] - 1;
        int endY = queries[i][2] - 1;
        int endX = queries[i][3] - 1;

        minNumber = 10000;
        vector<int> tmpVector;
        
        //2차원을 1차원이라고 생각하고 그다음 한칸씩 밀면됨
        for(int x = startX; x < endX; x++){
            tmpVector.push_back(v[startY][x]);
        }
        for(int y = startY; y < endY ; y++){
            tmpVector.push_back(v[y][endX]);
        }
        for(int x = endX; startX < x; x--){
            tmpVector.push_back(v[endY][x]);
        }
        for(int y = endY; startY < y; y--){
            tmpVector.push_back(v[y][startX]);
        }
        
        //1차원으로 만든후 회전
        int lastElement = tmpVector.back();
        tmpVector.pop_back();
        tmpVector.insert(tmpVector.begin(),lastElement);
        for(int j = 0 ; j < tmpVector.size();j++){
            minNumber = tmpVector[j] < minNumber ? tmpVector[j] : minNumber;
        }
        answer.push_back(minNumber);
        
        //회전한 1차원 배열을 행렬에 다시 값 넣기 
        int idx = 0;
        for(int x = startX; x < endX; x++){
            v[startY][x] = tmpVector[idx++];
        }
        for(int y = startY; y < endY ; y++){
            v[y][endX] = tmpVector[idx++];
        }
        for(int x = endX; startX < x; x--){
            v[endY][x] = tmpVector[idx++];
        }
        for(int y = endY; startY < y; y--){
            v[y][startX] = tmpVector[idx++];    
        }
    }
    
    return answer;
}