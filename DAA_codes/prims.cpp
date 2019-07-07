#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool isfalse(int* visited,int v)
{
        for(int i=0;i<v;i++)
        {
                if(visited[i]==0)
                        return true;
        }
        return false;
}
int extract_min(int*key,int v)
{
        swap(&key[0],&key[v-1]);
        int ret=a[v-1];
        v--;
        heapify(key,v,0);
        return ret;
}
void heapify(int *key,int v,int i)
{
        int c1=2*i+1;
        int c2=2*i+2;
        int smallest=i;
        if(c1<v&&key[smallest]>key[c1])
        {
                smallest=c1;
        }
        if(c2<v&&key[smallest]>key[c1])
        {
                smallest=c2;
        }
        if(smallest!=i)
        {
                swap(&key[smallest],&key[i]);
                heapify(key,v,smallest);
        }

}
void swap(int* a,int* b)
{
        int c;
        c=a;
        a=b;
        b=c;


}

int main()
{
        int v,e,s,d,w;
        cin>>v>>e;
        int g[v][v]={};
        for(int i=0;i<e;i++)
        {
                cin>>w>>s>>d;
                g[s][d]=w;
                g[d][s]=w;
        }
        int parent[v],key[v],visited[v];
        for(int i=0;i<v;i++)
        {
                parent[i]=-1;
                key[i]=INT_MAX;
                visited[i]=0;
        }
        key[0]=0;
        while(isfalse(visited,v))
        {
                s=extract_min(key,v);
                for(int i=0;i<v;i++)
                {
                        if(g[s][i!=INT_MAX && visited[i]==0)
                        {
                                if(key[i]>g[s][i])
                                {
                                        key[i]=g[s][i];
                                        parent[i]=s;
                                }


                        }
                }
                visited[s]=1;


        }
}
