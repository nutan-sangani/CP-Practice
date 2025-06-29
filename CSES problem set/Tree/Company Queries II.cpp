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

void debug(){
    cout<<endl;
}

template<typename T,typename... Args>
void debug(T firstArg,Args... args){
    cout<<firstArg<<" ";
    debug(args...);
}

template<typename T>
void printArray(vector<T>& a){
    int n = a.size();
    forn(0,n) cout<<a[i]<<" ";
    cout<<endl;
}

template<typename T>
void printMatrix(vector<vector<T>>& a){
    int rows = a.size();
    forn(0,rows){
        printArray(a[i]);
    }
}

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

void binaryLiftingPreprocess(vector<vector<int>>& jthAncestorOfNodeI,vector<int>& depth,int root,int parent,um<ll,vecll>& tree){
    jthAncestorOfNodeI[root][0]=parent;
    int temp = parent;
    int i=1;
    while(temp!=-1){
        jthAncestorOfNodeI[root][i] = jthAncestorOfNodeI[temp][i-1];
        temp = jthAncestorOfNodeI[temp][i-1];
        i++;
    }
    if(parent!=-1)
        depth[root] = depth[parent] + 1;
    for(auto child : tree[root]){
        binaryLiftingPreprocess(jthAncestorOfNodeI,depth,child,root,tree);
    }
}

void printLCA(int u,int v,vector<int>& depth,vector<vector<int>>& jthAncestorOfNodeI){
    if(depth[u]<depth[v]) swap(u,v);
    ll diff = depth[u] - depth[v];
    int i=0;
    while(i<=32){
        if(diff & 1LL<<i){
            u = jthAncestorOfNodeI[u][i];
        }
        i++;
    }
    if(u==v){
        cout<<u<<endl;
        return;
    }
    for(int j=32;j>=0;j--){
        if(jthAncestorOfNodeI[u][j]!=jthAncestorOfNodeI[v][j]){
            u = jthAncestorOfNodeI[u][j];
            v = jthAncestorOfNodeI[v][j];
        }
    }
    cout<<jthAncestorOfNodeI[u][0]<<endl;
}

void solve(){
    int n,q;
    cin>>n>>q;
    um<ll,vecll> tree;
    forn(1,n){
        ll parent;
        cin>>parent;
        tree[parent].pb(i+1);
    }
    vector<vector<int>> jthAncestorOfNodeI(n+1,vector<int> (35,-1));
    vector<int> depth(n+5,0);
    binaryLiftingPreprocess(jthAncestorOfNodeI,depth,1,-1,tree);
    while(q--){
        ll u,v;
        cin>>u>>v;
        printLCA(u,v,depth,jthAncestorOfNodeI);
    }
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}