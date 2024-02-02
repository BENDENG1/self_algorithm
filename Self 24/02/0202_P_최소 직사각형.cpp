/*
최소 직사각형

엥 걍 백터 sort하면 되는거 아닌가 최소 너비니깐 ㅇㅇ
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = 0;
    int height = 0;
    
    for(int i = 0 ; i < sizes.size();i++){
        sort(sizes[i].begin(), sizes[i].end());
        if(sizes[i][0] > width)
            width = sizes[i][0];
        if(sizes[i][1] > height)
            height = sizes[i][1];
    }
    return height * width;
}