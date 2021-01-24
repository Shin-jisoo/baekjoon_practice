#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[16] = { 0, };
int cnt = 0;

//back tracking 가지치기
bool check(int l) {

	//해당 열까지 for 문 사용
	for (int i = 0;i < l;i++) {
		//같은 행에 있거나, 대각선에 있는 경우 false
		if (arr[l] == arr[i] || abs(arr[l] - arr[i]) == l - i)
			return false;
	}

	//나머지 true
	return true;
}

void func(int k) {

	//완성된 경우 cnt 1증가
	if (k == n) {
		cnt++;
	}

	else {
		for (int i = 1;i <= n;i++) {
			//k 번째에 i 넣어주기
			arr[k] = i;

			//check 해서 true 인 경우 다음번째에 수 넣어주기
			if (check(k)) func(k + 1);
		}
	}
	}

int main() {
	cin >> n;
	func(0);

	cout << cnt;
}