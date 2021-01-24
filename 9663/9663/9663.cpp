#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int vx[16], vy[16];

int go(int y, int x) {

	for (int i = 0;i < y;i++) {
		if (x == vx[i]) return 0; //¼¼·Î³¢¸® °ãÄ§
		if (y == vy[i]) return 0; //°¡·Î³¢¸® °ãÄ§
		if (abs(x - vx[i]) == abs(y - vy[i])) return 0; //´ë°¢¼± °ãÄ§
	}

	//Á¾·á Á¶°Ç
	if (y == N - 1) {
		return 1;
	}

	vx[x] = x;
	vy[y] = y;

	int r = 0;
	for (int i = 0;i < N;i++) {
		r += go(y + 1, i);
	}
	return r;
}

int main() {
	cin >> N;
	//scanf("%d", &N);

	int r = 0;
	for (int i = 0;i < N;i++) {
		r += go(0, i);
	}

	cout << r;
	return 0;
}