#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[16] = { 0, };
int cnt = 0;

//back tracking ����ġ��
bool check(int l) {

	//�ش� ������ for �� ���
	for (int i = 0;i < l;i++) {
		//���� �࿡ �ְų�, �밢���� �ִ� ��� false
		if (arr[l] == arr[i] || abs(arr[l] - arr[i]) == l - i)
			return false;
	}

	//������ true
	return true;
}

void func(int k) {

	//�ϼ��� ��� cnt 1����
	if (k == n) {
		cnt++;
	}

	else {
		for (int i = 1;i <= n;i++) {
			//k ��°�� i �־��ֱ�
			arr[k] = i;

			//check �ؼ� true �� ��� ������°�� �� �־��ֱ�
			if (check(k)) func(k + 1);
		}
	}
	}

int main() {
	cin >> n;
	func(0);

	cout << cnt;
}