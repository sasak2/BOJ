#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//15663 n과m 9

int n,m;
int a;
vector<int> v;
int check[10]={0,};

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

	
	for(int i=0; i<n; i++) {
		if(check[i]!=0)
			continue;



		int d=0;
		for(int k=0; k<i; k++) {
			if(v[k]==v[i])
				if(check[k]==0) {
					d=1;
					break;
				}
		}
		if(d==1) continue;
		
		
		


		check[i]=1;
		arr[depth]=i;
		f(depth+1);
		check[i]=0;
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
	

	f(1);
	
	return 0;
}