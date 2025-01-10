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

void solve(){
    string a,b;
    cin>>a>>b;
    ll n = a.size();
    ll m = b.size();
    // vector<vecll> dp(m+1,vecll(n+1,0));
    // forn(0,m+1){
    //     dp[i][0]=i;
    // }
    // forn(0,n+1){
    //     dp[0][i]=i;
    // }
    // forn(1,m+1){
    //     for(int j=1;j<=n;j++){
    //         ll temp=LLONG_MAX;
    //         if(a[j-1]==b[i-1])
    //             temp=dp[i-1][j-1];
    //         temp = min<ll>(dp[i-1][j]+1,min<ll>(dp[i-1][j-1]+1,min<ll>(temp,dp[i][j-1]+1)));
    //         dp[i][j]=temp;
    //     }
    // }
    // cout<<dp[m][n]<<endl;
    //working towards better space complexity
    vector<ll> prev(n+1,0),curr(n+1,0);
    forn(0,n+1){
        prev[i]=i;
    }
    curr[0]=1;
    forn(1,m+1){
        for(int j=1;j<=n;j++){
            ll temp = LLONG_MAX;
            if(a[j-1]==b[i-1]){
                temp = prev[j-1]; //prev is i-1 and curr is i
            }
            temp = min<ll>(temp,min<ll>(prev[j-1]+1,min<ll>(curr[j-1]+1,prev[j]+1)));
            curr[j]=temp;
        }
        for(int j=0;j<n+1;j++){
            prev[j]=curr[j];
            curr[j]=0;
        }
        curr[0]=i+1;
    }
    cout<<prev[n]<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}