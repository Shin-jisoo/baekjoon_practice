#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8] = { 0, };
//bool isused[8] = { 0, };

void func(int num,int k) {
	if (k == m) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 비내림차순이므로 num 자리에 i 넣어주기
	for (int i=num;i <= n;i++) {
		arr[k] = i;
		func(i,k + 1);
	}
}

int main() {
	cin >> n >> m;
	func(1,0);
}