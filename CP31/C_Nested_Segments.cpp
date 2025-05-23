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
    vector<pll> ranges;
    forn(0,n){
        ll l,r;
        cin>>l>>r;
        ranges.pb(mp(l,r));
    }
    vector<pll> copy(ranges);
    map<ll,ll> leftBoundToIndex;
    sort(itr(ranges),[](pll a,pll b) -> bool {
        if(a.second!=b.second)
            return a.second<b.second;
        return a.first>b.first;
    });
    vector<pll> ans;
    forn(0,n){
        ll currLeftBound = ranges[i].first;
        auto itr = leftBoundToIndex.lower_bound(currLeftBound);
        if(itr!=leftBoundToIndex.end()){
            ans.pb(ranges[(*itr).second]);
            ans.pb(ranges[i]);
            break;
        }
        leftBoundToIndex[currLeftBound]=i;
    }
    ll firstIndex = -1;
    ll lastIndex = -1;
    if(ans.size()>=2){
        forn(0,n){
            if(copy[i].first==ans[0].first && copy[i].second==ans[0].second && firstIndex==-1){
                firstIndex=i+1;
            }
            else if(copy[i].first==ans[1].first && copy[i].second==ans[1].second && lastIndex==-1){
                lastIndex=i+1;
            }
        }
    }
    cout<<firstIndex<<" "<<lastIndex<<endl;
}

int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}