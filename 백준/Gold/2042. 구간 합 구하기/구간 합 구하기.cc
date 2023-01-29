#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

//2042 구간 합 구하기

/*
  자 일단 메인 뽀인뜨!

  세그트리!
*/

long long int n,m,k;
vector<long long int> arr;
vector<long long int> segtree;

long long int init(int s, int e, int node) {

	if(s==e)
		return segtree[node]=arr[s];

	int mid=(s+e)/2;

	return segtree[node]=init(s,mid,node*2)+init(mid+1,e,node*2+1);
}

long long int sum(int s, int e, int node, int l, int r) {

	if(l>e||s>r)
		return 0;

	if(l<=s&&e<=r)
		return segtree[node];

	int mid=(s+e)/2;
	return sum(s,mid,node*2,l,r)+sum(mid+1,e,node*2+1,l,r);
	
}

void update(int s, int e, int node, int index, long long int diff) {
	if(index<s||index>e)
		return;

	segtree[node]+=diff;
	if(s==e)return;
	int mid=(s+e)/2;
	update(s,mid,node*2,index,diff);
	update(mid+1,e,node*2+1,index,diff);
}

int main() {
// freopen("input.txt", "rt", stdin);

	scanf("%lld %lld %lld",&n,&m,&k);

	for(int i=0; i<n; i++) {
		long long int temp;
		scanf("%lld",&temp);
		arr.push_back(temp);
	}
	segtree.assign(n*4,0);
	init(0,n-1,1);

	int i=m+k;

	while(i--) {
		long long int a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		//1 바꾸기 2 합구하기
		if(a==1)  {
		update(1,n,1,b,c-arr[b-1]);
			arr[b-1]=c;
		}
		if(a==2)
			printf("%lld\n",sum(0,n-1,1,b-1,c-1));
		
	}

	
  return 0;
}