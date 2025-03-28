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

// map<ll,ll> uniqueCount;

vecll uniqueCount(10000002,-1);

void helper(){
    forn(2,10000003){
        ll val = i;
        ll multiple=2;
        while((val*multiple)<=10000003LL){
            if(uniqueCount[i]==-1){
                ll temp=val*multiple;
                uniqueCount[temp] = uniqueCount[temp]==-1 ? 1 : uniqueCount[temp]+1;
            }
            multiple+=1;
        }
    }
}

// ll findPrimeFactorCount(ll n){
//     ll uniqueFactorCount=0;
//     if(uniqueCount[n]!=0) return uniqueCount[n];
//     map<ll,ll> factors;
//     ll multiple=2;
//     while(n>1 && multiple<=(sqrt(n))){
//         if(n%multiple==0){
//             n/=multiple;
//             if(factors[multiple]==0){
//                 uniqueFactorCount+=1;
//                 factors[multiple]=1;
//             }
//         }
//         else{
//             multiple+=1;
//         }
//     }
//     if(multiple!=1 && factors[n]==0) uniqueFactorCount+=1;
//     return uniqueFactorCount;
// }

void solve(){
    ll n;
    ll count=0;
    cin>>n;
    forn(2,n+1){
        ll factors = uniqueCount[i];
        if(factors==-1) factors=1;
        count+=factors;
    }
    cout<<count<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    helper();
    while(t--)
    {
        solve();
    }
    return 0;
}