#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int main() {
 // freopen("input.txt","rt",stdin);

	char arr[100];
	scanf("%s",arr);

	int len =strlen(arr);

	int sum = len+2;
	for(int i=0; i<len ;i++) {
		if(arr[i]=='_')
			sum+=5;
	}
	printf("%d",sum);
	return 0;
}