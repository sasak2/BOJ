#include "Annalib.h"
#include "Brunolib.h"

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void Anna(int N, long long X, int K, int P[])
{
	set<int> broken;
	vector<int>able;

	for (int i = 0; i < K; i++) {
		broken.insert(P[i]);
	}

	for (int i = 0; i < 50; i++) {
		int cnt = 0;
		for (int j = 0; j < 3; j++) {
			cnt += broken.count(i * 3 + j);
		}
		if (cnt == 0) {
			able.push_back(i);
		}
		else {
			Set(i * 3, 0);
			Set(i * 3 + 1, 0);
			Set(i * 3 + 2, 0);
		}
	}
	/*
001 010 011 100 101 110 111
0   1   2   3   4   5   6
총 7 ^ 10까지(?)

  */
	long long int x = X;

	for (int i = 0; i < able.size(); i++) {


		long long num = x % 7;
		if (num % 2 == 0) {
			Set(able[i] * 3 + 2, 1);
		}
		else {
			Set(able[i] * 3 + 2, 0);
		}
		if ((num % 4) == 0 || (num % 4) == 3) {
			Set(able[i] * 3 + 1, 0);
		}
		else {
			Set(able[i] * 3 + 1, 1);
		}
		if (num >= 3) {
			Set(able[i] * 3, 1);
		}
		else {
			Set(able[i] * 3, 0);
		}

		x /= 7;

	}




	return;
}

long long Bruno(int N, int A[])
{

	long long int p = 1;
	long long num = 0;
	for (int i = 0; i < 50; i++) {
		int cnt = 0;
		for (int j = 0; j < 3; j++) {
			cnt += A[i * 3 + j];
		}
		if (cnt == 0)
			continue;
		else {
			int su = -1;
			su += A[i * 3] * 2 * 2;
			su += A[i * 3 + 1] * 2;
			su += A[i * 3 + 2];
			num += su * p;
			p=p*7;
		}
	}


	//return 123;
	return num;
}