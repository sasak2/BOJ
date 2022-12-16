#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//15657 N과M 8

int n,m;
int arr[10];
int num[10];

void print(void) {
	for(int i=0; i<m; i++) {
		printf("%d ",num[arr[i+1]-1]);
	}
	printf("\n");
}

void f(int depth) {
	if(depth==m+1)  {
		print();
		return;
		}
	

	for(int i=arr[depth-1]; i<=n; i++) {
	
	
		arr[depth]=i;
		f(depth+1);

		
	}
 
	
	
}

int main() {
	freopen("input.txt","rt",stdin);

	scanf("%d %d",&n,&m);

	for(int i=0; i<n; i++)
		scanf("%d",&num[i]);

	sort(num,num+n);
	
	arr[0]=1;
	f(1);

	

	return 0;
}