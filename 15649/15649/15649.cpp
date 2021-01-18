#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, }; // �ش� ������ ��뿩�θ� �����ϱ� ���� �迭

void dfs(int cnt) {

	//���ڸ� �տ������� �� ���� �̾ư��鼭 visited �� m ��ŭ true �� �Ǹ�
	if (cnt == m) {

		// �� �ٿ� m ������ ���
		for (int i = 0;i < m;i++) {
			cout << arr[i] << ' ';
		}
		// ������ �����ٷ� �Ѿ��
		cout << '\n';
		return;
	}

	// ����Լ� �̿�
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