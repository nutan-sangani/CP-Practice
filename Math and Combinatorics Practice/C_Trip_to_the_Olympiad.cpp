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

bool isBitSet(ll l,ll index){
    return (1LL<<index & l)>0;
}

ll setIthBit(ll l,ll i){
    ll after = 1LL<<i;
    return l | after;
}
void solve(){
    ll l,r;
    cin>>l>>r;
    if(r-l==2){
        cout<<l<<" "<<l+1<<" "<<r<<endl;
        return;
    }
    ll a,b,c;
    ll val = 0;
    for(int i=32;i>=0;i--){
        if(isBitSet(l,i) && isBitSet(r,i)){
            val = setIthBit(val,i);
        }
        else if(isBitSet(l,i) || isBitSet(r,i)){
            //r me mostly set rhega ye wala bit
            val = setIthBit(val,i);
            a=val;
            b=val-1;
            if(b==l) c=r;
            else c=l;
            break;
        }
        else{
            continue;
            //ie answer me set mat kr ye bit
        }
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
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