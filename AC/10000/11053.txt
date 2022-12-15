#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//11053 가장 긴 증가하는 부분 수열

int n;
int arr[1004];
int big[1004]={0,};

int main() {
	freopen("input.txt","rt",stdin);

	scanf("%d",&n);
	for(int i=0; i<n; i++) 
		scanf("%d",&arr[i]);

	for(int i=0; i<n; i++) {
		int d=0;
		for(int k=0; k<i; k++) {
			if(arr[k]<arr[i]&&big[k]>=d)
				d=big[k];
		}
		big[i]=d+1;
	}

	int wow=1;
	for(int i=0; i<n; i++) {
		if(big[i]>wow)
			wow=big[i];
	}
	printf("%d",wow);
	return 0;
}