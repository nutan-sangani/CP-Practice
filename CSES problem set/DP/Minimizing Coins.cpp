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

// ll findMinCoinsNeededToMake(ll value,vecll& denominations,vecll& dp){
//     if(value==0) return 0;
//     else if(value<0) return -1;
//     else if(dp[value]!=-2) return dp[value];
//     ll minCoinsNeeded = LLONG_MAX;
//     for(ll denomination : denominations){
//         ll temp = findMinCoinsNeededToMake(value-denomination,denominations,dp);
//         if(temp!=-1) minCoinsNeeded = min<ll>(minCoinsNeeded,temp+1);
//     }
//     if(minCoinsNeeded==LLONG_MAX){
//         minCoinsNeeded=-1;
//     }
//     return dp[value]=minCoinsNeeded;
// }

void solve(){
    ll n,x;
    cin>>n>>x;
    vecll denominations(n,0);
    forn(0,n){
        cin>>denominations[i];
    }
    vecll dp(x+1,-1);
    // cout<<findMinCoinsNeededToMake(x,denominations,dp);
    //lets tabularize
    dp[0]=0;
    forn(1,x+1){
        ll minCost=LLONG_MAX;
        for(auto denomination : denominations){
            ll rem = i - denomination;
            if(rem>=0){
                ll cost = dp[i-denomination];
                if(cost!=-1){
                    minCost=min<ll>(cost+1,minCost);
                }
            }
            else continue;
        }
        if(minCost!=LLONG_MAX) dp[i]=minCost;
    }
    cout<<dp[x];
    //see, memo and tabu me bahot kam diff h (atleast for this pattern).
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}