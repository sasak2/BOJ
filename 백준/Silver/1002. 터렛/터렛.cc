#include <iostream>
int t;
int x1,x2,y1,y2,r1,r2;
int main(void) {
scanf("%d",&t);
for(int i=0; i<t; i++) {
scanf("%d %d %d %d %d %d",&x1, &y1, &r1, &x2, &y2, &r2);
if(x1==x2&&y2==y1){
if(r1==r2&&r1!=0) 
printf("-1\n");
else if(r1==r2&&r1==0)
printf("1\n");
else
printf("0\n");
continue;
}int d=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));if(r1*r1<d&&r2*r2<d)
if(d==(r1+r2)*(r1+r2)) printf("1\n");
else if(d>(r1+r2)*(r1+r2))printf("0\n");
else printf("2\n");
else if(d==(r1-r2)*(r1-r2)) printf("1\n");
else if(d<(r1-r2)*(r1-r2))printf("0\n");
else printf("2\n");
}return 0;
}