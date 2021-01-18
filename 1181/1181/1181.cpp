#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a,b �� ���̸� ���ϰ� ���̸� �������� �����ϴ� �Լ�
bool com(string a, string b) {
	if (a.length() == b.length())return a < b;
	return a.length() < b.length();
}

int main() {
	// �ܾ��� ����
	int n;
	cin >> n;
	
	vector<string>v;
	
	for (int i = 0;i < n;i++) {
		string str;
		cin >> str;

		// �Է��� ������ vector �ȿ� �ִ� ����� ��ġ�� �������
		// (= vector �� end �ΰ��)
		if (find(v.begin(), v.end(), str) == v.end()) {

			// vector �ȿ� �־� �ֱ�
			v.push_back(str);
		}

	}

	// vecotr �� com �Լ��� ����
	sort(v.begin(), v.end(), com);

	//���
	for (int i = 0;i < v.size();i++) {
		cout << v[i] << "\n";
	}

}