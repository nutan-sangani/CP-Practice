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
    ll n,k;
    cin>>n>>k;
    vecll a(n);
    forn(0,n) cin>>a[i];
    double sum = 0;
    double windowSum = 0;
    forn(0,k) windowSum+=a[i];
    forn(0,n-k+1){
        ll first = a[i];
        ll next = i+k<n ? a[i+k] : 0;
        sum+=windowSum;
        windowSum-=first;
        windowSum+=next;
    }
    double windowCount = n-k+1;
    double avg = (double)sum/(double) windowCount;
    cout<<setiosflags(ios::fixed)<<setprecision(10)<<avg<<endl;
}
//aaj cout stream ke bari me thoda pata chala, ki usme precision kese set krne ka
//iske badle printf from c bhi use krsakte, but ye banane ka koi reason hoga, thus ye banaya h
//uske bari me jaan

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}