#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 나이가 적은 수부터 차례로 정렬하는 함수
bool com(pair<int,string> a,pair<int,string> b) {
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;

	pair<int, string>p;
	vector<pair<int, string>>v;

	// 나이, 이름 순으로 저장
	for (int i = 0;i < n;i++) {
		cin >> p.first >> p.second;

		v.push_back(p);
	}

	// 안정정렬
	stable_sort(v.begin(), v.end(), com);

	//출력
	for (int i = 0;i < n;i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}