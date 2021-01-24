#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; // 입력 받을 수
int arr[10] = { 0, }; // 수열을 담을 배열
bool isused[10] = { 0, }; // 특정 수가 쓰였는지 확인

// 현재 k까지의 수를 택한 상황에서 arr[k]를 정하는 함수
void func(int k) {

	// m 개를 모두 골랐다면 출력 후 종료
	if (k == m) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return; // 되돌아가기
	}


	for (int i = 1;i <= n;i++) {
		if (!isused[i]) { // 중복이 없어야 하므로 해당 숫자를 쓰지 않았다면
			arr[k] = i; // k 번째에 해당 숫자 넣어주기
			isused[i] = true; // 사용했으므로 true로 바꿔주기
			func(k + 1); // 그 다음 숫자 선택하기 위해 func 함수 호출
			isused[i] = false; // 모두 고른 후 되돌아갈때 해당 숫자 false로 바꿔주기
		}
	}

}

int main(void) {

	// 시간 줄이기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);


	// 입력
	cin >> n >> m;
	// 첫번째 숫자를 선택하기 위해 func(0)호출
	func(0);
}