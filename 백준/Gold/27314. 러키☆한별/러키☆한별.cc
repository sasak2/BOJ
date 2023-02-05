#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<char>> map;
int hbdist;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

vector<vector<char>> check;
struct Q {
	int x, y;

	int nowdist = 0;
};

Q makeQ(int x, int y) {
	Q newQ;

	newQ.x = x;
	newQ.y = y;
	return newQ;
}

int dfs_dist(int nowx, int nowy, int goalx, int goaly) {
	queue<Q> q;
	Q temp;

	check.resize(N + 3);
	for (int i = 0; i < N + 2; i++) {
		check[i].assign(M + 2, 0);
	}

	q.push(makeQ(nowx, nowy));
	while (1) {
		if (q.empty()) return -1;

		temp = q.front();
		q.pop();

		if (temp.nowdist > hbdist)
			return -1;
		if (temp.x == goalx && temp.y == goaly)
			return temp.nowdist;

		for (int d = 0; d < 4; d++) {
			int x = temp.x + dx[d];
			int y = temp.y + dy[d];

			if (x < 0 || y < 0 || x >= N || y >= M) continue;
			if (check[x][y] == 1) continue;
			if (map[x][y] == 'X') continue;

			check[x][y] = 1;
			temp.x += dx[d];
			temp.y += dy[d];
			temp.nowdist++;
			q.push(temp);
			temp.x -= dx[d];
			temp.y -= dy[d];
			temp.nowdist--;
			//check[x][y] = 0;
		}
	}
}

/*
자 이제 내가 뭔 짓거리를 해야할까

일단 위에 함수를 복사를 해
그다음에 잘 조져서
출구를 기반으로 해서
hbdist 까지 깊이를 두고
거기서 발견하는 사람들을 수를 모아서
리턴을 하는 함수를 만들자요
*/

int dfs_dist_cnt_people(int nowx, int nowy) {
	queue<Q> q;
	Q temp;

	check.resize(N + 3);
	for (int i = 0; i < N + 2; i++) {
		check[i].assign(M + 2, 0);
	}

	int sum = 0;

	q.push(makeQ(nowx, nowy));
	while (1) {
		if (q.empty()) break;

		temp = q.front();
		q.pop();

		if (temp.nowdist > hbdist)
			break;
		if (map[temp.x][temp.y] == 'P')
			sum++;

		for (int d = 0; d < 4; d++) {
			int x = temp.x + dx[d];
			int y = temp.y + dy[d];

			if (x < 0 || y < 0 || x >= N || y >= M) continue;
			if (check[x][y] == 1) continue;
			if (map[x][y] == 'X') continue;

			check[x][y] = 1;
			temp.x += dx[d];
			temp.y += dy[d];
			temp.nowdist++;
			q.push(temp);
			temp.x -= dx[d];
			temp.y -= dy[d];
			temp.nowdist--;
			//check[x][y] = 0;
		}
	}

	return sum;
}


struct EXform {
	int x, y;
	int dist = -1;
};

EXform makeEXF(int x, int y, int dist) {
	EXform a;
	a.x = x;
	a.y = y;
	a.dist = dist;
	return a;
}

pair<int, int> HB;
vector<EXform> exits;
vector<pair<int, int>> person;


int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &N, &M);

	//printf("asdf");
	map.resize(N + 1);
	for (int i = 0; i < N; i++) {
		char ch[100010];
		scanf("%s", ch);
		for (int k = 0; k < M; k++) {

			map[i].push_back(ch[k]);
			if (ch[k] == 'H') {
				HB.first = i;
				HB.second = k;
			}
			if (ch[k] == 'P') {
				person.push_back(make_pair(i, k));
			}

			if (ch[k] == '#') {
				exits.push_back(makeEXF(i, k, -1));
			}

		}
	}

	//자 이제 dfs 하면서 한별쓰와 출구들 사이의 경로를 구해
	//만약 한별~출구 거리 >= 사람 ~ 출구 거리면 그 사람은 선물줄수있어
	//printf("asdf");


	int max_ = 0;
	for (int i = 0; i < exits.size(); i++) {
		int sum = 0;
		/*printf("%d %d to %d %d is %d\n",
		HB.first, HB.second, exits[i].x, exits[i].y,
		dfs_dist(HB.first, HB.second, exits[i].x, exits[i].y));
		*/
		hbdist = 1000000;
		hbdist = dfs_dist(HB.first, HB.second, exits[i].x, exits[i].y);
		if (hbdist == -1)
			continue;

		/*
		for (int k = 0; k < person.size(); k++) {
			int persondist = dfs_dist(person[k].first, person[k].second, exits[i].x, exits[i].y);
			if (persondist != -1 && persondist <= hbdist)
				sum++;
		}
		*/
		sum = dfs_dist_cnt_people(exits[i].x, exits[i].y);

		if (max_ < sum)max_ = sum;
	}
	printf("%d", max_);

	return 0;
}