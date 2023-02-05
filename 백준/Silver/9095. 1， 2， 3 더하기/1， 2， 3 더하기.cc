#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T;
int n;
int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &T);

	int sum[20] = { 0, };
	
	sum[1] = 1;
	sum[2] = 2;
	sum[3] = 4;

	for (int i = 4; i <= 11; i++) {
		sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
	}




	while (T--) {
		scanf("%d", &n);
		printf("%d\n", sum[n]);
	}

	

	

	return 0;
}