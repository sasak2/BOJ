#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//20300 서강근육맨

int n;
long long int arr[10005];

int main() {
	freopen("input.txt","rt",stdin);

	scanf("%d",&n);

	for(int i=0; i<n; i++) 
		scanf("%lld",&arr[i]);
	
	sort(arr,arr+n);

	long long int m=0;
	if(n%2==1) {
		m=arr[n-1];
		n--;
	}

	for(int i=0; i<n/2; i++) {
		if(m<arr[i]+arr[n-i-1])
			m=arr[i]+arr[n-i-1];
	}

	printf("%lld",m);
	return 0;
}