#include<iostream>
#include<string.h>
using namespace std;
int arr[10001];
int get_max(int a, int b) { return a > b ? a : b; }

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, tmp;
	cin >> n;

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp] += 1;
	}

	for (int i = 0; i <= 10000; i++) {
		if (arr[i] != 0) {
			while (arr[i] != 0) {
				cout << i << "\n";
				arr[i] -= 1;
			}
		}
	}
}