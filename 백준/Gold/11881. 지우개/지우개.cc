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
11881 지우개
*/
ll nowsum=0;
ll dp[4][100010];

int main() {
	//freopen("input.txt","rt",stdin);

	
	ll n;
	scanf("%lld",&n);
for(int i=0;i<n;i++) {
		scanf("%lld",&dp[3][i]);
	dp[3][i]%=MOD;	
	//printf("%lld ",dp[3][i]);
		
}
	sort(dp[3],dp[3]+n);

	for(int i=0;i<n;i++) 
		//printf("%lld ",dp[3][n-1-i]);	
	//printf("\n  ");
//printf("\n");
	//nowsum-=dp[3][0];




	
	ll nowsum2=0;
	ll 중복_모아둘거=0;
	for(int i=n-2; i>0; i--) {

		if(dp[3][i]==dp[3][i+1]) {
			dp[2][i]=dp[2][i+1];
			중복_모아둘거+=dp[3][i+1];
	//	printf("%lld ",dp[2][i]);
			continue;
		}
		if(i<n-2)
		if(dp[3][i+1]==dp[3][i+2]) {
		//	nowsum-=dp[3][i+1];
			nowsum+=중복_모아둘거;
			중복_모아둘거=0;
		}
		nowsum+=dp[3][i+1];		
		//printf("|ns%lld|",nowsum);
		/*ll tempsum=0;
		//for(int k=i+1; k<n-1; k++)
			tempsum=nowsum-dp[3][i];
		nowsum-=dp[3][i];
printf("|nowsum = %lld|",nowsum);
		nowsum%=MOD;*/

		dp[2][i]=0;
		dp[2][i]=nowsum*dp[3][i];
		dp[2][i]%=MOD;
		//nowsum2+=dp[2][i];
		//nowsum2%=MOD;
		//nowsum-=dp[3][i];
		//if(dp[2][i]<dp[3][i])
		//dp[2][i]=dp[3][i]*nowsum;
		//dp[3][i]*(dp 3 i+1~n)
		//야 이거 미래의 내가 누적 합 하는거 구현할거야

	//	printf("%lld ",dp[2][i]);
	
	}
	//나우섬2가 1~n-1까지자나
//printf("\n");
	ll ans=0;
	nowsum=0;
	중복_모아둘거=0;
	for(int i=n-3; i>=0; i--) {
	/*
ll tempsum=nowsum2;
		nowsum2-=dp[2][i+1];
tempsum%=MOD;
		nowsum2%=MOD;
*/		
	if(dp[3][i]==dp[3][i+1]) {
			dp[1][i]=dp[1][i+1];
			
			중복_모아둘거+=dp[2][i+1];
		//printf("%lld ",dp[1][i]);
			
		
		ans+=dp[1][i];
		ans%=MOD;
		continue;
		}
		if(i<n-3)
		if(dp[3][i+1]==dp[3][i+2]) {
			//nowsum-=dp[2][i+1];
			nowsum+=중복_모아둘거;
			//nowsum+=dp[2][i+1];
			중복_모아둘거=0;
		}
		
 nowsum+=dp[2][i+1];
		
		//printf("|ns%lld|",nowsum);
 
 dp[1][i]=0;
		dp[1][i]=nowsum*dp[3][i];
		dp[1][i]%=MOD;
		/*nowsum+=dp[2][i+1];
		dp[1][i]=dp[3][i]*nowsum;
		ans+=dp[1][i];
		//야 이거 미래의 내가 누적 합 하는거 구현할거야
			*/
		ans+=dp[1][i];
		ans%=MOD;
		//printf("%lld ",dp[1][i]);
	
	}
//printf("\n");
ans%=MOD;
	cout<<ans;
	
	
	return 0;
}