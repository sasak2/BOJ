#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int T;
int R,C;

char ch[100][100];

int main() {
  //freopen("input.txt","rt",stdin);

	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&R,&C);
		for(int i=0; i<R; i++) {
			scanf("%s",ch[i]);
			//printf("%s\n",ch[i]);
		}
		int sum=0;
		int D=3*'#'+'.';

		int Rm=100,RM=0,CM=0,Cm=100;
		
		for(int i=0; i<R; i++) {
			for(int k=0; k<C; k++) {
				if(ch[i][k]=='.')
					continue;
				if(i<Rm) Rm=i;
				if(k<Cm) Cm=k;
				if(i>RM) RM=i;
				if(k>CM) CM=k;
				
			}
		}

		
		R=RM; C=CM;
		//printf("%d %d %d %d",Rm,RM,Cm,CM);
		if(RM-Rm!=CM-Cm) {
			printf("0\n");
			continue;
		}
		
		for(int i=Rm; i<R; i++) {
			for(int k=Cm; k<C; k++) {
				if(ch[i][k]+ch[i+1][k]+ch[i][k+1]+ch[i+1][k+1]==D)
					sum++;
			}
		}
		printf("%d\n",sum==1?1:0);
	}
	
	return 0;
}