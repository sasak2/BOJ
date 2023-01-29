#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//14939 불끄기

char light[12][12];
int onoff[12][12]={{0,},};

void print(void) {
	printf("\n\n");
	for(int i=0; i<10; i++) {
		for(int k=0; k<10; k++) {
			printf("%c",light[i][k]);
		}
		printf("\n");
	}
}

void swap(int i,int k) {
	if(i<0||k<0||i>9|| k>9)
		return;
	if(light[i][k]=='#')
		light[i][k]='O';
	else
		light[i][k]='#';
	return;
}

void onofflight(int i, int k) {
	swap(i,k);
	swap(i-1,k);
	swap(i+1,k);
	swap(i,k-1);
	swap(i,k+1);
	return;
}

int check(void) {
	for(int i=0; i<10; i++) {
		
		if(light[9][i]!='#')
			return 999;
	}
	//print();
	return 0;
}

int nextline(int l) {

	
	if(l==9)
		return check();
	int sum=0;

	for(int i=0; i<10; i++) {
		if(light[l][i]=='O') {
			sum++;
			onoff[l+1][i]++;
			onofflight(l+1,i);
		}
	}
	
	sum += nextline(l+1);
	
	for(int i=0; i<10; i++) {
		if(onoff[l+1][i]==1) {
			onoff[l+1][i]--;
			onofflight(l+1,i);
		}
	}

	return sum;
}



int main() {
	//freopen("input.txt","rt",stdin);


	int maxy=999;
	
	for(int i=0; i<10; i++)
		scanf("%s", light[i]);

	onoff[0][0]=-1;
	for(int i=0; i<=1024; i++) {
		int sum=0;
		onoff[0][0]++;
		for(int k=0; k<10; k++) {
			if(onoff[0][k]==2) {
				onoff[0][k+1]++;
				onoff[0][k]=0;
			}
			if(onoff[0][k]==1) {
				onofflight(0,k);
				sum++;
			}
		}

		sum += nextline(0);
		for(int k=0; k<10; k++) 
			if(onoff[0][k]==1) 
				onofflight(0,k);

		if(sum<maxy) {
			maxy=sum;
			//print(sum);
		}
	}

	printf("%d",maxy<100?maxy:-1);
	return 0;
}