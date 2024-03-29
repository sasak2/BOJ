#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int r,c;
char map[1502][1502];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int unf[1502][1502];
int L1=-1,L2;
int rnk[1502][1502];



int root(int x) {
    if(unf[x/1500][x%1500]==x)
        return x;
    return root(unf[x/1500][x%1500]);
}

void merge(int x,int y) {
int a,b;
    a=root(x);
    b=root(y);
    if(a==b) {
        return;}
    else {
        if(rnk[a/1500][a%1500]==rnk[b/1500][b%1500]) {
            rnk[a/1500][b%1500]++;
        }
if(rnk[a/1500][a%1500]>rnk[b/1500][b%1500]) {
    unf[b/1500][b%1500]=a;
}
        else {
            unf[a/1500][a%1500]=b;
        }
      //  unf[b/1500][b%1500]=a;
    }
    
}
queue<int> icemelt;
int IceWillMeltCount=0;
int IceWillMeltCount2=0;
int main() {
   // freopen("in3.txt","rt",stdin);

    scanf("%d %d",&r,&c);

    for(int i=0;i<r; i++) {
        scanf("%s",map[i]);    
        for(int k=0; k<c;k++) {
            rnk[i][ k]=0;
            if(map[i][k]=='L') {
                if(L1==-1)
                    L1=i*1500+k;
                else
                    L2=i*1500+k;
                }
            if(map[i][k]!='X') {
                icemelt.push((i)*1500+(k));
                IceWillMeltCount++;
            
                }
            }
        
        }

    for(int i=0;i<r;i++) 
        for(int k=0;k<c;k++) 
            unf[i][k]=i*1500+k;
    
    for(int i=0;i<r;i++) {
        for(int k=0;k<c;k++) {
            if(map[i][k]!='X')
                for(int d=0;d<4;d++) {
                    if(i+dx[d]<0||k+dy[d]<0||i+dx[d]>=r||k+dy[d]>=c)
                        continue;
                    if(map[i+dx[d]][k+dy[d]]!='X') {
                        merge((i+dx[d])*1500+k+dy[d],i*1500+k);
                        
                    }
                        
                }
            
        }
       
    }

    

    
    int time=0;
    int asdf=0;
    
    while(1) {

        if(root(L1)==root(L2)) {
            printf("%d",time==0?0:time-1);
            return 0;
        }
        time++;

        


        /*
        for(int i=0;i<r;i++) {
            for(int k=0;k<c;k++) {
                if(map[i][k]=='X') {
                    for(int d=0; d<4; d++) {
                        if(i+dx[d]<0||k+dy[d]<0||i+dx[d]>=r||k+dy[d]>=c)
                        continue;
                        if(map[i+dx[d]][k+dy[d]]!='X') {
                            icemelt.push((i)*1500+(k));
                            break;
                        }
                    }
                }   
            }
        }
*/
        //----------------------------------
        
        for(int l=0;l<IceWillMeltCount;l++) {
            int ii=icemelt.front()/1500;
            int ik=icemelt.front()%1500;
            icemelt.pop();
            if(map[ii][ik]=='.')
                if(asdf==1)
                continue;
            map[ii][ik]='.';
            for(int d=0; d<4; d++) {
                if(ii+dx[d]<0||ik+dy[d]<0||ii+dx[d]>=r||ik+dy[d]>=c)
                        continue;
                icemelt.push((ii+dx[d])*1500+ik+dy[d]);
                IceWillMeltCount2++;
            }

            
            for(int d=0; d<4; d++) {
                if(ii+dx[d]<0||ik+dy[d]<0||ii+dx[d]>=r||ik+dy[d]>=c)
                        continue;
                if(map[ii+dx[d]][ik+dy[d]]!='X') {
                    int rootice = (ii+dx[d])*1500+ik+dy[d];
                    merge(rootice,ii*1500+ik);
                }
                
            }
            
        }
        

        IceWillMeltCount=IceWillMeltCount2;
        IceWillMeltCount2=0;


        asdf=1;
    }

                       

    

    return 0;
}