#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
 
	int array[1000001];
 
	for(int i = 0; i < N; i++) {
		cin >> array[i];
	}
 
	sort(array, array + N);	
 
	cout << array[0] << " " << array[N - 1];
 
	return 0;
 
}