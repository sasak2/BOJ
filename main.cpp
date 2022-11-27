#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
	freopen("input.txt","rt",stdin);

	int n;
	int a;
	vector<int> v;
	
	scanf("%d",&n);
	
	for(int i=0; i<n;i++) {
		scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n;i++)
		printf("%d\n",v[i]);
	//히히 신난다
  return 0;
}