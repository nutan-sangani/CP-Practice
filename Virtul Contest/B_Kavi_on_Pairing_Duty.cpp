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

vecll divisorCnt;

void addDivisors(ll n){
    divisorCnt.resize(n+1,1);
    int i=2;
    while(i<=n){
        ll val=i;
        while(val<=n){
            divisorCnt[val]+=1;
            divisorCnt[val]%=mod;
            val+=i;
        }
        i++;
    }
}

ll memoize(vecll& dp,int n){
    if(n==1) return 1;
    else if(n<1) return 0;
    else if(dp[n]!=-1) return dp[n];
    ll singleDistance = divisorCnt[n];
    ll total = singleDistance;
    total%=mod;
    ll gap=1;
    while(gap<=(n-1)){
        total+=memoize(dp,gap);
        total%=mod;
        gap+=1;
    } //with this the time complexity is n^2, isko tabulate kiya toh prefix
    //ka sum store krke time complexity ko n krsakte
    return dp[n]=total;
}

void solve(){
    ll n;
    cin>>n;
    vecll dp(n+1,0);
    addDivisors(n);
    // cout<<memoize(dp,n); n^2 me chalega
    ll sum=0;
    for(int gap=1;gap<n;gap++){
        ll val = divisorCnt[gap]+sum; //s=1,v=1 -> v=2,s=3
        val%=mod;
        sum+=val;
        sum%=mod;
    }
    sum+=divisorCnt[n];
    sum%=mod;
    cout<<sum<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}