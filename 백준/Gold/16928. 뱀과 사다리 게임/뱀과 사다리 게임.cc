#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n, m;
map<int, int> bamsadari;
int check[123] = { 0, };


int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n + m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		bamsadari.insert(make_pair(a, b));
	}

	queue<pair<int,int>> q;
	q.push(make_pair(1,0));
	while (1) {
		
		int a = q.front().first;
		int dist = q.front().second;

		q.pop();
		
		if (check[a] == 1) continue;
		check[a] = 1;
		
		if (a >= 100) {
			printf("%d", dist);
			return 0;
		}

		for (int i = 1; i <= 6; i++) {
			if (bamsadari.find(a + i) != bamsadari.end())
				q.push(make_pair(bamsadari[a + i], dist + 1));
			else
				q.push(make_pair(a + i, dist + 1));
		}


	}

	

	return 0;
}