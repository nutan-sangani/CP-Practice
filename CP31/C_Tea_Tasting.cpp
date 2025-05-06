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

int getLastIndexToGive(ll teaIndex,vecll& prefixSum,ll amount){
    ll prev = teaIndex-1>=0 ? prefixSum[teaIndex-1] : 0;
    ll target = prev+amount;
    auto it = lower_bound(itr(prefixSum),target);
    if(it==prefixSum.end()){
        return prefixSum.size()-1;
    }
    else if(*it==target){
        return it-prefixSum.begin();
    }
    else if(it==prefixSum.begin()){
        return -1;
    }
    else{
        it--;
        return it-prefixSum.begin();
    }
}

void solve(){
    ll n;
    cin>>n;
    vecll a(n);
    forn(0,n){
        cin>>a[i];
    }
    vecll b(n);
    vecll prefixSum(n,0);
    ll sum=0;
    forn(0,n){
        cin>>b[i];
        sum+=b[i];
        prefixSum[i]=sum;
    }
    vecll ans(n,0);
    vecll ps(n,0);
    forn(0,n){
        ll indexTill = getLastIndexToGive(i,prefixSum,a[i]);
        ps[i]+=1;
        ll nextIndex = indexTill+1;
        if(nextIndex<n)
            ps[nextIndex]-=1;
        ll prev = i-1>=0 ? prefixSum[i-1] : 0;
        ll curr = indexTill>=0 ? prefixSum[indexTill] : 0;
        ll rem = a[i] - (curr-prev);
        if(nextIndex<n)
            ans[nextIndex]+=rem;
    }
    sum=0;
    forn(0,n){
        sum+=ps[i];
        ans[i]+=(sum*b[i]);
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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