#include <iostream>
#include<string.h>


int main() {
   // freopen("input.txt","rt",stdin);

    char arr[1000002];
    int len;
    int num=1;
    
    scanf("%[^\n]s",arr);
    len=strlen(arr);

    for(int i=0; i<len; i++) 
        if(arr[i]==' ')
            num++;

    if(arr[0]==' ')
        num--;
    
    if(arr[len-1]==' ')
        num--;
    
    printf("%d",num);
    
    return 0;
}