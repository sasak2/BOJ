#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int M,Q,N;
int arr[1010];
int say[1010] = {1,};

int main() {
  //freopen("input.txt","rt",stdin);

	scanf("%d %d %d",&M,&N,&Q);
	for(int i=1; i<=N; i++)
		scanf("%d",&arr[i]);
	
	for(int i=1; i<=Q; i++) {
		printf("? %d %d\n",((i-1)%M)+1,i);
		std::cout << std::flush;
		scanf("%d",&say[i]);
	}

	
	printf("!");
	for(int i=1; i<=N; i++)
		printf(" %d",(say[i]%arr[i])+1);
	std::cout << std::flush;
	return 0;
}