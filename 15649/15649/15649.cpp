#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, }; // 해당 숫자의 사용여부를 저장하기 위한 배열

void dfs(int cnt) {

	//숫자를 앞에서부터 한 개씩 뽑아가면서 visited 가 m 만큼 true 가 되면
	if (cnt == m) {

		// 한 줄에 m 까지만 출력
		for (int i = 0;i < m;i++) {
			cout << arr[i] << ' ';
		}
		// 끝나면 다음줄로 넘어가기
		cout << '\n';
		return;
	}

	// 재귀함수 이용
	for (int i = 1;i <= n;i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0);
}