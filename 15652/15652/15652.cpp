#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = { 0, };
int visited[MAX] = { 0, };

void dfs(int num,int cnt) {
	if (cnt == m) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 매개변수 넘겨주기
	// if(!visited[i]) 생략
	for (int i = num;i <= n;i++) {
		visited[i] = true;
		arr[cnt] = i;
		dfs(i, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	dfs(1,0);
}