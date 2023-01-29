#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stdlib.h>

using namespace std;

//1149 rgb거리
int n;
int cost[3][1005];
int dp[3][1005]={{0,},};

int main(void) {
	//freopen("input.txt","rt",stdin);

	scanf("%d",&n);

	for(int i=0; i<n; i++) {
		scanf("%d %d %d",&cost[0][i],&cost[1][i],&cost[2][i]);
	}
	dp[0][0]=cost[0][0];
	dp[1][0]=cost[1][0];
	dp[2][0]=cost[2][0];


	for(int i=1; i<n; i++) {
		for(int k=0; k<3; k++) {
			dp[k][i]=cost[k][i]+min(dp[(k+1)%3][i-1],dp[(k+2)%3][i-1]);
		}
	}


	printf("%d",min(dp[0][n-1],min(dp[1][n-1],dp[2][n-1])));
	
	
	return 0;
}