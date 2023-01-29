#include <iostream>

char up[5][5],down[5][5],front[5][5],back[5][5],left[5][5],right[5][5];
int t;
int n;
char rollside, rollpm;
int rollcount;

void rotateswap(char *a, char *b, char *c, char *d) {
	char temp;
	temp = *d;
	*d = *c;
	*c = *b;
	*b = *a;
	*a = temp;
}

/*
기준은 앞 왼 위 가 기준이다

 00 01 02
 10 11 12
 20 21 22

앞/뒷면의 왼쪽 상단이 00

위/아래면의 왼쪽 뒤가 00

왼/오른면의 뒤쪽 위가 00

아우 대가리 깨질거같네

*/

void L() {
	for(int i=0; i<3; i++) {
		rotateswap(&up[i][0],&front[i][0],&down[2-i][0],&back[2-i][0]);
	}
	rotateswap(&left[0][0],&left[0][2],&left[2][2],&left[2][0]);
	rotateswap(&left[0][1],&left[1][2],&left[2][1],&left[1][0]);
}

void R() {
	for(int i=0; i<3; i++) {
		rotateswap(&up[2-i][2],&back[i][2],&down[i][2],&front[2-i][2]);
	}
	rotateswap(&right[0][1],&right[1][0],&right[2][1],&right[1][2]);
	rotateswap(&right[0][0],&right[2][0],&right[2][2],&right[0][2]);
}

void U() {
	for(int i=0; i<3; i++) {
		rotateswap(&back[0][i],&right[0][i],&front[0][2-i],&left[0][2-i]);
	}
	rotateswap(&up[0][1],&up[1][2],&up[2][1],&up[1][0]);
	rotateswap(&up[0][0],&up[0][2],&up[2][2],&up[2][0]);
}

void D() {
	for(int i=0; i<3; i++) {
		rotateswap(&back[2][2-i],&left[2][i],&front[2][i],&right[2][2-i]);
	}
	rotateswap(&down[0][1],&down[1][0],&down[2][1],&down[1][2]);
	rotateswap(&down[0][0],&down[2][0],&down[2][2],&down[0][2]);
}

void F() {
	for(int i=0; i<3; i++) {
		rotateswap(&up[2][i],&right[i][2],&down[2][2-i],&left[2-i][2]);
	}
	rotateswap(&front[0][1],&front[1][2],&front[2][1],&front[1][0]);
	rotateswap(&front[0][0],&front[0][2],&front[2][2],&front[2][0]);
}

void B() {
	for(int i=0; i<3; i++) {
		rotateswap(&up[0][2-i],&left[i][0],&down[0][i],&right[2-i][0]);
	}
	rotateswap(&back[0][1],&back[1][0],&back[2][1],&back[1][2]);
	rotateswap(&back[0][0],&back[2][0],&back[2][2],&back[0][2]);
}

int main(void) {

	//freopen("input.txt","rt",stdin);

	scanf("%d",&t);

	while(t!=0) {
		t--;
		
		scanf("%d\n",&n);

		for(int i=0; i<3; i++)
			for(int k=0; k<3; k++) {
				up[i][k]='w';
				down[i][k]='y';
				front[i][k]='r';
				back[i][k]='o';
				left[i][k]='g';
				right[i][k]='b';
			}

		for(int i=0; i<n; i++) {
			scanf("%c%c ",&rollside,&rollpm);

			if(rollpm=='+')
				rollcount=1;
			else
				rollcount=3;

			for(int k=0; k<rollcount; k++) {
				switch(rollside) {
 					case 'L' :
 						L();
						break;
					case 'R' :
 						R();
						break;
					case 'U' :
 						U();
						break;
					case 'D' :
 						D();
						break;
					case 'F' :
 						F();
						break;
					case 'B' :
 						B();
						break;
					default :
						break;
 				}
				
				
			}

		}

		
		for(int i=0; i<3; i++) {
			for(int k=0; k<3; k++) 
				printf("%c",up[i][k]);
			printf("\n");	
			}
	
	}

	return 0;
}