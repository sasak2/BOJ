#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//1920 수 찾기

int a;
int m;
int n;
vector<int> v;

int main() {
	//freopen("input.txt","rt",stdin);

	scanf("%d",&n);
	
	for(int i=0; i<n; i++) {
		scanf("%d",&a);
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	scanf("%d",&m);

	for(int i=0; i<m; i++) {
		scanf("%d",&a);
		printf("%d\n",binary_search(v.begin(),v.end(),a));
	}
	

	return 0;
}