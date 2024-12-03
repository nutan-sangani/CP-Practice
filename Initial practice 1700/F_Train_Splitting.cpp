#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

int visitedCount=0;

void dfs(um<ll,vecll>& graph,umll& visited,int root,set<pll>& selectedEdgePairs,int n){
    visitedCount+=1;
    visited[root]=1;
    if(visitedCount==n){
        return;
    }
    vecll children = graph[root];
    for(auto child : children){
        if(visited[child]==0){
            selectedEdgePairs.insert(mp(root,child));
            dfs(graph,visited,child,selectedEdgePairs,n);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    um<ll,vecll> graph;
    umll visited;
    vector<pll> edges;
    vecll ans(m+1,0);
    set<pll> selectedEdgePairs;
    forn(0,m){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
        edges.pb(mp(u,v));
    }
    dfs(graph,visited,1,selectedEdgePairs,n);
    forn(0,m){
        if(selectedEdgePairs.count(mp(edges[i].first,edges[i].second))==1 
         || selectedEdgePairs.count(mp(edges[i].second,edges[i].first))==1){
            ans[i]=1;
            if(selectedEdgePairs.size()==1){
                ans[i]=2;
            }
            if(selectedEdgePairs.count(mp(edges[i].first,edges[i].second))){
                selectedEdgePairs.erase(mp(edges[i].first,edges[i].second));
            }
            else{
                selectedEdgePairs.erase(mp(edges[i].second,edges[i].first));
            }
        }
    }
    ll count=3;
    forn(0,m){
        if(ans[i]==0){
            ans[i]=count;
            ++count;
        }
    }
    cout<<count-1<<endl;
    forn(0,m){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        visitedCount = 0;
        solve();
    }
    return 0;
}