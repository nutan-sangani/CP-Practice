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

ll recurse(vector<vecll>& dp,ll index,ll numberWanted,ll n,vecll& a){
    if(numberWanted==4) return 1;
    else if(index>=n) return 0;
    else if(dp[index][numberWanted]!=-1) return dp[index][numberWanted];
    ll count=0;
    if(a[index]==numberWanted){
        if(numberWanted==2){
            count=recurse(dp,index+1,numberWanted,n,a);
            count%=mod;
            count+=recurse(dp,index+1,numberWanted+1,n,a);
            count%=mod;
        }
        else{
            count=recurse(dp,index+1,numberWanted+1,n,a);
            count%=mod;
        }
    }
    count += recurse(dp,index+1,numberWanted,n,a);
    count%=mod;
    return dp[index][numberWanted]=count;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n,0);
    forn(0,n) cin>>a[i];
    vector<vecll> dp(n,vecll (4,-1));
    cout<<recurse(dp,0,1,n,a)<<endl;

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