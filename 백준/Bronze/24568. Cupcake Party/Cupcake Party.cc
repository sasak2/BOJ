#include <bits/stdc++.h>
using namespace std;
int rBox, sBox, ans;
int main(){//2345789-23457890527934
    cin >> rBox >> sBox;
    ans = rBox * 8 + sBox * 3 - 28;
    if(ans < 0) ans = 0;
    cout << ans;
}