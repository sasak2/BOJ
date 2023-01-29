#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//1085 직사각형에서 탈출

int x,y,h,w;

int main() {
	//freopen("input.txt","rt",stdin);

	int a=9999;

	scanf("%d %d %d %d",&x,&y,&w,&h);
	a=min(a,h-y);
	a=min(a,y);

	a=min(a,w-x);
	a=min(a,x);

	printf("%d",a);
	

	return 0;
}