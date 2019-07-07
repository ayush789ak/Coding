#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<double,pair<int,int> >a,pair<double,pair<int,int> >b)
{
        return a.first>b.first;
}
int main()
{
        vector<pair<double,pair<int,int> > >item;
        int n,v,w,k;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>v>>w;
                item.push_back(make_pair((double)v/w,make_pair(v,w)));
        }
        sort(item.begin(),item.end(),compare);
        cin>>k;
        double pro=0.0,r=0.0;
        for(int i=0;i<n;i++)
        {
                if(k<=0)
                        break;
                v=item[i].second.first;
                w=item[i].second.second;
                r=item[i].first;
                if(w<=k)
                {
                        pro=pro+v;
                        k=k-w;
                }
                else
                {
                        pro=pro+k*r;
                        k=0;

                }
        }
        cout<<pro;
return 0;
}
