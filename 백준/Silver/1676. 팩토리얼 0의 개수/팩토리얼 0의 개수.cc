#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//1676 팩토리얼 0의 개수

int n;
int dl=0,dh=0;

void fibodiv2(int n) {
	if(n%2==0) {
		dl++;
		fibodiv2(n/2);
	}
}

void fibodiv5(int n) {
	if(n%5==0) {
		dh++;
		fibodiv5(n/5);
	}
}

int main() {
	//freopen("input.txt","rt",stdin);

	scanf("%d",&n);

	for(int i=5; i<=n; i++) {
		//fibodiv2(i);
		fibodiv5(i);
	}

	printf("%d",dh);
	
	return 0;
}