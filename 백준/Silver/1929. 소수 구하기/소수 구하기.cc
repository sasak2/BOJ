#include <iostream>
#include <math.h>
using namespace std;
int main() {

  int n,m;
  int d = 0;
  int root=0;
  
  scanf("%d %d",&n,&m);
  if (n==1)
    n++;
  for(int i = n; i <= m ; i++) {
     d = 0;
     root=int(sqrt(i));
     for( int k =2; k<= root; k++) {
         if(i%k==0) {
             d=1;
             break;
         }
       
       
     }
     if(d==0)
         printf("%d\n",i);




    
  }
  
}