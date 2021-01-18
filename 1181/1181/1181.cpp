#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a,b 의 길이를 비교하고 길이를 오름차순 정렬하는 함수
bool com(string a, string b) {
	if (a.length() == b.length())return a < b;
	return a.length() < b.length();
}

int main() {
	// 단어의 개수
	int n;
	cin >> n;
	
	vector<string>v;
	
	for (int i = 0;i < n;i++) {
		string str;
		cin >> str;

		// 입력한 문장이 vector 안에 있는 문장과 겹치지 않을경우
		// (= vector 의 end 인경우)
		if (find(v.begin(), v.end(), str) == v.end()) {

			// vector 안에 넣어 주기
			v.push_back(str);
		}

	}

	// vecotr 를 com 함수로 정렬
	sort(v.begin(), v.end(), com);

	//출력
	for (int i = 0;i < v.size();i++) {
		cout << v[i] << "\n";
	}

}