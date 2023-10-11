#include<iostream>
#include<algorithm>
#include<vector>


/*
2818


*/

using namespace std;



int main() {
	//freopen("input.txt", "rt", stdin);
	
	int n, q;

	scanf("%d %d", &n, &q);

	int ans = 0;
	while (q--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) ans++;
		else ans += (c - b + 1) / 2;
		ans %= 2;
		printf("%d\n", ans);
		
	}
	
	return 0;
}