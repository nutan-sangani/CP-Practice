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

ll dfs(vecll& visited,int root,umll& componentOf,ll component,um<ll,vecll>& graph,int n){
    visited[root]=1;
    ll size=0;
    if(root<=n){
        componentOf[root]=component;
        size+=1;
    }
    for(auto neighbour : graph[root]){
        if(visited[neighbour]==0){
            ll temp = dfs(visited,neighbour,componentOf,component,graph,n);
            size+=temp;
        }
    }
    return size;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    um<ll,vecll> graph;
    forn(n+1,m+n+1){
        ll k;
        cin>>k;
        for(int j=0;j<k;j++){
            ll v;
            cin>>v;
            graph[i].pb(v);
            graph[v].pb(i);
        }
    }
    vecll visited(n+m+1,0);
    umll componentOf;
    umll sizeOfComponent;
    ll count=0;
    forn(0,n){
        if(visited[i+1]==0){
            ll nodes = dfs(visited,i+1,componentOf,count,graph,n);
            sizeOfComponent[count]=nodes;
            count+=1;
            cout<<nodes<<" ";
        }
        else{
            ll component = componentOf[i+1];
            ll size = sizeOfComponent[component];
            cout<<size<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}