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
	
	//3x3 ���� ���� ������
	int square_x = p.first / 3;
	int square_y = p.second / 3;

	for (int i = 0;i < MAX;i++) {
		//���� �� �˻�
		if (arr[p.first][i] == arr[p.first][p.second] && i != p.second)
			return false;
		//���� �� �˻�
		if (arr[i][p.second] == arr[p.first][p.second] && i != p.first)
			return false;
	}

	//���� �ȿ��� �˻�
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

	//0�� �� ä���ٸ� ���
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

		//�ϼ����� ture �� �ٲٱ�
		found = true;
		return;
	}
	
	//�ش� ĭ�� 1~9 ���� �־��
	for (int j = 1;j <= MAX;j++) {
		arr[points[N].first][points[N].second] = j;

		// check �Լ����� Ȯ�� �� true �� ��ȯ�ϸ�
		if (check(points[N]))

			//���� 0 �� ��ġ�� ���ڸ� �־��ֱ� ���� ����Լ� ȣ��
			sudoku(N + 1);

		// �ϼ��ϸ� ������
		if (found)
			return;
	}

	// ��ã���� ����α�
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