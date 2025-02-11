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

void takeInput(vecll& a,int n,umll& mapOfA){
    forn(0,n){
        cin>>a[i];
        mapOfA[a[i]]=i;
    }
}

ll doDFS(vecll& a,vecll& b,vecll& c,vecll& visited,int n,int index,bool indexOfA,umll& mapOfA,umll& mapOfB){
    if(visited[index]==1) return 0;
    if(visited[index]==0)
        visited[index]=1;
    ll nextVal,nextIndex;
    if(indexOfA){
        nextVal = b[index];
        nextIndex = mapOfA[nextVal];
    }
    else{
        nextVal = a[index];
        nextIndex = mapOfB[nextVal];
    }
    ll val = doDFS(a,b,c,visited,n,nextIndex,indexOfA,mapOfA,mapOfB);
    if(visited[index]==2) return -1;
    if(val==-1) return -1;
    return val+1;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n),b(n),c(n),visited(n,0);
    umll mapOfA,mapOfB;
    takeInput(a,n,mapOfA);
    takeInput(b,n,mapOfB);
    forn(0,n){
        cin>>c[i];
        if(c[i]!=0) visited[i]=2;
    }
    ll cost = 1;
    forn(0,n){
        if(visited[i]==0){
            if(a[i]==b[i]){
                visited[i]=1;
                continue;
            }
            ll val = doDFS(a,b,c,visited,n,i,true,mapOfA,mapOfB);
            if(val!=-1){
                cost*=2;
                cost%=mod;
            }
        }
    }
    cout<<cost<<endl;
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