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

vecll fact(200001,1);

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

ll nCr(ll n,ll r){ //3C1
    if(n<=r || r==0) return 1;
    ll numerator = fact[n]; //6
    numerator%=mod;
    ll denominator = fact[n-r]*fact[r]; //2
    denominator%=mod;
    ll inverse = binaryExponent(denominator,mod-2,mod);
    return (numerator*inverse*1LL)%mod;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n,0);
    map<ll,ll> freq;
    forn(0,n){
        cin>>a[i];
        freq[a[i]]++;
    }
    forn(1,n+1){
        fact[i] = (((i+0LL)*fact[i-1])%mod);
    }
    auto largest = --freq.end();
    ll largestCount = (*largest).second;
    ll largestNo = (*largest).first;
    if(freq.size()==1){
        cout<<fact[n]<<endl;
        return;
    }
    ll secondLargestNo = largestNo-1;
    ll secondLargestCount = freq[secondLargestNo];
    // cout<<freq.size();
    if(secondLargestCount==0){
        cout<<0<<endl;
        return;
    }
    if(largestCount>1){
        cout<<fact[n]<<endl;
        return;
    }
    ll count=0;
    forn(0,n){
        ll before = i;
        ll after = n - i - 1;
        ll rem = n - largestCount - secondLargestCount;
        if(before>=secondLargestCount){
            ll multiple = nCr(rem,rem-after);
            ll beforePerm = fact[before];
            ll afterPerm = fact[after];
            ll temp = multiple*beforePerm;
            temp%=mod;
            temp*=afterPerm;
            temp%=mod;
            count+=temp;
            count%=mod;
        }
    }
    ll total = fact[n];
    // if(count==total){
    //     cout<<"same h bhai";
    // }
    total+=mod;
    total-=count;
    total%=mod;
    cout<<total<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}