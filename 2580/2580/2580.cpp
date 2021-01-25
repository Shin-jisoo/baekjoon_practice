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
		//���� �࿡ ���� ���ڰ� ���� ���
		if (arr[i][po.second] == arr[po.first][po.second] && i != po.first)
			return false;

		//���� ���� ���� ���ڰ� ���� ���
		if (arr[po.first][i] == arr[po.first][po.second] && i != po.second)
			return false;
	}

	//���� �׷� �ȿ� ���� ���ڰ� ���� ���
	for (int i = 3 * group_x;i < 3 * group_x + 3;i++) {
		for (int j = 3 * group_y;j < 3 * group_y + 3;j++) {
			if (arr[i][j] == arr[po.first][po.second]) {
				if (i != po.first && j != po.second)
					return false;
			}
		}
	}

	return true; //��� �ƴ� ��� true
}

void func(int k) {
	
	//0�� ������ŭ �� ä���� ���
	if (k == cnt) {
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				//���
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}

		//�ϼ� �Ǿ��ٰ� ǥ��
		found = true;
		return;
	}

	for (int j = 1;j <= 9;j++) {

		//1~9 �� �־��
		arr[p[k].first][p[k].second] = j;

		//������ �� ����� ��� ���� ��°�� �Ѿ��
		if (check(p[k]))
			func(k + 1);

		//������ ��� ����
		if (found)
			return;
	}

	//�����ظ� ��ã�� ��� ����
	arr[p[k].first][p[k].second] = 0;
	return;
}

int main() {

	pair<int, int>pp;

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {

				//0�� ���� ī��Ʈ
				cnt++;
				pp.first = i;
				pp.second = j;
				p.push_back(pp);
			}
		}
	}

	func(0);
}