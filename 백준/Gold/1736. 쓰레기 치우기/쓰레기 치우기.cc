#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define mt(x,y,z) make_tuple(x,y,z)
#define x first
#define y second

#define X dx[d]
#define Y dy[d]

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <complex>

using namespace std;

/*
https://www.acmicpc.net/problem/1736

자 일단 메인 포인또
이게 일단 그냥 그래프로 생각을 해둘수가 있단말임
엄
그리디 쓰까

시작점에서
136
25
4

이런식으로 탐색하고
방문하면 없애기
ㅇㅇ
*/

int n,m;
int area[222][222];

int main() {
	//freopen("input.txt","rt",stdin);

	scanf("%d %d",&n,&m);

	for(int i=0;i<211; i++) {
		for(int k=0; k<211; k++) {
			area[i][k]=0;
		}
	}

int trash=0;
	for(int i=0;i<n; i++) {
		for(int k=0; k<m; k++) {
			scanf("%d",&area[k][i]);
			trash+=area[k][i];
			//printf("%d",area[k][i]);
		}
	//	printf("\n");
	}
	
//return 0;
	if(trash==0) {printf("0");return 0;}
	
	if(trash==1) {printf("1");return 0;}
	//printf("%d",trash);
trash-=area[0][0];

	
	int cnt=0;
	while(trash!=0) {

		int x=0,y=0;
		area[m+2][n+2]=1;
		area[0][0]=0;
		//int now_robot_goto_mn_direct=0;
		while(1) {
			area[m+2][n+2]=1;

			
			//ki
			for(int i=y; i<n+5; i++) {
				for(int k=x; k<m+5; k++) {
					if(area[k][i]==1) {
						trash--;
						area[k][i]=0;
						x=k;
						y=i;
						goto A;
						
						
					}
				}
				
			}

				
			
			A:
			/*
			printf("\n\n %d %d %d \n",x,y,trash);
	for(int i=0;i<n+3; i++) {
		for(int k=0; k<m+3; k++) {
			//scanf("%d",&area[k][i]);
			printf("%d",area[k][i]);
		}
		printf("\n");
	}
	*/
		
			if(x==m+2&&y==n+2)  {
				trash ++;
				cnt++;break;}
	}
		
	}

	printf("%d",cnt);

	
	return 0;
}