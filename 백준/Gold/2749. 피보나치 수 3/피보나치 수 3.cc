#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

//2749 피보나치 수 3

/*
  자 일단 메인 뽀인뜨!
	무지성 ㄱ

*/


int main() {
  //freopen("input.txt", "rt", stdin);

	long long int n;
	long long int a=0,b=1,c=1;

  scanf("%lld",&n);

	n%=1500000;

	for(long long int i=1; i<=n; i++) {
		c=(a+b)%1000000;
		a=b;
		b=c;
	}

	printf("%lld",a);
  return 0;
}