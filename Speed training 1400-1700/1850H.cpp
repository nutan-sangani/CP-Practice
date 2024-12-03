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

bool answer=true;

void dfs(um<ll,vector<pll>>& graph,umll& visited,umll& cost,ll root,ll currCost,ll parent){
    if(answer==false) return;
    if(visited[root]!=0){ //wapis visit kiya toh cost should remain same
        if(currCost!=cost[root]){
            answer=false;
        }
        return;
    }
    cost[root]=currCost;
    visited[root]=1;
    vector<pll> edges = graph[root];
    for(auto edge : edges){
        if(edge.first!=parent)
            dfs(graph,visited,cost,edge.first,currCost+edge.second,root);
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    um<ll,vector<pll>> graph;
    forn(0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].pb(mp(b,-1LL*c));
        graph[b].pb(mp(a,c));
    }
    umll visited;
    umll costFromZero;
    forn(1,n+1){
        if(visited[i]==0){
            dfs(graph,visited,costFromZero,i,0,-1);
        }
        else continue;
    }
    if(answer)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        answer=true;
        solve();
    }
    return 0;
}