#define ll long long int

#include<iostream>
#include<algorithm>
#include<vector>


/*


*/

using namespace std;

vector<long long int> avg,origin;

int main() {
	//freopen("input.txt", "rt", stdin);
	
	int n;
	vector<int> arr;



	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		printf("%d ",arr[i]);
	}







	return 0;
}