#include <iostream>
#include <cmath>
#include <stdio.h>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// �� �Լ�
int compare(const pair<int, int>& a, const pair<int, int>& b) {

	// y ��ǥ�� ���� ��� x ��ǥ�� �������� ��������
	if (a.second == b.second) return a.first < b.first;

	// �ƴ� ��� y ��ǥ �������� ��������
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;

	pair<int, int>arr[100000];

	for (int i = 0;i < n;i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	// �� �Լ� �̿��Ͽ� ����
	sort(arr, arr + n, compare);

	for (int i = 0;i < n;i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}

	return 0;
}