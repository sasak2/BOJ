#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define mt(x,y,z) make_tuple(x,y,z)
#define x first
#define y second
#define MOD 1000000007
#define X dx[d]
#define Y dy[d]

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <complex>
#define ll long long int
using namespace std;

/*
10653 매뢔퉌

dp i k = i번째까지 올떄k를 스킵했어용

dp i k = min(dp i-1 k + 거리 ,dp i-x k-x )x가 1~k까지다
이건 포문 를! 돌린다

*/

int n,kk;
int dp[555][555];
pair<int,int> point[555];
int main() {
//	freopen("input.txt","rt",stdin);

	scanf("%d %d",&n,&kk);
	
	int a,b;
		scanf("%d %d",&a,&b);
		point[1]=mp(a,b);
	
	for(int i=2;i<=n;i++) {
		scanf("%d %d",&a,&b);
		point[i]=mp(a,b);
		dp[i][0]=dp[i-1][0]+abs(point[i].x-point[i-1].x)+abs(point[i].y-point[i-1].y);
	}

	for(int k=0;k<=kk;k++) {
		dp[1][k]=dp[1][0];
		//printf("\n%d ",dp[1][k]);
		for(int i=2;i<=n;i++) {
			dp[i][k]=dp[i-1][k]+abs(point[i].x-point[i-1].x)+abs(point[i].y-point[i-1].y);
			for(int j=0; j<=k;j++) {
				if(i-j-1<=0)continue;
				//printf("k%d i%d j%d i-j-1%d ",k,i,j,i-j-1);
				dp[i][k]=min(dp[i][k],dp[i-j-1][k-j]+abs(point[i].x-point[i-j-1].x)+abs(point[i].y-point[i-j-1].y));
			//	printf("/%d/",dp[i-j][k-j]);
				
			}
			//printf("%d ",dp[i][k]);
		}
	}
	cout<<dp[n][kk];
	return 0;
}