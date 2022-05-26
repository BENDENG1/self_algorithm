/*
주기의 길이가 P 이면, N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째 피보나치 수를 M을 나눈 나머지와 같습니다.

M = 10^k 일 때, k > 2 라면, 주기는 항상 15 × 10^(k-1) 입니다. 이 사실을 모른다고 해도, 주기를 구하는 코드를 이용해서 문제를 풀 수 있습니다.

이 문제에서 M = 10^6 이기 때문에, 주기는 15 × 10^5 = 1500000가 되겠네요.
이런 개 억지 문제가 있다늬.. fuck..
*/


#include<iostream>

using namespace std;
long long arr[1500050];
int MAX = 1000000;
 
void fibonacci() {
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 0; i < 1500000; i++) {
        arr[i + 2] = (arr[i + 1] + arr[i]) % MAX;
    }
}
 
int main() {
    long long n;
    cin >> n;
    fibonacci();
    cout << arr[n%1500000] << "\n";
 
}