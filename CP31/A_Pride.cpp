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
    ll n;
    cin>>n;
    vecll a(n);
    forn(0,n) cin>>a[i];
    ll moves = n-1;
    ll minDistance = LLONG_MAX;
    ll oneCount = 0;
    forn(0,n){
        int l,r;
        l=i-1;
        r=i+1;
        if(a[i]==1){
            oneCount+=1;
        }
        ll gcd1 = a[i];
        while(l>=0 && __gcd(gcd1,a[l])!=1){
            gcd1 = __gcd(gcd1,a[l]);
            l--;
        }
        ll gcd2 = a[i];
        while(r<n && __gcd(gcd2,a[r])!=1){
            gcd2 = __gcd(gcd2,a[r]);
            r++;
        }
        if(l>=0 && __gcd(gcd1,a[l])==1){
            minDistance = min(minDistance,i-l+0LL);
        }
        if(r<n && __gcd(gcd2,a[r])==1){
            minDistance = min(minDistance,0LL+r-i);
        }
    }
    if(minDistance==LLONG_MAX && oneCount==0){
        cout<<-1<<endl;
        return;
    }
    if(oneCount==0) oneCount = -1*n;
    ll minMoves = min(n-oneCount,n-1+minDistance);
    cout<<minMoves<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}