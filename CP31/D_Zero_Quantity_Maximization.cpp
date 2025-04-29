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
    vecll b(n);
    forn(0,n) cin>>a[i];
    ll maxi = 0;
    forn(0,n){
        cin>>b[i];
    }
    map<pll,ll> count;
    ll adder=0;
    forn(0,n){
        if(a[i]==0 && b[i]==0) adder+=1; //any d would work
        if(a[i]==0) continue;
        ll gcd = __gcd(abs(a[i]),abs(b[i]));
        ll newA = a[i]/gcd;
        ll newB = b[i]/gcd;
        if(newA<0 && newB>=0){
            count[mp(newA,abs(newB))]+=1;
        }
        else if(newA>0 && newB<=0){
            count[mp(newA*-1LL,abs(newB))]+=1;
        }
        else
            count[mp(abs(newA),abs(newB))]+=1;
    }
    for(auto entry : count){
        if(entry.second>maxi) maxi = entry.second;
    }
    cout<<maxi+adder<<endl;
}
int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}