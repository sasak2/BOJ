#include<iostream>
#include<algorithm>
/*
2818


*/

using namespace std;

int u = 1, d = 6, l = 4, r = 3, f = 2, b = 5;

void roll_right() {
	int temp = u;
	u = l;
	l= d;
	d = r;
	r= temp;
}
void roll_left() {
	roll_right(); roll_right(); roll_right();
}
void roll_down() {
	int t = f;
	f = u;
	u = b;
	b = d;
	d = t;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int rr;//아래
	int c;// 옆으로
	long long int sum = 0;
	
	scanf("%d %d", &rr, &c);
	for (int i = 0; i < 12; i++) {
		sum += u;
		//printf("\n%d ", u);
		for(int k=1; k<c; k++) {
			if (i % 2 == 0) {
				roll_right();
				sum += u;
			}
			if (i % 2 == 1) {
				roll_left();
				sum += u;
			}
		//printf("%d ", u);
		}
		roll_down();
	}
	long long int mungtangE12 = sum;

	u = 1, d = 6, l = 4, r = 3, f = 2, b = 5;
	sum = 0;

	for (int i = 0; i < rr%12; i++) {
		sum += u;
		//printf("\n%d ", u);
		for (int k = 1; k < c; k++) {
			if (i % 2 == 0) {
				roll_right();
				sum += u;
			}
			if (i % 2 == 1) {
				roll_left();
				sum += u;
			}
			//printf("%d ", u);
		}
		roll_down();
	}

	printf("%lld", mungtangE12*(rr/12) + sum);

	return 0;
}