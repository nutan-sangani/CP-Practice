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

vector<pll> combinations;
vecll fact(17,1);

void findAllCombinations(vecll& fact,int index,ll sum,ll count,int n,vector<pll>& combinations){
    if(index==n){
        combinations.pb(mp(sum,count));
        return;
    }
    findAllCombinations(fact,index+1,sum+fact[index],count+1,n,combinations);
    findAllCombinations(fact,index+1,sum,count,n,combinations);
}

ll findCountOfSetBits(ll n){
    ll count=0;
    while(n>0){
        bool isBitSet = (n & 1LL);
        if(isBitSet) count+=1;
        n/=2;
    }
    return count;
}

void solve(){
    ll n;
    cin>>n;
    ll minOps = LLONG_MAX;
    for(auto combination : combinations){
        ll val = combination.first;
        if(n-val < 0) continue;
        ll ops = findCountOfSetBits(n-val)+combination.second;
        minOps = min<ll>(minOps,ops);
    }
    cout<<minOps<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    forn(1,17){
        fact[i] = i*fact[i-1];
    }
    findAllCombinations(fact,1,0,0,17,combinations);
    while(t--)
    {
        solve();
    }
    return 0;
}