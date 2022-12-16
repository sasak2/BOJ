#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//4619 루트

int b,n;

int main() {
	freopen("input.txt","rt",stdin);

	while(1) {
		scanf("%d %d",&b,&n);
		if(n==0)
			break;
		
		int sum = pow(double(b),1.0/n);
		int mindiff = sum;
		if(abs(pow(mindiff,n)-b) > abs(pow(sum+1,n)-b))
			mindiff=sum+1;
		if(abs(pow(mindiff,n)-b) > abs(pow(sum-1,n)-b))
			mindiff=sum-1;
		printf("%d\n",mindiff);
	}
	

	return 0;
}