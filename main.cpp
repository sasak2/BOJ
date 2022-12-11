#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//15666 n과m 12

int n,m;
int a;
vector<int> v;

int arr[10]={0,};

void print() {
	for(int i=0; i<m; i++)
		printf("%d ",v[arr[i+1]]);
	printf("\n");
}

void f(int depth) {
	if(depth==m+1) {
		print();
		return;
	}

	for(int i=arr[depth-1]; i<n; i++) {
		arr[depth]=i;
		f(depth+1);
	}
		
	

	
}

int main() {
	freopen("input.txt","rt",stdin);

	scanf("%d %d",&n,&m);

	for(int i=0; i<n; i++) {
		scanf("%d",&a);
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	n=v.size();

	f(1);
	
	return 0;
}