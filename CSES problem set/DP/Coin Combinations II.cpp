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

// ll findWays(ll target,vecll& a,vector<vecll>& dp,ll index,ll n){
//     if(target==0) return 1;
//     else if(target<0) return 0;
//     else if(index>=n) return 0;
//     else if(dp[target][index]!=-1) return dp[target][index];
//     ll ways=0;

//     // forn(index,n){
//     //     ways+=findWays(target-a[i],a,dp,i,n);
//     //     ways%=mod;
//     // }
//     //this is not the decision that we need to make, we need to choose between 2 decisions
//     //1. whether isko le
//     //2. ya nhi
//     //wese toh dono hi chalega, but niche wala would be faster and will consume less space 
//     //due to making less fn calls.

//     ways+=findWays(target-a[index],a,dp,index,n);
//     ways%=mod;
//     ways+=findWays(target,a,dp,index+1,n);
//     ways%=mod;
//     return dp[target][index]=ways;
// }
//lets do tabular way, since runtime err aa rha h, maybe due to 10^6 recursion calls
//but dusre questions me ye problem toh nhi hui thi.

ll findWay(ll target,queue<ll>& a,vector<ll>& dp){
    if(target==0) return 1;
    if(a.empty()) return 0;
    else if(target<0) return 0;
    else if(dp[target]!=-1) return dp[target];
    ll multiple = target/a.front();
    ll first=a.front();
    a.pop();
    ll ways=0;
    forn(1,multiple+1){
        ll val = first*(i+0LL);
        ways+=findWay(target-val,a,dp);
    }
    return dp[target]=ways;

}

void solve(){
    ll n,target;
    cin>>n>>target;
    // vecll a(n,0);
    queue<ll> q;
    vector<ll> dp(target+1,-1);
    forn(0,n){
        ll z;
        cin>>z;
        q.push(z);
        // dp[0][i]=1;
    }
    cout<<findWay(target,q,dp);
    // dp[0][n]=1;
    // ll ways = (findWays(target,a,dp,0,n)%mod);
    // forn(1,target+1){
    //     for(ll val=0;val<n;val++){
    //         // ll rem = i-a[val];
    //         // ll ways=0;
    //         // if(rem>=0){
    //         //     ways+=max<ll>(0,dp[rem][val]);
    //         // }
    //         // ways%=mod;
    //         // if(val>0)
    //         //     ways+=max<ll>(0,dp[i][val-1]);
    //         // ways%=mod;
    //         // dp[i][val]=ways;
    //     }
    // }
    // ll ways=dp[target][n-1];
    // ll ways=0;
    // cout<<ways<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}