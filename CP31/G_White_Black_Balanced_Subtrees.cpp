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

int gcount=0;

pll findCountOfWhiteAndBlack(int root,int parent,um<ll,vecll>& tree,vector<char>& color){
    ll countWhite = 0;
    ll countBlack = 0;
    for(int node : tree[root]){
        if(node!=parent){
            pll c = findCountOfWhiteAndBlack(node,root,tree,color);
            countWhite+=c.first;
            countBlack+=c.second;
        }
    }
    if(color[root]=='W') countWhite+=1;
    else countBlack+=1;
    if(countWhite==countBlack) gcount+=1;
    return pair(countWhite,countBlack);
}

void solve(){
    ll n;
    cin>>n;
    um<ll,vecll> tree;
    vector<char> color(n+1,'.');
    forn(2,n+1){
        ll p;
        cin>>p;
        tree[i].pb(p);
        tree[p].pb(i);
    }
    string c;
    cin>>c;
    forn(1,n+1){
        color[i]=c[i-1];
    }
    findCountOfWhiteAndBlack(1,-1,tree,color);
    cout<<gcount<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        gcount=0;
    }
    return 0;
}