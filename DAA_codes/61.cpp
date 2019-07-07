#include <bits/stdc++.h>
using namespace std;
#define max 10

int graph[max+1][max+1];
bool visited[max+1];
int vertices,source,dest;

void dfs(int s) {
    visited[s] = true;
    for(int i = 1;i <= vertices;i++)    {
     if(graph[s][i] && visited[i] == false)
         dfs(i);
    }
}

void initialize() {
    for(int i = 0;i <= max;++i)
     visited[i] = false;
}

int main() {
    //Number of vertices
    cin >> vertices;
    for(int i = 1;i <= vertices;i++){
        for(int j = 1;j <= vertices;j++){
            cin >> graph[i][j];
        }
    }
    initialize();                           //Initialize all nodes as not visited
    cin >> source >> dest;
    dfs(source);
    if(visited[dest]){
        cout << "Yes Path Exsists\n";
    }else{
        cout << "No Such Path Exsists\n";
    }
    return 0;
}
