#include <bits/stdc++.h>
using namespace std;
#define max 10

int graph[max+1][max+1];
int colour[max+1];
int vertices;

bool bfs(int s) {
    colour[s] = 1;
    queue <int> Q;
    Q.push(s);
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        if(graph[temp][temp])
            return false;
        for(int i=1; i<=vertices; i++){
            if(graph[temp][i] && colour[i]==-1){
                colour[i]=1-colour[temp];
                Q.push(i);
            }else if(graph[temp][i] && colour[temp]==colour[i])
                return false;
        }
    }
    return true;
}

int main() {
    //Number of vertices
    cin >> vertices;
    for(int i = 1;i <= vertices;i++){
        for(int j = 1;j <= vertices;j++){
            cin >> graph[i][j];
        }

    }
    memset(colour,-1,sizeof(colour));
    if(bfs(1)){
        cout << "Yes Bipartite\n";
    }else{
        cout << "No Bipartite\n";
    }
    return 0;
}
