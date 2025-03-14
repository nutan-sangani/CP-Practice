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

bool isColorPresent(ll root,ll parent,um<ll,vecll>& tree,vecll& color,ll level,ll colorNeeded,um<ll,umll>& countOfColor){
    if(level==2){
        if(countOfColor[root][colorNeeded]>1) return true;
        else return false;
    }
    else{
        if(countOfColor[root][colorNeeded]>=1) return true;
        bool isPresent = false;
        for(auto child : tree[root]){
            isPresent = isPresent | isColorPresent(child,root,tree,color,level+1,colorNeeded,countOfColor);
            if(isPresent) return true;
        }
        return false;
    }
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n+1,-1);
    forn(1,n+1){
        cin>>a[i];
    }
    um<ll,vecll> tree;
    um<ll,umll> countOfColor;
    forn(0,n-1){
        ll u,v;
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    for(auto root : tree){
        vecll temp = root.second;
        forn(0,temp.size())
            countOfColor[root.first][a[temp[i]]]+=1;
    }
    umll colorPresent;
    forn(1,n+1){
        if(isColorPresent(i,-1,tree,a,1,a[i],countOfColor)){
            colorPresent[a[i]]=1;
        }
    }
    forn(1,n+1){
        cout<<colorPresent[i];
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