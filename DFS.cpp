#include<bits/stdc++.h>
using namespace std;
void dfs(int u,vector<int>adj[],vector<bool>&vis,vector<pair<int,int>>&time)
{
    stack<int> s;
    int tt=0;
    s.push(u);
    vis[u]=true;
    time[u].first=tt++;
    while(!s.empty())
    {
        int node=s.top();
        if(!vis[node])
        {
            vis[node]=true;
            time[node].first=tt++;
        }
        bool flag=false;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                s.push(it);
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            time[node].second=tt++;
            s.pop();
        }
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int,int>> time(v,{0,0});
    vector<bool> vis(v,false);
    dfs(0,adj,vis,time);
    for(int i=0;i<v;i++)
    {
        cout<<time[i].first<<" "<<time[i].second<<endl;
    }
    cout<<endl;
    return 0;
}
