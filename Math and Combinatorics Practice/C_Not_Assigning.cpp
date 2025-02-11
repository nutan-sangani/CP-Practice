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

ll getAlternateWeight(ll parentWeight){
    if(parentWeight==2) return 5;
    else return 2;
}

void dfs(um<ll,vector<pll>>& tree,vecll& weights,ll root,ll parent,ll parentWeight){
    if(tree[root].size()==1 && parent!=-1) return;
    if(parentWeight==-1){
        weights[tree[root][0].second]=2;
        dfs(tree,weights,tree[root][0].first,root,2);
        if(tree[root].size()==2){
            weights[tree[root][1].second]=5;
            dfs(tree,weights,tree[root][1].first,root,5);
        }
        return;
    }
    vector<pll> temp = tree[root];
    for(pll edge : temp){
        if(edge.first==parent) continue;
        if(weights[edge.second]==-1){
            ll currWeight = getAlternateWeight(parentWeight);
            weights[edge.second]=currWeight;
            dfs(tree,weights,edge.first,root,currWeight);
        }
    }
    return;
}

void solve(){
    ll n;
    cin>>n;
    um<ll,vector<pll>> tree;
    ll maxSize = 0;
    vecll weights(n,-1);
    forn(1,n){
        ll a,b;
        cin>>a>>b;
        tree[a].pb(mp(b,i));
        maxSize = max<ll>(maxSize,tree[a].size());
        tree[b].pb(mp(a,i));
        maxSize = max<ll>(maxSize,tree[b].size());
    }
    if(maxSize>2){
        cout<<-1<<endl;
        return;
    }
    dfs(tree,weights,1,-1,-1);
    forn(1,n){
        cout<<weights[i]<<" ";
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
        solve();
    }
    return 0;
}