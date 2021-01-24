#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9] = { 0, };
bool isused[9] = { 0, };

void func(int num,int k) {
	if (k == m) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// i=num 으로 시작해서 두번째 숫자는 반드시 첫번째 숫자보다 크도록
	// 세번째 숫자는 반드시 두번째 숫자보다 크도록 함
	for (int i = num;i <= n;i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = true;
			func(i + 1, k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	func(1,0);
}