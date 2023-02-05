//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*

자 일딴 메인 포인뜨

이거는 그리디 맞는듯


*/

struct cmp {
	bool operator()(pair<long long int, long long int>& a, pair<long long int, long long int>& b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		else {
			return a.first > b.first;
		}
	}
};



long long int N, M;
priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> mun;//1아이디어 2구현 
//저거가 이제 아이디어가 낮은게 먼저오곘찌
priority_queue<long long int, vector<long long int>, greater<long long int>> P;// 이게 이제 아이디어가 충족되는것들만 모아놓은거 근데이제 여기서 구현레벨이 낮으면 앞에오겠지
long long int hd, hp;

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%lld %lld", &N, &M);

	for (long long int i = 0; i < N; i++) {
		long long int a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (c == 1)
			b = 0;
		if (d == 1) {
			a = (a + 1) / 2;
			b /= 2;
		}
		mun.push(make_pair(a, b));

	}
	scanf("%lld %lld", &hd, &hp);

	long long int WAsum = 0;
	while (M--) {
		while (1) {
			if (mun.empty()) break;
			if (mun.top().first <= hd) {
				P.push(mun.top().second);
				mun.pop();
			}
			else {
				break;
			}
		}
		if (P.empty()) {
			printf("-1");
			return 0;
		}

		//prlong long intf("%d ",P.top());
		WAsum += (P.top() <= hp)? 0 : P.top() - hp;
		P.pop();

		hp++;
		hd++;



	}

	printf("%lld", WAsum);



	return 0;
}