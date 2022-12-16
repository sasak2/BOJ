#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//11650 좌표 정렬

int n;


struct xy{
int x,y;
	bool operator() (xy a,xy b) {
			if(a.x>b.x)
			return true;
		if(a.x<b.x)
			return false;
		if(a.y>b.y)
			return true;
		if(a.y<b.y)
			return false;
	}
} a[100001],temp;


priority_queue<xy> pq;


int cmp(xy a, xy b) {
	if(a.x>b.x)
		return 1;
	if(a.x<b.x)
		return 0;

	
	if(a.y>b.y)
		return 1;
	if(a.y<b.y)
		return 0;
};


int main() {
	freopen("input.txt","rt",stdin);

	scanf("%d",&n);

	for(int i=0; i<n; i++) {
		scanf("%d %d",&a[i].x,&a[i].y);
		pq.push(a[i]);
	}


	for(int i=0; i<n; i++) {
		printf("%d %d\n",pq.top().x,pq.top().y);
	}
	return 0;
}