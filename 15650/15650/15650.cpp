#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = { 0, };
int visited[MAX] = { 0, }; // ���Ǿ����� Ȯ���ϱ� ���� �迭

void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// �ι�° ���ڴ� �ݵ�� ù��° ���ں��� ũ����, ����° ���ڴ� �ݵ�� �ι��� ���ں��� ũ���� ����
	for (int i = num;i <= n;i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;

			// ���� ���� ������ ���� ������ ������� �ʰԲ�, for���� i���� �Բ� �Ѱ���
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}