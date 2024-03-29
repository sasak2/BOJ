#include <iostream>

//1799 비숍
using namespace std;

int n;
int map[11][11];
int max_1=-1;
int max_2=-1;

void mapplus(int x, int y,int one) {
	for(int i=0; i<n; i++) {
		if(x-i<0||y-i<0) break;
		map[x-i][y-i]+=one;
	}

	for(int i=0; i<n; i++) {
		if(x+i>n||y+i>n) break;
		map[x+i][y+i]+=one;
	}

	for(int i=0; i<n; i++) {
		if(x-i<0||y+i>n) break;
		map[x-i][y+i]+=one;
	}

	for(int i=0; i<n; i++) {
		if(x+i>n||y-i<0) break;
		map[x+i][y-i]+=one;
	}



	
	map[x][y]+=(one*6);
	
}

void dfs2(int count,int x, int y) {
	if(y==n) return;
	if(count>max_2) {
		max_2=count;
        /*
		printf("max2 : %d\n\n",count);
		for(int i=0; i<=n; i++) {
			for(int k=0; k<=n; k++) {
				printf("%d ",map[i][k]);
			}
			printf("\n");
		}
		printf("\n\n");
        */
	}	
	
	int xx=x+2;
	int yy=y;
	if(xx>=n) {
		yy++;
		xx=1-(yy%2);
	}
if(y==n) return;
	
	dfs2(count,xx,yy);

	if(map[xx][yy]==0) {
		mapplus(xx,yy,1);
		dfs2(count+1,xx,yy);
		mapplus(xx,yy,-1);
	}
	return;
}

void dfs1(int count,int x, int y) {
	if(y==n) return;
	if(count>max_1) {
		max_1=count;
        /*
		printf("max1 : %d x %d y %d\n\n",count,x,y);
		for(int i=0; i<=n; i++) {
			for(int k=0; k<=n; k++) {
				printf("%d ",map[i][k]);
			}
			printf("\n");
		}
		printf("\n\n");
        */
	}	
	
	int xx=x+2;
	int yy=y;
	if(xx>=n) {
		yy++;
		xx=yy%2;
	}
if(y==n) return;
	
	dfs1(count,xx,yy);

	
	if(map[xx][yy]==0) {
		mapplus(xx,yy,1);
		dfs1(count+1,xx,yy);
		mapplus(xx,yy,-1);
	}
	return;
}


int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d",&n);
	for(int i=0; i<n; i++)
		for(int k=0; k<n; k++) {
 			scanf("%d",&map[i][k]);
			map[i][k]=(map[i][k]+1)%2;
			}

	dfs1(0,-2,0);
	dfs2(0,-1,0);
	printf("%d",max_1+max_2);


		
        
	
	

	return 0;
}