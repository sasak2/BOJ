#include<iostream>
#include<queue>
using namespace std;

int n,m;

struct Map{

int depth=0;
char map[13][13];

}default_map;

queue <Map> map;

int ThereAreNoRedBall(char temp[13][13]) {
  int num=0;
  for(int i=0; i<n; i++) 
    for(int k=0; k<m; k++)
      if(temp[i][k]=='R') 
        num++;
  return num;
}

int TheTwoArrayIsSame(char one[13][13],char two[13][13]) {
  int d=0;
  for(int i=0; i<n; i++) {
    for(int k=m-1; k>=0; k--) {
      if(one[i][k]!=two[i][k]) {
        d=1;
        break;
      }
    }
    if(d==1) break;
  }
  return d;
}

Map TiltUP(Map temp) {
  for(int i=0; i<n; i++) {
    for(int k=0; k<m; k++) {
      if(temp.map[i][k]=='#'||temp.map[i][k]=='O'||temp.map[i][k]=='.') continue;
      else {
        int TEMP_I=i-1;
        while(1) {
          if(temp.map[TEMP_I][k]=='.') {
            TEMP_I--;       
            continue;
          }
          else if(temp.map[TEMP_I][k]=='O') {
            if(temp.map[i][k]=='B') {
                temp.depth=-2;
                return temp;
                }
              temp.map[i][k]='.';
              break;
            }  
          else {
            if (TEMP_I+1!=i) {
              temp.map[TEMP_I+1][k]=temp.map[i][k];
              temp.map[i][k]='.';
            }
            break;
          }
        }
      }
    }
  }
  temp.depth++;
  return temp;
}
Map TiltDOWN(Map temp) {
  for(int i=n-1; i>=0; i--) {
    for(int k=0; k<m; k++) {
      if(temp.map[i][k]=='#'||temp.map[i][k]=='O'||temp.map[i][k]=='.') continue;
      else {
        int TEMP_I=i+1;
        while(1) {
          if(temp.map[TEMP_I][k]=='.') {
            TEMP_I++;       
            continue;
          }
            else if(temp.map[TEMP_I][k]=='O') {
              if(temp.map[i][k]=='B') {
                temp.depth=-2;
                return temp;
                }
              temp.map[i][k]='.';
              break;
            }
          else {
            if (TEMP_I-1!=i) {
              temp.map[TEMP_I-1][k]=temp.map[i][k];
              temp.map[i][k]='.';
            }
            break;
          }
        }
      }
    }
  }
  temp.depth++;
  return temp;
}
Map TiltLEFT(Map temp) {
  for(int i=0; i<n; i++) {
    for(int k=0; k<m; k++) {
      if(temp.map[i][k]=='#'||temp.map[i][k]=='O'||temp.map[i][k]=='.') continue;
      else {
        int TEMP_K=k-1;
        while(1) {
          if(temp.map[i][TEMP_K]=='.') {
            TEMP_K--;       
            continue;
            }
            else if(temp.map[i][TEMP_K]=='O') {
              if(temp.map[i][k]=='B') {
                temp.depth=-2;
                return temp;
                }
              temp.map[i][k]='.';
              break;
            }
            else {
            if (TEMP_K+1!=k) {
              temp.map[i][TEMP_K+1]=temp.map[i][k];
              temp.map[i][k]='.';
            }
            break;
          }
        }
      }
    }
  }
  temp.depth++;
  return temp;
}
Map TiltRIGHT(Map tempone) {
  Map temp=tempone;
  for(int i=0; i<n; i++) {
    for(int k=m-1; k>=0; k--) {
      if(temp.map[i][k]=='#'||temp.map[i][k]=='O'||temp.map[i][k]=='.') continue;
      else {
        int TEMP_K=k+1;
        while(1) {
          if(temp.map[i][TEMP_K]=='.') {
            TEMP_K++;       
            continue;}
            else if(temp.map[i][TEMP_K]=='O') {
              if(temp.map[i][k]=='B') {
                temp.depth=-2;
                return temp;
                }
              temp.map[i][k]='.';
              break;    
          }else {
            if (TEMP_K-1!=k) {
              temp.map[i][TEMP_K-1]=temp.map[i][k];
              temp.map[i][k]='.';
            }
            break;
          }
        }
      }
    }
  }
  temp.depth++;
  
  return temp;
}

int BFS(void) {
  while (1){
  if(map.front().depth>10)
    return -1;
  if(map.front().depth==-2) {
    map.pop();
    continue;
  }
  if(map.empty()==1) return -1;
  if(ThereAreNoRedBall(map.front().map)==0)
    return map.front().depth;
  
  if(TheTwoArrayIsSame(map.front().map,TiltUP(map.front()).map)==1)
    map.push(TiltUP(map.front()));

 if(TheTwoArrayIsSame(map.front().map,TiltDOWN(map.front()).map)==1)
    map.push(TiltDOWN(map.front()));
            if(TheTwoArrayIsSame(map.front().map,TiltLEFT(map.front()).map)==1)
  map.push(TiltLEFT(map.front()));
    if(TheTwoArrayIsSame(map.front().map,TiltRIGHT(map.front()).map)==1)
  map.push(TiltRIGHT(map.front()));
    
  map.pop();
  
  }
}

int main(void) {
	scanf("%d %d",&n, &m);
	for(int i=0; i<n; i++) 
			scanf("%s%c",default_map.map[i]);
  map.push(default_map);
  printf("%d",BFS());
	return 0;
}