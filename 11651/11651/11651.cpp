#include <iostream>
#include <cmath>
#include <stdio.h>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 비교 함수
int compare(const pair<int, int>& a, const pair<int, int>& b) {

	// y 좌표가 같을 경우 x 좌표를 기준으로 내림차순
	if (a.second == b.second) return a.first < b.first;

	// 아닌 경우 y 좌표 기준으로 내림차순
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;

	pair<int, int>arr[100000];

	for (int i = 0;i < n;i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	// 비교 함수 이용하여 정렬
	sort(arr, arr + n, compare);

	for (int i = 0;i < n;i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}

	return 0;
}