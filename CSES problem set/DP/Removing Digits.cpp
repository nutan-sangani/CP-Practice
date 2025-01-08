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
#define debug(x) cout<<"#x : "<<x<<endl;

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

vecll getAllDigitsFrom(ll n){
    vecll ans;
    while(n){
        ans.pb(n%10);
        n/=10;
    }
    return ans;
}

// ll getMinMoves(vecll& dp,ll n){
//     if(n<0) return LLONG_MAX-1;
//     else if(n==0) return 0;
//     // else if(n<=9 && n>0) return 1;
//     else if(dp[n]!=-1) return dp[n];
//     vecll digits = getAllDigitsFrom(n);
//     ll minMoves = LLONG_MAX;
//     for(ll digit : digits){
//         if(digit==0) continue;
//         ll temp = getMinMoves(dp,n-digit);
//         minMoves = min<ll>(temp+1,minMoves);
//     }
//     return dp[n]=minMoves;
// }
//lets memoize it.

void solve(){
    ll n;
    cin>>n;
    vecll dp(n+1,LLONG_MAX);
    dp[0]=0;
    forn(1,min<ll>(9,n+1)){
        dp[i]=1;
    }
    forn(1,n+1){
        vecll digits = getAllDigitsFrom(i);
        ll minMoves=LLONG_MAX;
        for(auto digit : digits){
            if(i-digit>=0){
                ll temp = dp[i-digit];
                if(temp!=LLONG_MAX)
                    minMoves=min<ll>(minMoves,temp+1);        
            }
        }
        dp[i]=minMoves;
    }
    cout<<dp[n]<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}