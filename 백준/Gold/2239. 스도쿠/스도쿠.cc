#include<stdio.h>

int map[99][99];

int s,ss,ssss;

void printtt(int t) {
    for(int i=0; i<ss; i++) {
        for(int k=0; k<ss; k++) {
            printf("%d",map[i][k]-48);
        }
        printf("\n");
    }
    //printf("\n\n\n%d\n\n\n",t);
    return;
}

int able(int x,int y, int a) {
        for(int i=0; i<ss; i++) {
            if(map[x][i]==a||map[i][y]==a) 
                return 1;
            if(map[(x/s)*s+(i/s)][(y/s)*s+(i%s)]==a) 
                return 1;
        }
    return 0;
}

int dfs(int depth) {
    //printtt(depth);
    if(depth==ssss) {
        printtt(0);
        return -99;
    }
    int wow= map[depth/ss][depth%ss];
	if(wow!='0'&&wow!=0) 
        return dfs(depth+1);

    for(int i=0; i<ss; i++) {
        if(able(depth/ss,depth%ss,i+49)==0) {
            int f;
            map[depth/ss][depth%ss]=i+49;
            f=dfs(depth+1);
            if(f==-99) return -99;
            map[depth/ss][depth%ss]=0;
        }
    }
    
        
    return 0;
}

int main(void) {

    char z;

    //freopen("input.txt","rt",stdin);
    //scanf("%d",&s);
    s=3;
    ss=s*s;
    ssss=ss*ss;
	for(int i=0; i<ss; i++) {
		for(int k=0; k<ss; k++) {
            scanf("%c",&map[i][k]);
			
			}
		scanf("%c",&z);
		}


    dfs(0);
    
	return 0;
}
