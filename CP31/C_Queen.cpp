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

ll dfs(um<ll,vecll>& tree,vecll& toBeDeleted,int root,int parent,umll& doesRespect){
    ll score = 1;
    for(auto child : tree[root]){
        if(child!=parent){
            score = min<ll>(dfs(tree,toBeDeleted,child,root,doesRespect),score);
        }
    }
    if(score==1 && doesRespect[root]==1 && parent!=-1){
        toBeDeleted.pb(root);
    }
    return doesRespect[root];
}

void solve(){
    ll n;
    cin>>n;
    um<ll,vecll> tree;
    umll doesRespect;
    ll root;
    forn(1,n+1){
        ll parent,respectParent;
        cin>>parent>>respectParent;
        doesRespect[i]=respectParent;
        if(parent==-1){
            root=i;
            continue;
        }
        tree[i].pb(parent);
        tree[parent].pb(i);
    }
    vecll toBeDeleted;
    dfs(tree,toBeDeleted,root,-1,doesRespect);
    if(toBeDeleted.size()==0){
        cout<<-1<<endl;
        return;
    }
    sort(itr(toBeDeleted));
    for(auto node : toBeDeleted){
        cout<<node<<" ";
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