#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n;

struct tree {

set<int>v;
int num=0;
int level=0;
};

vector<tree> graph;



int main() {
	//freopen("tjdrp.txt","rt",stdin);

	/*
	set<int> s;
	s.insert(1);
	s.insert(2);
	auto it = s.begin();
		for (auto it = s.begin(); it != s.end(); it++)
		{
			printf("value: %d\n", *it);
		}*/

	scanf("%d",&n);

	graph.resize(n+2);
//return 0;
	//printf("1");

	for(int i=1; i<n; i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].num++;
		graph[a].v.insert(b);
		graph[b].num++;
		graph[b].v.insert(a);
	}
	/*
	printf("\n\n\n");
for(int i=1; i<=n; i++) {
	printf("\n%d(%d) : ",i,graph[i].num);
	for(int k=0; k<graph[i].v.size(); k++)
		printf("%d ",graph[i].v[k]);
}*/
	//printf("2");
//return 0;
	queue<int> level1;
	for(int i=1; i<=n; i++) {
		if(graph[i].num==1)
			level1.push(i);
		if(graph[i].num==2) {
			int ab[3];
			int temp = 0;
			for (auto it = graph[i].v.begin(); it != graph[i].v.end(); it++) {
				ab[temp] = *it;
				temp++;
			}
			int a = ab[0];
			int b = ab[1];
			//printf("\n%d : %d %d",i,a,b);
			graph[a].v.erase(i);
			graph[a].v.insert(b);

			graph[b].v.erase(i);
			graph[b].v.insert(a);

			graph[i].num=0;
		}
	}
	/*
	printf("\n\n2개거름\n");
for(int i=1; i<=n; i++) {
	printf("\n%d(%d) : ",i,graph[i].num);
	for(int k=0; k<graph[i].v.size(); k++)
		printf("%d ",graph[i].v[k]);
}*/
	
	//printf("3");
//return 0;

	//printf("\n\n1 :");
	queue<int> level2;
	while(!level1.empty()) {
		int a=level1.front();
		//printf("%d ",a);
		level1.pop();
		
		auto amother = graph[a].v.begin();
		graph[*amother].num--;
		graph[*amother].v.erase(a);
		

		graph[a].num=0;
		if(graph[*amother].level==1) {
			continue;
		}

		graph[*amother].level=1;
		//level2.push(*amother);
		
	}
	queue<int> level3;
//return 0;
	//printf("4");
	/*
	printf("\n\n레벨1끝\n");
for(int i=1; i<=n; i++) {
	printf("\n%d(%d) : ",i,graph[i].num);
	for(int k=0; k<graph[i].v.size(); k++)
		printf("%d ",graph[i].v[k]);
}*/
	for (int i = 1; i <= n; i++) {
		if (graph[i].num == 1)
			level2.push(i);
	if (graph[i].num == 2) {
		int ab[3];
		int temp = 0;
		for (auto it = graph[i].v.begin(); it != graph[i].v.end(); it++) {
			ab[temp] = *it;
			temp++;
		}
		int a = ab[0];
		int b = ab[1];
		//printf("\n%d : %d %d",i,a,b);
		graph[a].v.erase(i);
		graph[a].v.insert(b);

		graph[b].v.erase(i);
		graph[b].v.insert(a);

		graph[i].num = 0;
	}
}

	//printf("\n\n2 : ");

	while(!level2.empty()) {
		int a=level2.front();
		level2.pop();
		//printf("%d ",a);

		auto amother = graph[a].v.begin();

		if(graph[a].num!=1)
			continue;
		
		graph[*amother].num--;
		graph[*amother].v.erase(a);
		
		graph[a].num=0;
		if(graph[*amother].level==2) {
			continue;
		}

		graph[*amother].level=3;
		level3.push(*amother);
		graph[a].num=0;
	}

	//return 0;
	//printf("5");
	/*
	printf("\n\n레벨2끝\n");
for(int i=1; i<=n; i++) {
	printf("\n%d(%d) : ",i,graph[i].num);
	for(int k=0; k<graph[i].v.size(); k++)
		printf("%d ",graph[i].v[k]);
}
	*/
	
	for(int i=1; i<=n; i++) {
		if(graph[i].num>=3) {
			printf("NO");
			return 0;
		}
	}

	
		printf("YES");
	

	return 0;
}