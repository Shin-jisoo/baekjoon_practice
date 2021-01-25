#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int arr[9][9];
vector<pair<int, int>>p;
bool found=false;
int cnt = 0;

bool check(pair<int, int>po) {
	int group_x = po.first / 3;
	int group_y = po.second / 3;


	for (int i = 0;i < 9;i++) {
		//같은 행에 같은 숫자가 있을 경우
		if (arr[i][po.second] == arr[po.first][po.second] && i != po.first)
			return false;

		//같은 열에 같은 숫자가 있을 경우
		if (arr[po.first][i] == arr[po.first][po.second] && i != po.second)
			return false;
	}

	//같은 그룹 안에 같은 숫자가 있을 경우
	for (int i = 3 * group_x;i < 3 * group_x + 3;i++) {
		for (int j = 3 * group_y;j < 3 * group_y + 3;j++) {
			if (arr[i][j] == arr[po.first][po.second]) {
				if (i != po.first && j != po.second)
					return false;
			}
		}
	}

	return true; //모두 아닌 경우 true
}

void func(int k) {
	
	//0의 개수만큼 다 채웠을 경우
	if (k == cnt) {
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				//출력
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}

		//완성 되었다고 표시
		found = true;
		return;
	}

	for (int j = 1;j <= 9;j++) {

		//1~9 다 넣어보기
		arr[p[k].first][p[k].second] = j;

		//조건을 다 통과할 경우 다음 번째로 넘어가기
		if (check(p[k]))
			func(k + 1);

		//끝났을 경우 종료
		if (found)
			return;
	}

	//최적해를 못찾을 경우 종료
	arr[p[k].first][p[k].second] = 0;
	return;
}

int main() {

	pair<int, int>pp;

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {

				//0의 개수 카운트
				cnt++;
				pp.first = i;
				pp.second = j;
				p.push_back(pp);
			}
		}
	}

	func(0);
}