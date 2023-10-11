#include<iostream>
#include<algorithm>
/*
28359


*/

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);

	int n;
	int arr[1010];
	scanf("%d", &n);
	

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	int p=0;
	int q_max=0;
	int q_now=0;
	p += arr[0];
	for (int i = 1; i < n; i++) {
		p += arr[i];
		if (arr[i] == arr[i - 1]) {
			q_now += arr[i];
		}
		else q_now = arr[i];
		q_max = max(q_max, q_now);
	}
	
	if (arr[0] == arr[n - 1])p++;

	printf("%d\n", p+ q_max);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}



	return 0;
}