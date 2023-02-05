#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int n;

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &n);

	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		pq.push(make_pair(b, a));
		// 앞에꺼가 끝나는시간 뒤에꺼가 시작하는시간
	}


	int nowtime = 0;
	int cnt = 0;
	while (!pq.empty()) {
		if (pq.top().second >= nowtime) {
			cnt++;
			nowtime = pq.top().first;
		}
		pq.pop();
	}

	
	printf("%d", cnt);
	

	return 0;
}