#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool sortbysec(pair<int,int>a,pair<int,int>b)
{
        return(a.second<b.second);
}
int main()
{
        vector<pair<int,int> >act;
        int e,s,n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>s>>e;
                act.push_back(make_pair(s,e));
        }
        sort(act.begin(),act.end(),sortbysec);
        int c=1;
        int i=0;
        e=act[i].second;
        for(i=1;i<n;i++)
        {
                s=act[i].first;
                if(s>=e)
                {
                        c++;
                        e=act[i].second;

                }
        }
        cout<<c;
return 0;
}
