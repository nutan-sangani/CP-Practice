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

class SegmentTree{
    vecll seg;
    public:
    SegmentTree(int n){
        seg.resize(4*n);
    }
    void build(vecll& a,int low,int high,int segmentTreeIndex){
        if(low==high){
            seg[segmentTreeIndex]=a[low];
            return;
        }
        ll mid = (low+high)/2;
        build(a,low,mid,2*segmentTreeIndex+1);
        build(a,mid+1,high,2*segmentTreeIndex+2);
        seg[segmentTreeIndex]=min(seg[segmentTreeIndex*2+1],seg[segmentTreeIndex*2+2]);
    }
    ll query(int low,int high,int l,int r,int segmentTreeIndex){
        //no overlap
        //l r low
        //high l r
        if(r<low || l>high) return LLONG_MAX;
        //complete overlap
        //l low high r
        else if(low>=l && high<=r){
            return seg[segmentTreeIndex];
        }
        //partial overlap
        else{
            ll mid = (low+high)/2;
            return min(query(low,mid,l,r,segmentTreeIndex*2+1),query(mid+1,high,l,r,segmentTreeIndex*2+2));
        }
    }
};

void solve(){
    ll n,q;
    cin>>n>>q;
    vecll a(n);
    forn(0,n) cin>>a[i];
    SegmentTree sgt(n);
    sgt.build(a,0,n-1,0);
    while(q--){
        ll l,r;
        cin>>l>>r;
        l-=1;
        r-=1;
        cout<<sgt.query(0,n-1,l,r,0)<<endl;
    }
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}