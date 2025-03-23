#include <iostream>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll,custom_hash>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void dfs(vecll& visited,um<ll,set<ll>>& graph,ll root,umll& nodeToComponent,ll component){
    visited[root]=1;
    nodeToComponent[root]=component;
    for(auto it : graph[root]){
        if(visited[it]==-1){
            dfs(visited,graph,it,nodeToComponent,component);
        }
    }
}

void dfs2(vecll& visited,um<ll,set<ll>>& graph,ll root,umll& nodeToComponent){
    visited[root]=1;
    for(auto it : graph[root]){
        if(visited[it]==-1 && nodeToComponent[it]==nodeToComponent[root]){
            dfs2(visited,graph,it,nodeToComponent);
        }
    }
}

void solve(){
    ll n,m1,m2;
    cin>>n>>m1>>m2;
    um<ll,set<ll>> f,g;
    forn(0,m1){
        ll u,v;
        cin>>u>>v;
        f[u].insert(v);
        f[v].insert(u);
    }
    forn(0,m2){
        ll u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    ll count=0;
    vecll visited(n+1,-1);
    umll nodeToComponent;
    ll componentNo = 1;
    forn(1,n+1){
        if(visited[i]==-1){
            dfs(visited,g,i,nodeToComponent,componentNo);
            componentNo+=1;
        }
    }
    forn(1,n+1){
        ll componentOfRoot = nodeToComponent[i];
        for(auto it : f[i]){
            if(nodeToComponent[it]!=componentOfRoot){
                count+=1;
                f[it].erase(i);
            }
        }
    }
    umll componentCount;
    vecll visited2(n+1,-1);
    forn(1,n+1){
        if(visited2[i]==-1){
            dfs2(visited2,f,i,nodeToComponent);
            componentCount[nodeToComponent[i]]+=1;
        }
    }
    for(auto it : componentCount){
        count+=(it.second-1);
    }
    cout<<count<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}