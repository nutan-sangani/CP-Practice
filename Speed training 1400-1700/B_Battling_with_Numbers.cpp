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

ll binaryExponentiation(ll base,ll power,ll modi){
    ll ans=1LL;
    while(power){
        if(power & 1LL){
            ans*=base;
            ans%=modi;
        }
        base*=base;
        base%=modi;
        power=power/2LL;
    }
    return ans%modi;
}

bool hasMinFactor(umll& x,umll& y){
    for(auto it : x){
        if(it.second>y[it.first]) return false;
    }
    return true;
}

void solve(){
    ll n;
    set<ll> factors;
    umll x,y;
    cin>>n;
    vecll a(n,0);
    forn(0,n){
        ll factor;
        cin>>factor;
        factors.insert(factor);
        a[i]=factor;
    }
    forn(0,n){
        ll power;
        cin>>power;
        x[a[i]]=power;
    }
    ll m;
    cin>>m;
    a.clear();
    a.resize(m);
    forn(0,m){
        ll factor;
        cin>>factor;
        factors.insert(factor);
        a[i]=factor;
    }
    forn(0,m){
        ll power;
        cin>>power;
        y[a[i]]=power;
    }
    ll anyMin = hasMinFactor(y,x);
    if(!anyMin){
        cout<<0<<endl;
        return;
    }
    ll count=0;
    for(auto it : factors){
        if(x[it]!=y[it]){
            count+=1;
        }
    }
    count = binaryExponentiation(2,count,mod);
    cout<<count<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}