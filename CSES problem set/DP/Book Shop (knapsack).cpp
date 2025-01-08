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

// ll findMaxPagesForCostAndIndex(ll rem,ll index,vector<vecll>& dp,vecll& pages,vecll& prices,int n){
//     if(rem==0) return 0;
//     if(index>=n) return 0;
//     //maintain the case of rem being -ve, it should be possible
//     else if(dp[rem][index]!=-1) return dp[rem][index];
//     ll maxPages=LLONG_MIN;
//     maxPages = findMaxPagesForCostAndIndex(rem,index+1,dp,pages,prices,n);
//     if(rem-prices[index]>=0)
//         maxPages = max<ll>(
//             maxPages,
//             findMaxPagesForCostAndIndex(rem-prices[index],index+1,dp,pages,prices,n)+pages[index]
//         );
//     return dp[rem][index]=maxPages;
// }
//lets do more optimization biro

void solve(){
    ll n,x;
    cin>>n>>x;
    vecll prices(n,0);
    vecll pages(n,0);
    forn(0,n) cin>>prices[i];
    forn(0,n) cin>>pages[i];

    // vector<vecll> dp(x+1,vecll (n,-1));
    // cout<<findMaxPagesForCostAndIndex(x,0,dp,pages,prices,n);
    //we can do only using 2 rows, so can remove the others
    //also the only operations on those 2 is addition from piche ki vals, thus can also do in 1 row
    //nope,ig since we are using rem-currPrice of prev, 2 rows toh use krne hi padenge
    ll prev[x+1];
    ll curr[x+1];
    forn(0,x+1){
        prev[i]=curr[i]=0;
    }
    // forn(0,n){
    //     for(int j=1;j<=x;j++){
    //         ll rem = j-prices[i];
    //         curr[j] = prev[j];
    //         if(rem>=0)
    //             curr[j] = max<ll>(curr[j],prev[rem]+pages[i]);
    //     }
    //     for(int j=0;j<=x;j++){
    //         prev[j]=curr[j];
    //         curr[j]=0;
    //     }
    // }
    //can further reduce it to use only 1 row. The reason we couldnt do so before was
    //ki dp[i][j] depends on dp[i-1][j-k], so if going from 1 to x, j-x is lower than j
    //thus hum usko pehle hi traverse kr chuke h ie change kr chuke h,so cant get the prev val
    //par x to 1 traverse kiya, then j-k is lesser but wo badme change hoga. Thus uski prev val
    //milegi apne ko. (btw idk ki prev ko change kiya toh signi eff hoga ki nhi answer. Hoga!!);

    forn(0,n){
        for(int j=x;j>=0;j--){
            ll rem = j-prices[i];
            // curr[j] = prev[j];
            if(rem>=0)
                curr[j] = max<ll>(curr[j],curr[rem]+pages[i]);
        }
    }
    cout<<curr[x]<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}