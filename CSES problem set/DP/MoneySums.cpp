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

vecll ans;

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

void findPossibleSums(vector<vecll>& dp,ll index,ll currSum,vecll& denominations,ll n){
    if(index>n) return;
    else if(dp[currSum][index]!=-1) return;
    else if(index==n){
        dp[currSum][n]=1;
        ans.pb(currSum);
        return;
    }
    //yaha 2 options, ya toh index le, ya mat le
    findPossibleSums(dp,index+1,currSum,denominations,n);
    findPossibleSums(dp,index+1,currSum+denominations[index],denominations,n);
}

void solve(){
    ll n;
    cin>>n;
    vecll denominations(n,0);
    forn(0,n) cin>>denominations[i];

    // vector<vecll> dp(100001,vecll(n+1,-1));
    // dp[0][n]=1;
    // findPossibleSums(dp,0,0,denominations,n);
    // cout<<ans.size()<<endl;
    // sort(itr(ans));
    // forn(0,ans.size()){
    //     cout<<ans[i]<<" ";
    // }
    //correct but giving TLE on most large edge cases
    //lets try to tabulate, since anyways wo krna hi h, if tabhi bhi TLE then kuch aur sochte

    //we know for sure ki 1e5 is the max no that can be formed, thus atmost 1e5 numbers banenge
    //in memoization, we only need to remove extra calls, tabulation me wo nhi krna padega.

    sort(itr(denominations));
    vector<vecll> dp(100002,vecll (n+1,0));
    dp[0][0]=1;
    forn(1,n+1){
        dp[0][i]=1;
        // dp[denominations[i-1]][0]=1;
    }
    ll uniqueNoCount=0;
    forn(1,100001){
        for(int j=1;j<=n;j++){
            dp[i][j] = max<ll>(dp[i][j-1]==1 ? 1 : 0,dp[i][j]);
            if(i-denominations[j-1]>=0)
                dp[i][j] = max<ll>(dp[i][j],dp[i-denominations[j-1]][j-1]==1 ? 1 : 0);
        }
    }
    forn(1,100001){
        if(dp[i][n]==1){
            ++uniqueNoCount;
        }
    }
    cout<<uniqueNoCount<<endl;
    forn(1,100001){
        if(dp[i][n]==1) cout<<i<<" ";
    }
    //isko further space optimize krsakte using only 2 rows
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}