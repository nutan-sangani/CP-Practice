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

ll options[3]={-1,0,1};

ll findWays(vecll& a,ll index,ll noAtPrevIndex,ll n,vector<vecll>& dp,ll m){
    if(index==(n)) return 1;
    else if(dp[noAtPrevIndex][index]!=-1) return dp[noAtPrevIndex][index];
    ll ways=0;
    if(a[index]!=0){
        if(noAtPrevIndex!=0 && abs(noAtPrevIndex-a[index])>1) return 0; //dono adj. side validation krna padega
        return dp[noAtPrevIndex][index]=findWays(a,index+1,a[index],n,dp,m);
    }
    if(noAtPrevIndex==0){
        forn(1,m+1){
            ways+=findWays(a,index+1,i,n,dp,m);
            ways%=mod;
        }
    }
    else{
        forn(0,3){
            ll currVal = noAtPrevIndex+options[i];
            if(currVal<1 || currVal>m) continue;
            ways+=findWays(a,index+1,currVal,n,dp,m);
            ways%=mod;
        }
    }
    return dp[noAtPrevIndex][index]=ways;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vecll a(n,0);
    forn(0,n) cin>>a[i];
    vector<vecll> dp(m+1,vecll (n+1,0));
    forn(0,m+1){
        dp[i][n]=1;
    }
    // cout<<findWays(a,0,0,n,dp,m);
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=m;j++){
            //where i is index and j is the prev val;
            if(a[i]!=0){
                if(i==0 || (abs(j-a[i])<=1)){
                    dp[j][i]+=dp[a[i]][i+1];
                    dp[j][i]%=mod;
                }
                else dp[j][i]=0;
            }
            else if(a[i]==0 && i==0){
                dp[0][0]+=dp[j][1];
            }
            else{
                for(int k=0;k<3;k++){
                    ll currVal = j + options[k];
                    if(currVal<1 || currVal>m) continue;
                    dp[j][i]+=dp[currVal][i+1];
                    dp[j][i]%=mod;
                }
            }
        }
    }
    cout<<dp[a[0]][0]<<endl;
    return;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}