#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define mt(x,y,z) make_tuple(x,y,z)
#define x first
#define y second
#define MOD 1000000007
#define X dx[d]
#define Y dy[d]

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <complex>
#define ll long long int
using namespace std;

/*
1796
싱기방구 키보드

dp i k j = i칸에서 시작해서 k칸에서 끝냄
근데이제 알파벳 j를 다 지움

이게 dp j 한 줄을 50*50이면 알수있음
i k j 는 왼쪽으로도 가보고 오른쪽으로 가보고 두번만 해보면 알수있다.

*/

char s[55];
int len;

char ch_중복=' ';
int 중복수=0;
pii 중복위치;

pii return_fisrt_and_final_position_of_ch(char ch) {
	//printf("|%d %d %d|",중복위치.first,중복위치.second,중복수);
	if(ch==ch_중복) return 중복위치;
	중복위치.first=-1;
	중복수=0;
	ch_중복=ch;
	for(int i=0; i<len; i++) {
		if(s[i]==ch&&중복위치.first==-1) {
			중복위치.first=i;
		}
		if(s[i]==ch) {
			중복위치.second=i;
			중복수++;
		//	printf("?%d %d %d %d?",ch,ch_중복,i,s[i]);
		}
	}
	return 중복위치;
}

int click_cnt(int s, int e, char ch) {
	//s에서 시작헤서 ch를 다 지우고e로 올끄야
	pii posi=return_fisrt_and_final_position_of_ch(ch);
	int posi_s=posi.first;
	int posi_e=posi.second;

	if(posi_s==-1) return abs(e-s);
	if(posi_s==posi_e) return abs(s-posi_s)+1+abs(posi_e-e);
	//왼쪽으로도 가보고 오른쪽으로도 가보자
	int temp;
	temp = min(
		abs(s-posi_s)+중복수+abs(posi_e-e)+abs(posi_s-posi_e),
		abs(e-posi_s)+중복수+abs(posi_e-s)+abs(posi_s-posi_e));

	//printf("!%d!",
	//	min(
	//	abs(e-posi_s)+중복수+abs(posi_e-s)+abs(posi_s-posi_e),
	//	abs(s-posi_s)+중복수+abs(posi_e-e)+abs(posi_s-posi_e)
	//	));
//
	//printf("/%d/",temp);
	
	
	return temp;
}

int dp[55][55][30];

int main() {
	//freopen("input.txt","rt",stdin);

	cin>>s;
	
	len=strlen(s);

	for(int i=0; i<len; i++) {
		s[i]-='a';
		//printf("%d",s[i]);
	}


	int alphabet=26;
	//alphabet=3;
	//야 이거 26까지로 바꿔야한다 알겠냐?
	for(int j=0; j<alphabet; j++) {
		for(int i=0; i<len; i++) {

			int tempmin=2147483647;
			if(j==0) {
				tempmin=i;
				//i=len-1;
				goto skip;
				//사끼야악 고투문이다!!!
			}
      for(int a=0; a<len; a++) {
				tempmin=min(tempmin,dp[a][i][j-1]);
				//이게 j-1==-1이면 error라서
				//고투를 쓸수밖에 없었다....
			}
			skip:
		//	printf(" temp = %d ",tempmin);
			//사끼야아아악 고투문이다!!!!
			for(int k=0; k<len; k++) {
			//dp ? i j-1 중 가장 작은거를 골라야함ㅇㅅㅇ
				dp[i][k][j]=tempmin+click_cnt(i, k, j);

				//printf("%d ",dp[i][k][j]);
			}
			//cout<<endl;
		}
		//cout<<endl<<endl<<"j="<<j+1<<endl;
	}

	int ans=2147483647;
	for(int i=0; i<len; i++) {
		for(int k=0; k<len; k++) {
			ans=min(ans,dp[i][k][alphabet-1]);
		}
	}
	
	cout<<ans;
	return 0;
}