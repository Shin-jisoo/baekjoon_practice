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

	// �񳻸������̹Ƿ� num �ڸ��� i �־��ֱ�
	for (int i=num;i <= n;i++) {
		arr[k] = i;
		func(i,k + 1);
	}
}

int main() {
	cin >> n >> m;
	func(1,0);
}