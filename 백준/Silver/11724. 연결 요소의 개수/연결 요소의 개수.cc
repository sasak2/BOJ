#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int UnF[1010];

int Find(int a) {
	if (UnF[a] == a) return a;
	return Find(UnF[a]);
}

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		UnF[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		UnF[Find(max(a, b))] = Find(min(a, b));
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (UnF[i] == i)
			cnt++;

	}
	printf("%d", cnt);
	

	return 0;
}