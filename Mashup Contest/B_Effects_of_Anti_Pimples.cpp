#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007
#define mod2 998244353LL

using namespace std;

umll dp;

ll binaryExponent(ll a,ll b,ll m){ //(a^b)%m
    // if(b==0) return 1;
    if(dp[b]!=0) return dp[b];
    ll copy = b;
    ll ans = 1;
    ll base = a;
    while(b>0){
        if(b & 1LL){
            ans*=base;
            ans%=m;
        }
        base*=base;
        base%=m;
        b/=2;
    }
    return dp[copy]=ans%m;
}

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b){ //for max heap and ascending sort in vector
        if(a.first!=b.first)
            return a.first>b.first;
        else return a.second<b.second;
    }
};

void solve(){
    um<ll,set<ll>> divisorsOf; // n : set of divisors
    ll n;
    cin>>n;
    vector<pll> a;
    forn(0,n){
        ll b;
        cin>>b;
        a.pb(mp(b,i+1));
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            divisorsOf[j].insert(i); //this is set for an index, so sorted no.s ka index bhi chahiye muje
        }
    }
    sort(itr(a),MyComp());
    ll ans=0;
    set<ll> excludedNumbers;
    forn(0,n){
        pll pair = a[i];
        ll val = pair.first;
        ll index = pair.second;
        if(excludedNumbers.count(index)>=1){
            continue;
        }
        excludedNumbers.insert(index);
        ll power = n - excludedNumbers.size(); //ie current number ko bhi exclude krna h and rem se choose kr.
        ll choices = (binaryExponent(2,power,mod2));
        choices%=mod2;
        choices*=val;
        choices%=mod2;
        ans+=(choices);
        ans%=mod2;
        for(ll idx : divisorsOf[index]){
            if(excludedNumbers.count(idx)==0){
                ll temp = (binaryExponent(2,power-1,mod2));
                temp*=val;
                temp%=mod2;
                ans+=temp;
                ans%=mod2;
                power-=1;
                excludedNumbers.insert(idx);
            }
        }
    }
    ans%=mod2;
    cout<<ans<<endl;
}

int main()
{
    FASTIO
    
    {
        solve();
    }
    return 0;
}