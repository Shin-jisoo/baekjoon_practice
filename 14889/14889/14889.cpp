#include<iostream>
#define MAX 100

using namespace std;

int arr[MAX][MAX] = { 0, };

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}
}