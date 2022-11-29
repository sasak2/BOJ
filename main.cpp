#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//1978 소수찾기

int n;
int a;
int cnt=0;

int main() {
	freopen("input.txt","rt",stdin);

	scanf("%d",&n);

	for(int i=0; i<n; i++) {
		scanf("%d",&a);
		if(a==1)
			continue;
		if(a==2) {
			cnt++;
			continue;
		}
		int d=1;
		for(int k=2; k<=int(sqrt(a))+1; k++) {
			//printf("%d %% %d = %d\n",a,k,a%k);
			if(a%k==0) {
				d=0;
				break;
			}
		}
		cnt+=d;
		//printf("%d %d\n",a,d);
	}

	printf("%d",cnt);
  return 0;
}