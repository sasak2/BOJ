#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int main() {
	freopen("input.txt","rt",stdin);

	int n;
	char ch[30];

	scanf
	while(1) {
		scanf("%d %d %d",&a,&b,&c);
		if(a+b+c==0)
			break;
		if(a>c) {
	  	temp=c;
	  	c=a;
	  	a=temp;
  	}
	  if(b>c) {
		  temp=c;
	  	c=b;
	  	b=temp;
	  }
		if(c*c==(a*a)+(b*b))
			printf("right\n");
		else
			printf("wrong\n");
		
	}

	
	
  return 0;
}