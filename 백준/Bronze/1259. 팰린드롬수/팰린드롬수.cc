#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;
int main() {
	//freopen("input.txt","rt",stdin);

	char ch[30];
	
	while(1) {
		scanf("%s",ch);

		if(ch[0]=='0')
			break;

		int len=strlen(ch);
		int d=0;

		for(int i=0; i<len/2; i++) {
			if(ch[i]!=ch[len-i-1]) {
				d=1;
				break;
			}
		}

		if(d==0)
			printf("yes\n");
		else
			printf("no\n");


		
	}

	
	
  return 0;
}