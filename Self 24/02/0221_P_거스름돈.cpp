/*
거스름돈

걍 다 구하면 되는거 아닌가?

아니 걍 dp 아님?

내야핼 금액 = (내야핼 금액 - 거스름돈) + 거스름돈 -> 거스름돈의 종류가 되는거네 
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    int arr[100001] = {0,};
    sort(money.begin(),money.end());
    arr[0] = 1;
    
    for(int i = 0; i < money.size();i++){
        for(int j = money[i]; j <= n; j++){
            arr[j] += arr[j - money[i]];
            arr[j] %= 1000000007;
        }
    }
    
    return arr[n] % 1000000007;
}