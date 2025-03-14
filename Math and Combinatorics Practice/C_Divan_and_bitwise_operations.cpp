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
#define forn(begin,end) for(ll i=begin;i<end;++i)
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

vecll powerOf2(200002,1);
vecll fact(200002,1);

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
    if(n<=r) return 1;
    ll numerator = fact[n]; //6
    numerator%=mod;
    ll denominator = fact[n-r]*fact[r]; //2
    denominator%=mod;
    ll inverse = binaryExponent(denominator,mod-2,mod);
    return (numerator*inverse*1LL)%mod;
}

class MyComp{
    public:
    bool operator()(const pair<ll,pll>& a,const pair<ll,pll>& b){ //for max heap and ascending sort in vector
        if(a.first!=b.first)
            return a.first<b.first;
        else return a.second.second<b.second.second;
    }
};

class MyComp2{
    public:
    bool operator()(const pll& a,const pll& b){ //for max heap and ascending sort in vector
        if(a.first!=b.first)
            return a.first>b.first;
        else return a.second>b.second;
    }
};

void solve(){
    ll n,m;
    cin>>n>>m;
    set<pll> uniqueRanges;
    vecll val(n,0);
    vector<pair<ll,pll>> ranges;
    forn(0,m){
        ll l,r,w;
        cin>>l>>r>>w;
        if(uniqueRanges.find(mp(l,r))==uniqueRanges.end()){
            ranges.pb(mp(l,mp(r,w)));
            uniqueRanges.insert(mp(l,r));
        }
    }
    m = uniqueRanges.size();
    sort(itr(ranges),MyComp());
    int rangeIndex=0;
    priority_queue<pll,vector<pll>,MyComp2> pq;
    forn(1,n+1){
        ll index = i-1;
        while(rangeIndex<m  && ranges[rangeIndex].first==i){
            pq.push(mp(ranges[rangeIndex].second.second,ranges[rangeIndex].second.first));
            ++rangeIndex;
        }
        while(!pq.empty() && pq.top().second<i) pq.pop();
        ll top = pq.top().first;
        val[index]=top;
    }
    ll count=0;
    //count c r * 2^(n-r)

    forn(0,32){ //32nd bit tak check kr
        ll bitSetCount = 0;
        for(auto num : val){
            bool isBitSet = (num & 1LL<<i);
            if(isBitSet) ++bitSetCount;
        }
        int k = 1;
        while(k<=bitSetCount){
            ll newN = n - bitSetCount;
            ll combinations = nCr(bitSetCount,k);
            ll power = powerOf2[newN];
            ll multiple = power*combinations;
            multiple%=mod;
            ll number = powerOf2[i];
            number*=multiple;
            number%=mod;
            count+=number;
            count%=mod;
            k+=2;
        }
    }
    cout<<count<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    forn(1,200001+1){
        powerOf2[i]=((powerOf2[i-1]*2LL)%mod);
        fact[i]=((i*fact[i-1])%mod);
    }
    while(t--)
    {
        solve();
    }
    return 0;
}