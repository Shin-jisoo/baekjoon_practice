#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; // �Է� ���� ��
int arr[10] = { 0, }; // ������ ���� �迭
bool isused[10] = { 0, }; // Ư�� ���� �������� Ȯ��

// ���� k������ ���� ���� ��Ȳ���� arr[k]�� ���ϴ� �Լ�
void func(int k) {

	// m ���� ��� ����ٸ� ��� �� ����
	if (k == m) {
		for (int i = 0;i < m;i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return; // �ǵ��ư���
	}


	for (int i = 1;i <= n;i++) {
		if (!isused[i]) { // �ߺ��� ����� �ϹǷ� �ش� ���ڸ� ���� �ʾҴٸ�
			arr[k] = i; // k ��°�� �ش� ���� �־��ֱ�
			isused[i] = true; // ��������Ƿ� true�� �ٲ��ֱ�
			func(k + 1); // �� ���� ���� �����ϱ� ���� func �Լ� ȣ��
			isused[i] = false; // ��� �� �� �ǵ��ư��� �ش� ���� false�� �ٲ��ֱ�
		}
	}

}

int main(void) {

	// �ð� ���̱� ����
	ios::sync_with_stdio(0);
	cin.tie(0);


	// �Է�
	cin >> n >> m;
	// ù��° ���ڸ� �����ϱ� ���� func(0)ȣ��
	func(0);
}