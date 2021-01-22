#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, total = 0;

// level 은 현재 몇번째 행을 채우고 있는지 기록
bool check(int level) {
	for (int i = 0;i < level;i++)

		if (col[i] == col[level] // 새로운 퀸과 기존의 퀸이 같은 행에 있거나
			|| abs(col[level] - col[i]) == level - i) // 대각선에 있는 경우
			return false; // false

		return true; // 아닌 경우 true
	
}

void nqueen(int x) {

	// 마지막에는 total 하나 올려주고 끝
	if (x == N)
		total++;

	else {
		for (int i = 0;i < N;i++) {
			col[x] = i; // 퀸의 좌표 지정
			if (check(x)) // true 인 경우 자리 배치
				nqueen(x + 1); // 다음 퀸의 자리 지정하기 위한 재귀함수 호출
			                   // 유효하지 않다면 다른 위치로 배치
		}
	}
}

int main() {
	cin >> N;
	nqueen(0);
	cout << total;
}