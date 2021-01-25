#include <iostream>

using namespace std;
int n;
int num[11];
int op[4]; //+,-,*,/
int MIN = 1000000000;
int MAX = -1000000000;


void func(int result,int count) {

	//모든 결과가 result 에 들어가있다
	if (count == n - 1) {
		if (MIN > result)
			MIN = result;
		if (MAX < result)
			MAX = result;
		return;
	}

	for (int i = 0;i < 4;i++) {
		//사용하고 싶은 연산자의 카운트가 남아있다면
		if (op[i] != 0) {
			--op[i];
			////////
			if (i == 0) {
				//결과값에 다음 항을 더해주기, count 1증가
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