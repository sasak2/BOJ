#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;



int main() {
	//freopen("input.txt", "rt", stdin);

	//아니 이게 그 일단 ㅣㅁㅁㄴㅣ 이런 상태도 있어
	//그냥 책 밑에 붘엔드 끼울수 있으면 1
	//책 옆에 ㄴ 끼울수 있으면 1
	// 붘엔드 없어도 되면 0
	// 그거도 안되면 -1 끝 아닌가
	//이게 왜 골1?

	int n, m, l, booksum = 0;
	scanf("%d %d %d", &n, &m, &l);

	while (n--) {
		int a;
		scanf("%d", &a);
		booksum += a;
	}

	if (booksum == m) {
		printf("0");
		return 0;
	}

	
	if (booksum > m) {
		printf("-1");
		return 0;
	}
	

	if (booksum - l >= 0 || booksum + l <= m) {
		printf("1");
		return 0;
	}
	else {
		printf("-1");
		return 0;
	}

	

	return 0;
}