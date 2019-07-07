#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int find(int *parent,int i,int v)
{
        if(i==parent[i])
        {
                return i;
        }
        return find(parent,parent[i],v);
}

void merge(int *parent,int s,int v,int d)
{
        int x=find(parent,s,v);
        int y=find(parent,d,v);
        if(x<y)
        {
                parent[y]=x;
        }
        else
        {
                parent[x]=y;
        }
}

int main()
{
        vector<pair<int,pair<int,int> > >g,res;
        int v,e,w,s,d;
        cin>>v>>e;
        for(int i=0;i<e;i++)
        {
                cin>>w>>s>>d;
                g.push_back(make_pair(w,make_pair(s,d)));
        }
        sort(g.begin(),g.end());
        int parent[v];
        for(int i=0;i<v;i++)
        {
                parent[i]=i;
        }
        for(int i=0;i<e;i++)
        {
                s=g[i].second.first;
                d=g[i].second.second;
                w=g[i].first;
                if(find(parent,s,v)!=find(parent,d,v))
                {
                        res.push_back(g[i]);
                        merge(parent,s,v,d);
                }
        }
        cout<<"The edges of MST are :"<<endl;
        int n=res.size();
        int ws=0;
        for(int i=0;i<n;i++)
        {
                s=res[i].second.first;
                d=res[i].second.second;
                w=res[i].first;
                ws=ws+w;
                cout<<w <<","<<s<<"---"<<d<<endl;
        }
        cout<<"weight of MST is "<<ws<<endl;

return 0;
}


