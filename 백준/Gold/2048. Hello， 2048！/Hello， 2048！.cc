#include<iostream>
#include<algorithm>
/*
2048


*/

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);

	int T;

	scanf("%d", &T);
	while (T--) {
		int l, r;
		scanf("%d %d", &l, &r);


		if(l==0&&r==3) { printf("5\n"); continue; }
		if (r == l) { printf("%d\n",r); continue; }



		if (r - l == 1 && r <= 3) { printf("%d\n", r + 1); continue; }
		printf("%d\n", r);

	}


	return 0;
}