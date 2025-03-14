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

void getAllPrimeFactors(ll n,vecll& factors){
    ll i = 2;
    while(n>1){
        if(n%i==0){
            factors.pb(i);
            n/=i;
        }
        else i+=1;
        ll sqRoot = sqrt(n)+1;
        if(i>sqRoot) break;
    }
    if(n>1){
        factors.pb(n);
    }
}

void solve(){
    ll n;
    cin>>n;
    umll countOf;
    ll primeCount = 0;
    vector<vecll> factors;
    umll primeCountOf;
    vecll vals;
    forn(0,n){
        ll a;
        cin>>a;
        countOf[a]+=1;
        vecll temp;
        getAllPrimeFactors(a,temp);
        factors.pb(temp);
        if(temp.size()==1){
            primeCount+=1;
            primeCountOf[temp[0]]+=1;
        }
        vals.pb(a);
    }
    ll ans=0;
    forn(0,n){
        ll factorCnt = factors[i].size();
        if(factorCnt==1){
            ans+=(primeCount-primeCountOf[vals[i]]);
            primeCount-=1;
            primeCountOf[vals[i]]-=1;
        }
        else if(factorCnt==2){
            ll factor1=factors[i][0],factor2=factors[i][1];
            if(factor1==factor2){
                ans+=countOf[factor1];
                ans+=(countOf[vals[i]]);
                countOf[vals[i]]-=1;
            }
            else{
                ans+=countOf[factor1];
                ans+=countOf[factor2];
                ans+=(countOf[vals[i]]);
                countOf[vals[i]]-=1;
            }
        }
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