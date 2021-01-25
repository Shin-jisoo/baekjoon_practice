#include <iostream>

using namespace std;
int n;
int num[11];
int op[4]; //+,-,*,/
int MIN = 1000000000;
int MAX = -1000000000;


void func(int result,int count) {

	//��� ����� result �� ���ִ�
	if (count == n - 1) {
		if (MIN > result)
			MIN = result;
		if (MAX < result)
			MAX = result;
		return;
	}

	for (int i = 0;i < 4;i++) {
		//����ϰ� ���� �������� ī��Ʈ�� �����ִٸ�
		if (op[i] != 0) {
			--op[i];
			////////
			if (i == 0) {
				//������� ���� ���� �����ֱ�, count 1����
				func(result + num[count + 1], count + 1);
			}
			else if (i == 1) {
				func(result - num[count + 1], count + 1);
			}
			else if (i == 2) {
				func(result * num[count + 1], count + 1);
			}
			else {
				func(result / num[count + 1], count + 1);
			}

			++op[i];
		}
	}
}


int main() {

	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> num[i];
	}

	for (int i = 0;i < 4;i++) {
		cin >> op[i];
	}

	func(num[0], 0);
	cout << MAX << '\n';
	cout << MIN;
}