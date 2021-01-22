#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, total = 0;

// level �� ���� ���° ���� ä��� �ִ��� ���
bool check(int level) {
	for (int i = 0;i < level;i++)

		if (col[i] == col[level] // ���ο� ���� ������ ���� ���� �࿡ �ְų�
			|| abs(col[level] - col[i]) == level - i) // �밢���� �ִ� ���
			return false; // false

		return true; // �ƴ� ��� true
	
}

void nqueen(int x) {

	// ���������� total �ϳ� �÷��ְ� ��
	if (x == N)
		total++;

	else {
		for (int i = 0;i < N;i++) {
			col[x] = i; // ���� ��ǥ ����
			if (check(x)) // true �� ��� �ڸ� ��ġ
				nqueen(x + 1); // ���� ���� �ڸ� �����ϱ� ���� ����Լ� ȣ��
			                   // ��ȿ���� �ʴٸ� �ٸ� ��ġ�� ��ġ
		}
	}
}

int main() {
	cin >> N;
	nqueen(0);
	cout << total;
}