#include <iostream>
using namespace std;
int main(){

int n,a=0;
    int x=0;
scanf("%d",&n);
    int nn=n;
    while(n--){
int aa;
    scanf("%d",&aa);
        if(aa==0)x++;
    a+=aa;}
//APPROVED, 통과되지 않았으면 REJECTED, 무효 처리되었으면 INVALID를 출력
if(x*2>=nn){printf("INVALID");return 0;}
    if(a>0) {
    printf("APPROVED");
}else 
    printf("REJECTED");
    
}
