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
28437
골3슥삭 두가자
*/


int dp[100010]={0,};

int main() {
	//freopen("input.txt","rt",stdin);

	int n,q;
	cin>>n;

	int temp=100009;
	while(temp--)
		dp[temp]=0;
	while(n--) {
		int a;
		scanf("%d",&a);
		dp[a]++;
	}

	for(int i=1; i<=50000;i++) {
		for(int k=i*2; k<=100000; k+=i) {
			dp[k]+=dp[i];
		}
	}
	
	cin>>q;
	while(q--) {
		int a;
		scanf("%d",&a);
		printf("%d ",dp[a]);
	}

	return 0;
}