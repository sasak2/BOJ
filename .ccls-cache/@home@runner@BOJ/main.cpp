#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//9622 Cabin Baggage

int t;
float a,b,c,d;

int main() {
	freopen("input.txt","rt",stdin);

	scanf("%d",&t);

	int sum = 0;

	while(t--) {
		scanf("%f %f %f %f",&a,&b,&c,&d);

		//56 45 25 125 7
		if(d>7) {
			printf("0\n");
			continue;
		}
		
		if((a+b+c>125)&&(a>56||b>45||c>25)) {
			printf("0\n");
			continue;
		}
		
		printf("1\n");
		sum++;
	}

	printf("%d",sum);

	return 0;
}