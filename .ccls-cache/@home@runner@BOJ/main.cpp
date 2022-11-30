#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//1018 체스판 다시 칠하기

int n,m;
char ch[52][52];

int fill(int x, int y, char wb) {

	int d=0;
	int cnt=0;;
	for(int i=x; i<x+8; i++) {
		for(int k=y; k<y+8; k++) {
			if((ch[i][k]==wb)==d)
				cnt++;
			d++;
			d%=2;
			
			
		}
	}

	return cnt;
}

int main() {
	freopen("input.txt","rt",stdin);

	scanf("%d %d",&n,&m);
	int min_=999;

	for(int i=0; i<n; i++) 
		scanf("%s",ch[i]);

	for(int i=0; i<=n-8; i++) {
		for(int k=0; k<=m-8; k++) {
			int b=fill(i,k,'B');
			int a=fill(i,k,'W');
			if(min_>a)
				min_=a;
			if(min_>b)
				min_=b;
		}
	}

	printf("%d",min_);

	return 0;
}