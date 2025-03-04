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

ll findBestIndex(vecll& indexes,ll prefixTillNow,vecll& nums){
    ll largest,largestIndex;
    largest = prefixTillNow | nums[indexes[0]];
    largestIndex=0;
    forn(0,indexes.size()){
        ll temp = nums[indexes[i]] | prefixTillNow;
        if(temp>largest){
            largestIndex=i;
            largest=temp;
        }
    }
    return indexes[largestIndex];
}

void solve(){
    ll n;
    cin>>n;
    ll totalOR = 0;
    vecll a(n,0);
    um<ll,vecll> indexWithThisBitSet; //bitIndex : index from a
    ll largestIndex = 0;
    vecll ans;
    forn(0,n){
        ll val;
        cin>>val;
        a[i]=val;
        totalOR = totalOR | val;
        if(val>a[largestIndex]){
            largestIndex=i;
        }
        for(int j=0;j<=32;j++){
            if(1LL<<j & val){
                indexWithThisBitSet[j].pb(i);
            }
        }
    }
    vector<bool> visited(n,false);
    visited[largestIndex]=true;
    ans.pb(a[largestIndex]);
    ll largest = a[largestIndex];
    ll prefixTillNow = largest;
    totalOR ^= largest;
    for(int i=33;i>=0;i--){ //0110
        if(1LL<<i & totalOR){
            ll greedyIndex = findBestIndex(indexWithThisBitSet[i],prefixTillNow,a);
            ll val = a[greedyIndex];
            ans.pb(val);
            visited[greedyIndex]=true;
            prefixTillNow |= val;
            for(int j=0;j<33;j++){
                if((1LL<<j & val) && (1LL<<j & totalOR)){
                    ll mask = 1LL<<j;
                    totalOR ^= mask;
                }
            }
        }
    }
    if(ans.size()<n){
        forn(0,n){
            if(visited[i]==false){
                ans.pb(a[i]);
            }
        }
    }
    forn(0,n){
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