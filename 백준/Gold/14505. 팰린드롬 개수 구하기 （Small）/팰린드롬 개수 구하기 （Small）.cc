#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

char ch[32];
int len;
int sum=0;

int arr[32][32];



void dfs(int s,int e) {
//if(arr[s][e]==0) return;
    int n=arr[s][e];
arr[s][e]=0;

    for(int i=0;i<s;i++) {
        for(int k=e+1; k<len;k++) {
           
            if(ch[i]==ch[k]) {
                arr[i][k]+=n;
                
                sum+=n;
                //dfs(i,k);
            }
        }
    }
}




int main() {
   // freopen("input.txt","rt",stdin);

    scanf("%s",ch);

    len = strlen(ch);
    
    for(int i=0;i<len; i++) {
        for(int k=0;k<len;k++) {
            arr[i][k]=0;
            
        }
    }

    for(int i=0;i<len; i++) {
        for(int k=i;k<len;k++)
            if(ch[i]==ch[k]) {
                arr[i][k]++;
                sum++;
                
            }
    }

    while(1) {
        int d=0;
        for(int i=0;i<len;i++) {
            for(int k=i;k<len;k++) {
                if(arr[i][k]!=0) {
                dfs(i,k);
                    d=1;
                }
            }
        }
        if(d==0) break;
    }



    printf("%d",sum);
    return 0;
}