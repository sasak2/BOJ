#define MOD 1000000007

#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

//1540 정사각형의 개수

/*
  자 일단 메인 뽀인뜨!

	일단 a*a에서 정사각형 개수는
	1제곱 + 2제곱 + 3제곰 ... a제곱임
	근데 이제 여기에서 플러스 알파로 옆에 꼬다리로 붙는게 생길거야
	일단 n보다 작은 가장 큰 제곱수를 구해서 그거로 딱 하고
	그담에는 옆에 꼬다리들을 계산을 하자

	ㅁㅁㅁ
	ㅁㅁㅁ
	ㅁㅁㅁ
	ㅁㅁㅁ
	이렇게며는 옆에 붙어있는그거가
	꼬다리 수 +1 c 2임

	위에 붙는 꼬다리가 다 차면 옆에도 꼬다리 붙이면 되구
	자 두가 자
*/

int nC2(int n) {
	if(n==1) return 0;
	return n*(n-1)/2;
}

int n;

int num = 0;

int main(void) {
	//freopen("input.txt","rt",stdin);

	scanf("%d",&n);

	int a;
	for(a=1; a<=1000; a++) {
		if(a*a>n) {
			break;
		}
	}
	a--;

	num = (a*(a-1)*(2*a-1))/6;

	n=n-a*a;

	if(n>=a) {
		num+=nC2(a);
		n-=a;
	}
	num+=nC2(n);

	printf("%d",num);
	
    
	return 0;
}