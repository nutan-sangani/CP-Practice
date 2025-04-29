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

ll findDistanceToLeaf(int root,int parent,um<ll,vecll>& tree){
    //since only 2 leafs, therefore only 2 childs hi honge usse jyada hohi nhi sakte h
    if(parent==-1){
        vecll distances;
        for(auto child : tree[root]){
            distances.pb(findDistanceToLeaf(child,root,tree));
        }
        for(auto dist : distances){
            if(dist%2!=0){
                cout<<"Ron"<<endl;
                return -1;
            }
        }
        cout<<"Hermione"<<endl;
        return -1;
    }
    ll dist = 0;
    for(auto child : tree[root]){
        if(child!=parent){
            dist = findDistanceToLeaf(child,root,tree);
        }
    }
    return dist+1;
}

void solve(){
    ll n,t;
    cin>>n>>t;
    um<ll,vecll> tree;
    forn(0,n-1){
        ll u,v;
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    ll root;
    cin>>root;
    findDistanceToLeaf(root,-1,tree);
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}