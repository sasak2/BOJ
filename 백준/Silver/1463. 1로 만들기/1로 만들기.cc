#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//1463 1로 만들기

int n;

struct num {
int n,depth;
};
num makenum(int n,int depth) {
	num a;
	a.n=n;
	a.depth=depth;
	return a;
}
queue<num> q;

int main() {
	//freopen("input.txt","rt",stdin);

	scanf("%d",&n);

	q.push(makenum(n,0));
	
	while(1) {
		int topn,topdepth;
		topn=q.front().n;
		topdepth=q.front().depth;
		q.pop();

		if(topn==1) {
			printf("%d",topdepth);
			return 0;
		}

		if(topn%3==0) {
	q.push(makenum(topn/3,topdepth+1));
		}
		if(topn%2==0) {
	q.push(makenum(topn/2,topdepth+1));
		}
	q.push(makenum(topn-1,topdepth+1));

		
	}

	
	
	return 0;
}