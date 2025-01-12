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

ll findOptimalScore(vector<vecll>& dp,int i,int j,int n,vecll& val,int turn){
    //if odd numbers are removed, then 2nd player ke bari, else first ki
    //first player will choose max of 2 options, else min of 2 options
    //2nd apna max nikal rha is same as wo 1st ka min nikal rha
    if(i>j) return 0;
    else if(i==j){
        return turn==1 ? val[i] : 0;
    }
    else if(dp[i][j]!=-1) return dp[i][j];
    ll nextTurn = turn==1 ? 2 : 1;
    ll option1 = findOptimalScore(dp,i+1,j,n,val,nextTurn);
    ll option2 = findOptimalScore(dp,i,j-1,n,val,nextTurn);
    if(turn==1){
        option1+=val[i];
        option2+=val[j];
    }
    return turn==1 ? max<ll>(option1,option2) : min<ll>(option1,option2);
}
//this works, but TLE, so sidha Tabula. pe hi move on kr rha me.
//but memo. me tle aana toh nhi chahiye, after this lets check ki iska koi better memo h kya.

void solve(){
    ll n;
    cin>>n;
    vecll val(n,0);
    forn(0,n) cin>>val[i];
    vector<vecll> dp(n+1,vecll(n+1,0)); //this contains optimal answer with that value.
    // cout<<findOptimalScore(dp,0,n-1,n,val,1)<<endl;

    //dp[i][j] = max/min (dp[i+1][j],dp[i][j-1]) (+val[i/j] based on turn)
    //so for an row(i), we see the dependence on prev col, as well as next row
    //thus isme normal tabulation nhi chalega, kuch krna padega
    //so isme cross/diagonal filing krte hum, since dp[i+1][j] and dp[i][j-1] are diagonal vals
    //or gap method. ie we fill based on gap between i and j.

    forn(0,n){
        dp[i][i] = (n-1)%2==0 ? val[i] : 0; //so 0 gap wala fill krdiya mene
    }
    for(int gap=1;gap<n;gap++){
        for(int i=0;(i+gap)<n;i++){
            int j = i+gap;
            ll remaining = j-i+1;
            ll removed = n - remaining;
            ll turn = removed%2==0 ? 1 : 2;
            ll option1 = dp[i+1][j];
            ll option2 = dp[i][j-1];
            if(turn==1){
                option1+=val[i];
                option2+=val[j];
                dp[i][j] = max<ll>(option1,option2);
                continue;
            }
            dp[i][j]=min<ll>(option1,option2);
        }
    }
    cout<<dp[0][n-1]<<endl;

    //to save space, we can use sparse matrix here, but i dont want to make it so complicated.
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}