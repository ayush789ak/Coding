#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int graph[MAX][MAX],vertices,dist[MAX];
bool vis [MAX];
vector<int> p_list[MAX];

void printPath(int parent[], int j){
    if (parent[j]==-1)
        return;
    cout << j << " ";
    printPath(parent, parent[j]);
}

int min(){
	int minimum=INT_MAX,pos;
	for(int i=1;i<=vertices;i++){
		if(!vis[i] && dist[i]<=minimum){
			minimum=dist[i];
			pos=i;
		}
	}
	return pos;
}

void printsol(int parent[],int src){
	for(int i=1;i<=vertices;i++){
		printPath(parent, i);
		cout << src << " : " << dist[i] <<endl;
	}
}

void dijkstra(int src){
	int parent[vertices];
	memset(vis, false , sizeof(vis));
	memset(dist, 9999 , sizeof(dist));
	memset(parent,-1,sizeof(parent));
    dist[src] = 0;
    for(int i=1;i<=vertices;i++){
    	int x=min();
    	vis[x]=true;
    	if(dist[x]!=INT_MAX){
	    	for(int j=1;j<=vertices;j++){
	    		if(!vis[j] && graph[x][j] && ((dist[x]+graph[x][j]) < dist[j])){
	    			parent[j]=x;
	    			dist[j]=dist[x]+graph[x][j];
	    		}
	    	}
    	}
    }
	printsol(parent,src);
}

int main(){
	int src;
	cin >> vertices;
	for(int i=1;i<=vertices;i++)
		for(int j=1;j<=vertices;j++)
			cin >> graph[i][j];
	cin >> src;
	dijkstra(src);
	return 0;
}
