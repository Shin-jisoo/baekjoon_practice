#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = { 0, };
int visited[MAX] = { 0, }; // 사용되었는지 확인하기 위한 배열

void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 두번째 숫자는 반드시 첫번째 숫자보다 크도록, 세번째 숫자는 반드시 두번쨰 숫자보다 크도록 설정
	for (int i = num;i <= n;i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;

			// 현재 뽑은 원소이 인전 값들은 고려하지 않게끔, for문의 i값을 함께 넘겨줌
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}