#define ll (long long int)

#include<iostream>
#include<algorithm>
#include<vector>


/*
두둥둥장


*/

using namespace std;

int n;
long long int D = 0, G = 0;


vector<vector<int>> graph(300030);

//(long long int)

int main() {
  //  freopen("input.txt", "rt", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    for (int i = 0; i < n; i++) {
        if (graph[i].size() < 3) continue;
        else G += ll(graph[i].size()) * ll(graph[i].size() - 1) * ll(graph[i].size() - 2) / 6;
    }
    for (int i = 0; i < n; i++) {
        int a = i;
        for (int k = 0; k < graph[a].size(); k++) {
            int b = graph[a][k];


            D += ll(graph[a].size() - 1)*ll(graph[b].size() - 1);
        }
    }

    G *= 2;

    //printf("G%lld D%lld", G, D);

    if (D == G * 3) printf("DUDUDUNGA");
    else if (D > G * 3) printf("D");
    else printf("G");



    return 0;
}