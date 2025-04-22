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

void solve(){
    
}

um<ll,vecll> divisors;
vector<vecll> dp(2001,vecll (2001,-1));

void findAllDivisors(ll n){
    int i=1;
    while(i<=n){
        ll val=i;
        while(val<=n){
            divisors[val].pb(i);
            val+=i;
        }
        i++;
    }
}

ll memoize(ll prevNumber,ll k){
    if(k==0) return 1;
    else if(prevNumber==1) return 1;
    else if(dp[prevNumber][k]!=-1) return dp[prevNumber][k];
    ll ways=0;
    for(ll divisor : divisors[prevNumber]){
        ways+=memoize(divisor,k-1);
        ways%=mod;
    }
    return dp[prevNumber][k]=ways;
}

int main()
{
    FASTIO
    {
        ll n,k;
        cin>>n>>k;
        findAllDivisors(n);
        ll sum=0;
        forn(1,n+1){
            sum+=memoize(i,k-1);
            sum%=mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}