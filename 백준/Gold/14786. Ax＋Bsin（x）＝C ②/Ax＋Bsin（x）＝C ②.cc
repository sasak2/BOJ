#define PI 3.14159265358979
#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// 14786 Ax+Bsin(x)=C ②

long double a, b, c;

/*
        자 일단 메인 뽀인뜨!
        일단 저게 증가는 하는거니까
  이분탐색 렛츠고
*/

long double f(long double x) { return a * x + b * sin(x); }

int main() {
 // freopen("input.txt", "rt", stdin);

  scanf("%Lf %Lf %Lf", &a, &b, &c);

  long double s = 0, e = 100000, m;
  for (int i = 0; i < 100; i++) {
    m = (s + e) / 2.0;

    // printf("%.10Lf\n",f(m));
    if (c > f(m)) {
      s = m;
    } else
      e = m;
  }

  printf("%.20Lf", m);

  return 0;
}