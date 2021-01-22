#include<iostream>

using namespace std;

int N;
int operands[11];
int operators[4];
int mmin = 100000001;
int mmax = -1000000001;

void getanswer(int result, int idx) {

	if (idx == N) {
		if (result > mmax)
			mmax = result;
		if (result < mmin)
			mmin = result;
		return;
	}

	for (int i = 0;i < 4;i++) {

		if (operators[i] > 0) {

			// 연산자 개수 줄여줌
			operators[i]--;

			if (i == 0) 
				getanswer(result + operands[idx], idx + 1);
			else if (i == 1) 
				getanswer(result - operands[idx], idx + 1);
			else if (i == 2) 
				getanswer(result * operands[idx], idx + 1);
			else
				getanswer(result / operands[idx], idx + 1);

			// 다른 연산자를 사용할 것이므로 줄였던 연산자 개수 늘려줌
			operators[i]++;
		}
	}
	return;
}


int main() {
	cin >> N;

	// 숫자 입력
	for (int i = 0;i < N;i++) {
		cin >> operands[i];
	}

	// 연산자 개수 입력
	for (int i = 0;i < 4;i++) {
		cin >> operators[i];
	}

	// 함수 호출
	getanswer(operands[0], 1);
	cout << mmax << '\n';
	cout << mmin;

}