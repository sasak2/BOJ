#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

//10845 큐

queue<int> q;

int main() {
	//freopen("input.txt","rt",stdin);

	int n;

	scanf("%d",&n);
	
	for(int i=0; i<n; i++) {
		char ch[100];
		scanf("%s",ch);
		if(!strcmp(ch,"push")) {
			int a;
			scanf("%d",&a);
			q.push(a);
		}
		if(!strcmp(ch,"pop")) {
			if(q.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n",q.front());
			q.pop();
		}
		if(!strcmp(ch,"size")) 
			printf("%d\n",q.size());
			
		if(!strcmp(ch,"empty"))
			printf("%d\n",q.empty());
		
		if(!strcmp(ch,"front")) {
			if(q.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n",q.front());
		}
		if(!strcmp(ch,"back")) {
			if(q.empty()) {
				printf("-1\n");
				continue;
			}
			printf("%d\n",q.back());
		}
		//printf("\n");
	}
	

	return 0;
}