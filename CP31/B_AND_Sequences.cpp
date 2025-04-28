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

vecll fact;

ll sumOfnNaturalNumbers(ll n){
    if(n%2==0){
        return (n/2LL)*(n+1);
    }
    return ((n+1LL)/2LL)*n;
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n);
    forn(0,n) cin>>a[i];
    umll bitSetCount;
    forn(0,n){
        for(int j=0;j<=32;j++){
            if(1LL<<j & a[i]){
                bitSetCount[j]++;
            }
        }
    }
    vecll incompleteBits;
    forn(0,33){
        if(bitSetCount[i]<n && bitSetCount[i]>0){
            incompleteBits.pb(i);
        }
    }
    //find all numbers with all incomplete bits unset
    int count=0;
    fact.resize(n+1,1);
    ll prod = 1;
    forn(0,n){
        prod*=(i+1);
        prod%=mod;
        fact[i+1]=prod;
        bool qualified = true;
        for(auto bit : incompleteBits){
            if(1LL<<bit & a[i]){
                qualified = false;
                break;
            }
        }
        if(qualified) count+=1;
    }
    ll ans = 0;
    if(incompleteBits.size()==0){
        ans = fact[n];
    }
    else if(count>=2){
        ans = fact[n-2];
        ll combinations = sumOfnNaturalNumbers(count-1);
        combinations*=2;
        combinations%=mod;
        ans*=combinations;
        ans%=mod;
    }
    cout<<ans<<endl;
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