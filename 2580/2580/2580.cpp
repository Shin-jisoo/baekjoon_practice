#include <iostream>
#include <utility>
#include <vector>
#define MAX 9

using namespace std;

int arr[MAX][MAX];
vector<pair<int, int>> points;
int cnt = 0;
bool found=false;

bool check(pair<int, int>p) {
	
	//3x3 으로 구간 나누기
	int square_x = p.first / 3;
	int square_y = p.second / 3;

	for (int i = 0;i < MAX;i++) {
		//같은 열 검사
		if (arr[p.first][i] == arr[p.first][p.second] && i != p.second)
			return false;
		//같은 행 검사
		if (arr[i][p.second] == arr[p.first][p.second] && i != p.first)
			return false;
	}

	//구간 안에서 검사
	for (int i = 3 * square_x;i < 3 * square_x + 3;i++) {
		for (int j = 3 * square_y;j < 3 * square_y + 3;j++) {
			if (arr[i][j] == arr[p.first][p.second]) {
				if (i != p.first && j != p.second) {
					return false;
				}
			}
		}
	}

	return true;
}

void sudoku(int N) {

	//0을 다 채웠다면 출력
	if(N == cnt) {
		for (int i = 0;i < MAX;i++) {
			for (int j = 0;j < MAX;j++) {
				cout << arr[i][j];
				if (j != 8) {
					cout << " ";
				}
			}
			cout << '\n';
		}

		//완성여부 ture 로 바꾸기
		found = true;
		return;
	}
	
	//해당 칸에 1~9 까지 넣어보기
	for (int j = 1;j <= MAX;j++) {
		arr[points[N].first][points[N].second] = j;

		// check 함수에서 확인 후 true 를 반환하면
		if (check(points[N]))

			//다음 0 의 위치에 숫자를 넣어주기 위해 재귀함수 호출
			sudoku(N + 1);

		// 완성하면 끝내기
		if (found)
			return;
	}

	// 못찾으면 비워두기
	arr[points[N].first][points[N].second] = 0;
	return;
}

int main() {
	pair<int, int>p;
	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 0) {
				cnt++;
				p.first = i;
				p.second = j;
				points.push_back(p);
			}
		}
	}

	sudoku(0);
}