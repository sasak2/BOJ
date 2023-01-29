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

//7576 토마토

/*
  자 일단 메인 뽀인뜨!

	익은 토미토를 큐에 넣어서 짠
*/

int n,m;
int map[1001][1001];
int dir[4]={0,1,0,-1};

queue<pair<int,int>> tomato;
queue<pair<int,int>> tomato2;


int main() {
	///freopen("input.txt", "rt", stdin);

	scanf("%d %d",&n,&m);

	for(int i=0; i<m; i++)
		for(int k=0; k<n; k++) {
			scanf("%d",&map[i][k]);
			if(map[i][k]==1)
				tomato.push(make_pair(i,k));
		}


	int day = 0;
	while(1) {
		int def=0;
		while(!tomato.empty()) {
			//asdf
	
			for(int d=0; d<4; d++) {
				if(tomato.front().first+dir[d]>=0&&tomato.front().first+dir[d]<m&&tomato.front().second+dir[(d+1)%4]>=0&&tomato.front().second+dir[(d+1)%4]<n)
				if(map[tomato.front().first+dir[d]][tomato.front().second+dir[(d+1)%4]]==0) {

					map[tomato.front().first+dir[d]][tomato.front().second+dir[(d+1)%4]]=1;

					
					tomato2.push(make_pair(tomato.front().first+dir[d],tomato.front().second+dir[(d+1)%4]));

					def=1;
					
				}
			}

			tomato.pop();
		}		
		if(def==0)
			break;
		while(!tomato2.empty()) {
			tomato.push(tomato2.front());
			tomato2.pop();
		}
		day++;

		/*
	printf("\n%d\n",day);	
	for(int i=0; i<m; i++) {
		for(int k=0; k<n; k++) {
			printf("%2d ",map[i][k]);
		
		}
		printf("\n");
	}
		*/
		
	}


	for(int i=0; i<m; i++) {
		for(int k=0; k<n; k++) {
			if(map[i][k]==0){
				printf("-1");
				return 0;
			}		
		}
	}

	printf("%d",day);
  return 0;
}