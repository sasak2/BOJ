#include <iostream>
#include<string.h>


int main() {
  //  freopen("input.txt","rt",stdin);

    char arr[1000002];
    int len;
    int count[40]={0,};
    int maxch=0;
    int d=1;
    
    scanf("%s",arr);
    len=strlen(arr);

    for(int i=0; i<len; i++) {
        count[(arr[i]-65)%32]++;
    }
    
    for(int i=66;i<=90 ;i++) {
        if(count[i-65]>count[maxch]) {
            maxch=i-65;
            d=1;
        }
        else if(count[i-65]==count[maxch]) {
            maxch=i-65;
            d=0;
        }
    }
    if(d==0) printf("?");
    else printf("%c",maxch+65);
    
    return 0;
}