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

ll binaryExponent(ll a,int b,ll m){
    ll ans = 1;
    ll base = a;
    while(b>0){
        if(b & 1){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        b/=2;
    }
    return ans%mod;
}

ll modularMultiplicativeInverse(ll val,ll modi){
    return binaryExponent(val,modi-2,modi)%modi;
}

ll findWays(vector<vecll>& dp,vecll& a,ll index,ll rem,ll n){
    if(rem==0){
        return 1;
    }
    else if(rem<0) return 0; //since there are no -ve vals
    else if(index>=n) return 0;
    else if(dp[rem][index]!=-1) return dp[rem][index];
    ll ways = 0;
    ways += findWays(dp,a,index+1,rem,n); //ignoring curr val
    ways%=mod;
    ways += findWays(dp,a,index+1,rem-a[index],n);
    ways%=mod;
    return dp[rem][index]=ways;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n,0);
    ll sum=0;
    forn(0,n){
        a[i]=i+1;
        sum+=a[i];
    }
    ll target = sum/2;
    if(sum%2!=0){
        cout<<0<<endl;
        return;
    }
    vector<vecll> dp(sum+1,vecll(n+1,0));
    //divide by 2 isiliye, since no of divisions of number into 2 sets find krne h with sum=target
    //not no of seq's with sum=target. since set1 and set2 me no.s ko interchange krne se
    //divisions/partitions same hi rehte h.

    // cout<<findWays(dp,a,0,target,n)/2; isko direct 2 se divide nhi krsakte
    //since %mod kiya h, isiliye mmi use krna padega

    // ll ways = findWays(dp,a,0,target,n);
    // ll mmi = modularMultiplicativeInverse(2,mod);
    // ways*=mmi;
    // ways%=mod;
    // cout<<ways<<endl;
    //this is correct, lets do tabulation

    forn(0,n+1) dp[0][i]=1;
    forn(1,target+1){
        for(int j=1;j<=n;j++){ //shift right kiya h since j-1 pe dependency h and j can be zero
            ll ways=0;
            ways+=dp[i][j-1];
            ways%=mod;
            if(i>=a[j-1])
                ways+=dp[i-a[j-1]][j-1];
            ways%=mod;
            dp[i][j]=ways;
        }
    }
    sum=dp[target][n];
    // forn(0,n+){
    //     sum+=dp[target][i];
    //     sum%=mod;
    // } ye nhi krna padega, since dp also considers ki ith ko nhi liya h
    //means it also considers ki kisi ko bhi nhi liya toh kya hoga.
    //thus nth index is the answer.
    ll mmi = modularMultiplicativeInverse(2,mod);
    sum*=mmi;
    sum%=mod;
    cout<<sum<<endl;

    //lets try to row optimize it, since sum has dependency larger than constant rows,
    //2nd dimension ie index ko reduce kr, since it only uses curr and prev rows.
    //nhi isko 2 rows me, ie using 2 i ki val nhi krsakte, since we need the count
    //ki i jitna sum j se index tak kitne baar banta h, since we can't take 1 no multiple times
    //agr ek ko multiple times le sakte toh += krte jaa sakte inn numbers ko

}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}