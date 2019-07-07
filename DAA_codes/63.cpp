#include <bits/stdc++.h>
using namespace std;
#define max 10

int graph[max+1][max+1];
int visited[max+1];
int vertices;
bool res=false;

void dfs(int s) {
    visited[s] = 1;
    for(int i=1;i<=vertices;i++){
        if(graph[s][i]){
            if(visited[i]==1){
                res=true;
            }
            else if(visited[i]==0){
                dfs(i);
            }
        }
    }
    visited[s]=2;
}

int main() {
    //Number of vertices
    cin >> vertices;
    for(int i = 1;i <= vertices;i++){
        for(int j = 1;j <= vertices;j++){
            cin >> graph[i][j];
        }

    }
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=vertices;i++){
        if(visited[i]==0)
            dfs(1);
    }
    if(res){
        cout << "Yes Cycle Exsists\n";
    }else{
        cout << "No Cycle Exsists\n";
    }
    return 0;
}
