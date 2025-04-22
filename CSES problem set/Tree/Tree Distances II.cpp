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

ll fillSubTreeSizeAndIn(int root,int parent,um<ll,vecll>& tree,umll& in,umll& subTreeSize,umll& out){
    ll sumOfSubTreeSize=0;
    ll sumOfIn=0;
    for(auto child : tree[root]){
        if(child!=parent){
            sumOfIn+=fillSubTreeSizeAndIn(child,root,tree,in,subTreeSize,out);
            sumOfSubTreeSize+=subTreeSize[child];
        }
    }
    subTreeSize[root]+=sumOfSubTreeSize+1;
    out[root]+=(sumOfIn+2LL*sumOfSubTreeSize);
    return in[root]+=(sumOfIn+sumOfSubTreeSize);
}

void fillAnsAndOut(int grandParent,int root,int parent,um<ll,vecll>& tree,umll& in,umll& out,umll& ans,umll& subTreeSize,ll n,umll& siblingStore){
    ll temp=0;
    if(parent!=-1){
        temp+=(out[parent]+(n-subTreeSize[parent]+1));
        // for(auto sibling : tree[parent]){ //the issue, since in wc har node ke n siblings, thus n*n jayega tc
        //     if(sibling!=root && sibling!=grandParent){
        //         temp+=(in[sibling]+2LL*subTreeSize[sibling]); //isko bhi parent ke out me hi dalde toh?
        //         //hojayega, par phir temp mese curr node ka minus krna padega
        //     }
        // }
        temp+=(siblingStore[parent]);
        temp-=(in[root]+2LL*(subTreeSize[root]));
    }
    out[root]+=temp;
    ans[root]+=(out[root]+in[root]);
    for(auto child : tree[root]){
        if(child!=parent){
            fillAnsAndOut(parent,child,root,tree,in,out,ans,subTreeSize,n,siblingStore);
        }
    }
}


void solve(){
    umll in;
    umll out;
    umll ans;
    umll subTreeSize;
    umll siblingStore;
    ll n;
    cin>>n;
    um<ll,vecll> tree;
    forn(0,n-1){
        ll u,v;
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    fillSubTreeSizeAndIn(1,-1,tree,in,subTreeSize,siblingStore);
    fillAnsAndOut(-1,1,-1,tree,in,out,ans,subTreeSize,n,siblingStore);
    forn(1,n+1){
        cout<<ans[i]<<" ";
    }
}
//start at - 9:47

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}