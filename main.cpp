#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

int h[52],w[53];

using namespace std;
int main() {
	freopen("input.txt","rt",stdin);

	int n;

	scanf("%d",&n);
	
	for(int i=0; i<n; i++) 
		scanf("%d %d",&h[i],&w[i]);
	
	for(int i=0; i<n; i++) {
		int d=1;
		for(int k=0; k<n; k++)
			if(h[i]<h[k]&&w[i]<w[k])
				d++;

		printf("%d ",d);

		
	}
	
  return 0;
}