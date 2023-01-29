#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

//2357 최댓값과 최솟값

/*
  자 일단 메인 뽀인뜨!

  세그트리!
근데이제 두개를 만들?까
*/

long long int n,m;
vector<long long int> arr;
vector<long long int> segtree;
vector<long long int>segtree2;

long long int init(int s, int e, int node) {

	if(s==e)
		return segtree[node]=arr[s];

	int mid=(s+e)/2;

	return segtree[node]=min(init(s,mid,node*2),init(mid+1,e,node*2+1));
}

long long int sum(int s, int e, int node, int l, int r) {

	if(l>e||s>r)
		return 99999999999;

	if(l<=s&&e<=r)
		return segtree[node];

	int mid=(s+e)/2;
	return min(sum(s,mid,node*2,l,r),sum(mid+1,e,node*2+1,l,r));
	
}

//--------
long long int init2(int s, int e, int node) {

	if(s==e)
		return segtree2[node]=arr[s];

	int mid=(s+e)/2;

	return segtree2[node]=max(init2(s,mid,node*2),init2(mid+1,e,node*2+1));
}

long long int sum2(int s, int e, int node, int l, int r) {

	if(l>e||s>r)
		return -1;

	if(l<=s&&e<=r)
		return segtree2[node];

	int mid=(s+e)/2;
	return max(sum2(s,mid,node*2,l,r),sum2(mid+1,e,node*2+1,l,r));
	
}
//--------
int main() {
 //freopen("input.txt", "rt", stdin);

	scanf("%lld %lld",&n,&m);

	for(int i=0; i<n; i++) {
		long long int temp;
		scanf("%lld",&temp);
		arr.push_back(temp);
	}
	segtree.assign(n*4,0);
	segtree2.assign(n*4,-1);
	init(0,n-1,1);
	init2(0,n-1,1);

	

	while(m--) {
		long long int a,b,c;
		scanf("%lld %lld",&a,&b);
			printf("%lld %lld\n",sum(0,n-1,1,a-1,b-1),sum2(0,n-1,1,a-1,b-1));
		
	}

	
  return 0;
}