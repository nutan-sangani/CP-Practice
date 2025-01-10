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

ll memoize(vector<vecll>& dp,ll n,ll m){
    if(n==m) return 0;
    else if(n==1) return m-1;
    else if(m==1) return n-1;
    else if(dp[n][m]!=-1) return dp[n][m];
    ll minCuts = LLONG_MAX;
    forn(1,n){
        minCuts = min<ll>(minCuts,memoize(dp,n-i,m)+memoize(dp,i,m)+1);
    }
    forn(1,m){
        minCuts = min<ll>(minCuts,memoize(dp,n,m-i)+memoize(dp,n,i)+1);
    }
    return dp[n][m]=minCuts;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vecll> dp(n+1,vecll(m+1,m*n));
    //where m*n is the max cost
    // cout<<memoize(dp,n,m)<<endl;
    //lets tabulate
    forn(1,n+1){
        dp[i][1]=i-1;
    }
    forn(1,m+1){
        dp[1][i]=i-1;
    }
    forn(0,m+1){
        for(int j=0;j<=n;j++){
            if(i==j){
                dp[j][i]=0;
            }
        }
    }
    forn(1,m+1){
        for(int j=1;j<=n;j++){
            ll minCuts=m*n;
            for(int k=1;k<j;k++){
                minCuts = min<ll>(minCuts,dp[j-k][i]+dp[k][i]+1);
            }
            for(int k=1;k<i;k++){
                minCuts = min<ll>(minCuts,dp[j][i-k]+dp[j][k]+1);
            }
            dp[j][i]=min<ll>(minCuts,dp[j][i]);
        }
    }
    cout<<dp[n][m]<<endl;
    //isko aur space optimize nhi krsakte, since i-k me k can be i-1 also, so uss case 
    //me 1st row access krni padegi, thus uske liye pura store krna hi padega
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}