#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//17253 삼삼한 수 2

long long int n;

int main() {
	freopen("input.txt","rt",stdin);

	scanf("%lld",&n);

	if(!n) {
		printf("NO");
		return 0;
	}
	while(n) {
		if(n%3>1) {
			printf("NO");
			return 0;
		}
		n/=3;
	}
	printf("YES");
	
	return 0;
}