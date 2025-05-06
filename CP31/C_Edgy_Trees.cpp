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

ll dfs(int root,um<ll,vecll>& tree,vecll& visited){
    visited[root]=1;
    ll count=0;
    for(auto child : tree[root]){
        if(visited[child]==0){
            count+=dfs(child,tree,visited);
        }
    }
    return count+1;
}

ll binaryExponent(ll a,ll b,ll m){ //(a^b)%m
    ll ans = 1;
    ll base = a;
    while(b>0){
        if(b & 1){
            ans*=base;
            ans%=m;
        }
        base*=base;
        base%=m;
        b/=2;
    }
    return ans%m;
}

void solve(){
    ll n,k;
    cin>>n>>k; 
    um<ll,vecll> tree;
    forn(0,n-1){
        ll u,v,c;
        cin>>u>>v>>c;
        if(c==0){
            tree[u].pb(v);
            tree[v].pb(u);
        }
    }
    vecll visited(n+1,0);
    ll nonGood = 0;
    forn(1,n+1){
        if(visited[i]==0){
            ll nodesInNonGoodComponent = dfs(i,tree,visited);
            nonGood+=binaryExponent(nodesInNonGoodComponent,k,mod);
            nonGood%=mod;
        }
    }
    ll total = binaryExponent(n,k,mod);
    total+=mod;
    total -= nonGood;
    total%=mod;
    cout<<total<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}