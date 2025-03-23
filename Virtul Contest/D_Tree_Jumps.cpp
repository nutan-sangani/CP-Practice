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
#define mod 998244353

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

// void countNodeAtLevel(um<ll,vecll>& tree,int root,int parent,int level,umll& nodeCountAtIthLevel){
//     nodeCountAtIthLevel[level]+=1;
//     for(auto child : tree[root]){
//         if(child!=parent){
//             countNodeAtLevel(tree,child,root,level+1,nodeCountAtIthLevel);
//         }
//     }
// }

// ll counti=0;

// void addClipPaths(um<ll,vecll>&tree,int root,int parent,int level,umll& nodeCountAtIthLevel){
//     if(parent==-1){ //means root aaya
//         counti=1;
//         counti+=tree[root].size();
//         counti%=mod;
//         for(auto child : tree[root]){
//             addClipPaths(tree,child,root,level+1,nodeCountAtIthLevel);
//         }
//         return;
//     }
//     if(nodeCountAtIthLevel[level]<=1) return;
//     ll childCount = tree[root].size()-1;
//     counti+=(childCount*(nodeCountAtIthLevel[level]-1));
//     counti%=mod;
//     for(auto child : tree[root]){
//         if(child!=parent){
//             addClipPaths(tree,child,root,level+1,nodeCountAtIthLevel);
//         }
//     }
// }

// void solve(){
//     ll n;
//     cin>>n;
//     counti=1;
//     um<ll,vecll> tree;
//     forn(2,n+1){
//         ll u=i;
//         ll v;
//         cin>>v;
//         tree[u].pb(v);
//         tree[v].pb(u);
//     }
//     umll nodeCountAtIthLevel;
//     countNodeAtLevel(tree,1,-1,0,nodeCountAtIthLevel);
//     addClipPaths(tree,1,-1,0,nodeCountAtIthLevel);
//     cout<<counti<<endl;
// }

void solve(){
    ll n;
    cin>>n;
    ll counti=1;
    um<ll,vecll> tree;
    forn(2,n+1){
        ll u=i;
        ll v;
        cin>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    queue<pll> q;
    q.push(mp(1,0));
    ll endAtPrevLevel = 1;
    umll visited;
    while(!q.empty()){
        ll levelSize=q.size();
        ll thisLevel = 0;
        while(levelSize--){
            pll root = q.front();
            q.pop();
            visited[root.first]=1;
            ll thisChild = endAtPrevLevel-root.second+mod;
            thisChild%=mod;
            for(auto child : tree[root.first]){
                if(visited[child]==0){
                    q.push(mp(child,thisChild));
                    thisLevel+=thisChild;
                    thisLevel%=mod;
                }
            }
        }
        counti+=thisLevel;
        counti%=mod;
        endAtPrevLevel=thisLevel;
    }
    cout<<counti<<endl;
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