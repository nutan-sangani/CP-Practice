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
#define umll unordered_map<ll,ll,custom_hash>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

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

ll insertTower(ll size,multiset<ll>& set){
    if(set.empty()){
        set.insert(size);
        return 1;
    }
    auto up = set.upper_bound(size);
    if(up==set.end()){
        set.insert(size);
        return 1;
    }
    if(*up==size) ++up;
    if(up==set.end()){
        set.insert(size);
        return 1;
    }
    else{
        set.erase(up);
        set.insert(size);
        return 0;
    }
}

void solve(){
    ll n;
    cin>>n;
    multiset<ll> set;
    ll count=0;
    forn(0,n){
        ll size;
        cin>>size;
        count+=insertTower(size,set);
    }
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