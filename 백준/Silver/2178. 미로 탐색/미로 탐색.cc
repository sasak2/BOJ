#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
char map[110][110];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };


int DFS() {
	int check[110][110] = { {0,}, };
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));

	while (1) {
		int X = q.front().first.first;
		int Y = q.front().first.second;
		int dist = q.front().second;

		q.pop();

		if (X == N - 1 && Y == M - 1)
			return dist;
		
		

		for (int d = 0; d < 4; d++) {
			int x = dx[d] + X;
			int y = dy[d] + Y;
			
			if (x < 0 || y < 0 || x >= N || y >= M)
				continue;

			if (map[x][y] == '0')
				continue;

			if (check[x][y] == 1)
				continue;

			q.push(make_pair(make_pair(x, y), dist+1));
			check[x][y] = 1;
		}

		

	
	
	
	}

	



}

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
	}

	printf("%d", DFS()+1);

	

	return 0;
}